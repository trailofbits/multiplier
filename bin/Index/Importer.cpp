// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Importer.h"

#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <system_error>
#include <unordered_map>
#include <vector>
#include <mutex>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <llvm/Support/Format.h>
#include <llvm/Support/FormatVariadic.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>
#include <multiplier/AST.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>

#include "Action.h"
#include "Context.h"
#include "Executor.h"
#include "IndexCompileJob.h"
#include "PASTA.h"
#include "Subprocess.h"

namespace indexer {
namespace {

struct Command {
 public:
  std::string compiler_hash;
  std::string working_dir;
  EnvVariableMap env;
  pasta::ArgumentVector vec;
  pasta::CompilerName name{pasta::CompilerName::kUnknown};
  pasta::TargetLanguage lang{pasta::TargetLanguage::kC};

  Command(const std::string &command)
      : vec(command) {}

  Command(const std::vector<std::string> &args)
      : vec(args) {}
};

struct PathCache {
  std::shared_ptr<pasta::FileSystem> fs;
  std::unordered_map<std::string,
                     std::unordered_map<std::string, std::string>> cache;

  explicit PathCache(const pasta::FileManager &fm)
      : fs(fm.FileSystem()) {}

  std::string *PathOf(std::string exe, const std::string &path,
                      const std::string &cwd) {
    std::unordered_map<std::string, std::string> &path_cache = cache[path];
    auto old_size = path_cache.size();
    std::string &entry = path_cache[exe];

    if (!entry.empty()) {
      return &entry;

    } else if (old_size == path_cache.size()) {
      return nullptr;
    }

    // Try to get the absolute path of the binary if this looks like a file.
    if (exe.starts_with('/') || exe.starts_with('\\') ||
        exe.starts_with('.')) {
      pasta::Result<pasta::Stat, std::error_code> res = fs->Stat(exe, cwd);
      if (res.Succeeded()) {
        entry = res.TakeValue().real_path.generic_string();
        return &entry;
      } else {
        (void) res.TakeError();
      }
    }

    std::stringstream path_ss;
    path_ss << path;

    char sep = ':';
    if (path.find(';') != std::string::npos) {
      sep = ';';
    }

    // Look for the binary in the `PATH` variable.
    for (std::string dir; std::getline(path_ss, dir, sep); dir.clear()) {
      if (dir.empty()) {
        continue;
      }

      std::filesystem::path exe_path(dir);
      exe_path /= exe;
      pasta::Result<pasta::Stat, std::error_code> res = fs->Stat(exe_path, cwd);
      if (res.Succeeded()) {
        entry = res.TakeValue().real_path.generic_string();
        return &entry;
      } else {
        (void) res.TakeError();
      }
    }

    return nullptr;
  }
};

static void FixEnvVariablesAndPath(Command &command, const std::string &cwd,
                                   PathCache &cache) {
  EnvVariableMap &envp = command.env;
  std::vector<std::string> to_remove;
  std::string path;

  for (auto &[key, val] : envp) {
    if (key == "PATH") {
      path = val;

    } else if (key.starts_with("BLIGHT_")) {
      to_remove.push_back(key);
    }
  }

  // Try to get the path of the target executable, and if we succeed, then
  // use it, otherwise drop `_`.
  std::string exe_name_var("_");
  if (auto exe = cache.PathOf(command.vec[0], path, cwd)) {
    envp[exe_name_var] = *exe;

    // Overwrite the first argument in the vector with the fully realized
    // path of the compiler.
    std::vector<std::string> new_vec;
    for (const char *arg : command.vec.Arguments()) {
      new_vec.emplace_back(arg);
    }
    new_vec[0] = *exe;
    command.vec.Reset(new_vec);

  } else {
    envp.erase(exe_name_var);
  }

  // Remove Blight-specific environment variables.
  for (const std::string &k : to_remove) {
    envp.erase(k);
  }

  // Maybe speed up the compiler we're invoking?
  envp["LC_ALL"] = "C";
  envp["LC_COLLATE"] = "C";
  envp["LANG"] = "C";
  envp["CWD"] = cwd;
  envp["PWD"] = cwd;
}

struct CompilerPathInfo {
  std::string sysroot;
  std::string no_sysroot;
};

class CompilerPathInfoCache {
 private:
  const bool enable_cache;

  std::unordered_map<std::string, CompilerPathInfo> cached_info;
  std::mutex cached_info_lock;

 public:
  inline CompilerPathInfoCache(bool enable_cache_)
      : enable_cache(enable_cache_) {}

  std::variant<CompilerPathInfo, std::string> GetCompilerInfo(
      const Command &command);
};

class BuildCommandAction final : public Action {
 private:
  pasta::FileManager &fm;
  const Command &command;
  std::shared_ptr<GlobalIndexingState> ctx;
  CompilerPathInfoCache &cache;

  void RunWithCompiler(pasta::CompileCommand cmd, pasta::Compiler cc);

  static bool CanRunCompileJob(const pasta::CompileJob &job);

 public:
  virtual ~BuildCommandAction(void) = default;

  inline BuildCommandAction(pasta::FileManager &fm_, const Command &command_,
                            std::shared_ptr<GlobalIndexingState> ctx_,
                            CompilerPathInfoCache &cache_)
      : fm(fm_),
        command(command_),
        ctx(std::move(ctx_)),
        cache(cache_) {}

  void Run(void) final;
};

// If we are using something like CMake commands, then pull in the relevant
// information by trying to execute the compiler directly.
std::variant<CompilerPathInfo, std::string>
CompilerPathInfoCache::GetCompilerInfo(const Command &command) {

  std::unique_lock<std::mutex> locker;

  // In caching mode, we check to see if, for the given compiler path, if we've
  // already got compiler info. If so then great, if not then we need to run
  // a command. We'll use the info generated from the first successful command.
  //
  // NOTE(pag): This is technically sketchy, but for some tests, in uniform
  //            codebases, this can significantly speed up the import step for
  //            compile commands.
  if (enable_cache) {
    std::unique_lock<std::mutex>(cached_info_lock).swap(locker);
    if (auto info_it = cached_info.find(command.vec[0]);
        info_it != cached_info.end()) {
      return info_it->second;  // Cache hit.
    }
  }

  std::vector<std::string> new_args;
  bool skip = false;
  for (const char *arg : command.vec) {
    if (skip) {
      skip = false;

      // NOTE(pag): Have observed things like the following in the Linux kernel:
      //
      //      ... -main-file-name -mrelocation-model ...
      //
      if (arg[0] != '-' && 1u < strlen(arg)) {
        continue;
      }
    }

    if (strstr(arg, "-Wno") == arg) {
      // Keep the argument.

    // Drop things like `-Wall`, `-Werror, `-fsanitize=..`, etc.
    } else if (strstr(arg, "-W") == arg ||
               strstr(arg, "-pedantic") == arg ||
               strstr(arg, "-fsanitize") == arg ||
               !strcmp(arg, "-pic-is-pie")) {
      continue;  // Skip the argument.

    } else if (!strcmp(arg, "-mllvm") ||
               !strcmp(arg, "-Xclang") ||
               !strcmp(arg, "-dependency-file") ||
               !strcmp(arg, "-diagnostic-log-file") ||
               !strcmp(arg, "-header-include-file") ||
               !strcmp(arg, "-stack-usage-file") ||
               !strcmp(arg, "-mrelocation-model") ||
               !strcmp(arg, "-pic-level") ||
               !strcmp(arg, "-main-file-name")) {
      skip = true;
      continue;  // Skip the argument and the next argument.

    // If it specifies some file, e.g. `-frandomize-layout-seed-file=...` or
    // `-fprofile-remapping-file=`, or ..., then drop it.
    } else if (strstr(arg, "-file=") /* NOTE(pag): find anywhere */ ||
               strstr(arg, "-dependent-lib=") == arg ||
               strstr(arg, "-stats-file=") == arg ||
               strstr(arg, "-fprofile-list=") == arg ||
               strstr(arg, "-fxray-always-instrument=") == arg ||
               strstr(arg, "-fxray-never-instrument=") == arg ||
               strstr(arg, "-fxray-attr-list=") == arg ||
               strstr(arg, "-treat") == arg) {
      continue;

    // Output file.
    } else if (!strcmp(arg, "-o")) {
      skip = true;
      new_args.emplace_back(arg);
      new_args.emplace_back("/dev/null");
      continue;
    }

    new_args.emplace_back(arg);
  }

  new_args.emplace_back("-w");  // Disable all warnings (GCC).
  new_args.emplace_back("-Wno-everything");  // Disable all warnings (Clang).
  new_args.emplace_back("-P");  // Disable preprocessor line markers.
  new_args.emplace_back("-v");
//  new_args.emplace_back("-dD");  // Print macro definitions in -E mode.
  new_args.emplace_back("-E");  // Only run the preprocessor.

  // Include a non-existent file. This guarantees a fatal error in all cases,
  // which prevents any compilation jobs from proceeding.
  new_args.emplace_back("-include");
  new_args.emplace_back("/trail/of/bits");

  CompilerPathInfo output;
  auto ret = Subprocess::Execute(
      new_args, &(command.env), nullptr /* stdin */, nullptr /* stdout */,
      &output.sysroot);

  if (std::holds_alternative<std::error_code>(ret) && output.sysroot.empty()) {
    return std::get<std::error_code>(ret).message();
  }

  if (auto it = output.sysroot.find("End of search list.");
      it == std::string::npos) {
    if (std::holds_alternative<std::error_code>(ret)) {
      return std::get<std::error_code>(ret).message();
    } else if (it = output.sysroot.find("error: "); it != std::string::npos) {
      while (!output.sysroot.empty() && output.sysroot.back() == '\n') {
        output.sysroot.pop_back();
      }
      return output.sysroot.substr(it + 7);
    } else {
      return "Unknown error: " + output.sysroot;
    }
  }

  new_args.emplace_back("-isysroot");
  new_args.emplace_back(command.working_dir + "/trail_of_bits");
  ret = Subprocess::Execute(
      new_args, &(command.env), nullptr, nullptr, &output.no_sysroot);

  // NOTE(pag): Changing the sysroot might make parts of the compilation fail.
  if (std::holds_alternative<std::error_code>(ret) && output.no_sysroot.empty()) {
    return std::get<std::error_code>(ret).message();
  }

  if (auto it = output.no_sysroot.find("End of search list.");
      it == std::string::npos) {
    if (std::holds_alternative<std::error_code>(ret)) {
      return std::get<std::error_code>(ret).message();
    } else {
      return "Unknown error: " + output.sysroot;
    }
  }

  if (enable_cache) {
    cached_info.emplace(command.vec[0], output);
  }

  return output;
}

bool BuildCommandAction::CanRunCompileJob(const pasta::CompileJob &job) {
  const auto &args = job.Arguments();
  for (auto it = args.begin(); it != args.end(); ++it) {
    const char *arg = *it;
    if (strcmp(arg, "-x")) {
      continue;
    }
    
    // Skip to the value after `-x`.
    ++it;
    if (it == args.end()) {
      break;  // No language specified?
    }
    
    // Next argument after opt_x flag will be lang value; Compare
    // it with the supported language i.e. C.
    arg = *it;
    if (strcmp(arg, "c")) {
      LOG(ERROR) << "Skipping compile job due to unsupported language "
                 << arg << ": " << args.Join();
      return false;
    }
    
    return true;
  }

  // Compile job should have associated opt_x value. Fallback here and return false
  // if the option does not exist.
  LOG(ERROR) << "Skipping compile job due to unknown language: "
             << args.Join();
  return false;
}

void BuildCommandAction::RunWithCompiler(pasta::CompileCommand cmd,
                                         pasta::Compiler cc) {
  auto maybe_jobs = cc.CreateJobsForCommand(cmd);
  if (!maybe_jobs.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile jobs: " << maybe_jobs.TakeError();
    return;
  }

  // The build command action adds these jobs to the indexing executor, which
  // is different than `exe`, because `exe` operates (and waits), for things
  // to finish with the current working directory changed.
  unsigned num_jobs = 0u;
  for (pasta::CompileJob job : maybe_jobs.TakeValue()) {
    ++num_jobs;

    if (!CanRunCompileJob(job)) {
      DLOG(WARNING)
          << "Skipping job: " << job.Arguments().Join();
      continue;
    }

    DLOG(INFO)
        << "Creating indexing action for main source file "
        << job.SourceFile().Path().generic_string();

    ctx->executor.EmplaceAction<IndexCompileJobAction>(ctx, fm, job);
  }

  LOG_IF(ERROR, !num_jobs)
      << "Didn't create any compiler jobs for command "
      << cmd.Arguments().Join();
}

// Build the compilers for the commands, then build the commands.
void BuildCommandAction::Run(void) {

  pasta::Result<pasta::CompileCommand, std::string_view> maybe_cmd =
      pasta::CompileCommand::CreateFromArguments(
          command.vec, command.working_dir);
  if (!maybe_cmd.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile command: " << maybe_cmd.TakeError();
    return;
  }

  auto maybe_cc_info = cache.GetCompilerInfo(command);
  if (!std::holds_alternative<CompilerPathInfo>(maybe_cc_info)) {
    LOG(ERROR)
        << "Error invoking original compiler to find version information: "
        << std::get<std::string>(maybe_cc_info) << "; original command was: "
        << command.vec.Join();
    return;
  }

  CompilerPathInfo &cc_info = std::get<CompilerPathInfo>(maybe_cc_info);

  pasta::Result<pasta::Compiler, std::string> maybe_cc =
      pasta::Compiler::Create(fm, command.vec[0], command.working_dir,
                              command.name, command.lang, cc_info.sysroot,
                              cc_info.no_sysroot);

  if (maybe_cc.Succeeded()) {
    RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue());
    return;
  }

  LOG(ERROR)
      << "Unable to create command-specific compiler: " << maybe_cc.TakeError()
      << "; falling back to host compiler for command " << command.vec.Join();

  maybe_cc = pasta::Compiler::CreateHostCompiler(fm, command.lang);
  if (maybe_cc.Succeeded()) {
    RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue());
    return;
  }

  LOG(ERROR)
      << "Unable to create host compiler " << maybe_cc.TakeError()
      << " for command " << command.vec.Join();
}

}  // namespace

struct Importer::PrivateData {
 public:
  // Commands, grouped by working directory.
  std::unordered_map<std::string, std::vector<Command>> commands;

  std::filesystem::path cwd;
  pasta::FileManager fm;
  std::shared_ptr<GlobalIndexingState> ctx;

  inline PrivateData(std::filesystem::path cwd_,
                     const pasta::FileManager &fm_,
                     std::shared_ptr<GlobalIndexingState> ctx_)
      : cwd(std::move(cwd_)),
        fm(fm_),
        ctx(std::move(ctx_)) {}
};

Importer::~Importer(void) {}

Importer::Importer(std::filesystem::path cwd_,
                   const pasta::FileManager &fm,
                   std::shared_ptr<GlobalIndexingState> ctx)
    : d(std::make_unique<Importer::PrivateData>(
            std::move(cwd_), fm, std::move(ctx))) {}

bool Importer::ImportBlightCompileCommand(llvm::json::Object &o) {

  auto wrapped_tool = o.getString("wrapped_tool");
  auto cwd = o.getString("cwd");
  auto args = o.getArray("args");
  auto hash = o.getString("hash");
  auto lang = o.getString("lang");  // `C`, `Cxx`, `Unknown`.
  auto env = o.getObject("env");

  if (!wrapped_tool || !cwd || !args || args->empty() || !hash || !lang ||
      !env) {
    return false;
  }

  std::vector<std::string> args_vec;
  args_vec.emplace_back(wrapped_tool->str());

  for (auto arg : *args) {
    if (auto arg_str = arg.getAsString()) {
      args_vec.emplace_back(arg_str->str());
    } else {
      return false;
    }
  }

  EnvVariableMap envp;
  for (const auto &it : *env) {
    const llvm::json::ObjectKey &key = it.first;
    const llvm::json::Value &val = it.second;
    if (auto val_str = val.getAsString()) {
      envp.emplace(key.str(), val_str->str());
    } else {
      return false;
    }
  }

  auto cwd_str = cwd->str();
  if (cwd_str.empty()) {
    cwd_str = d->cwd.generic_string();
  }

  auto &command = d->commands[cwd_str].emplace_back(args_vec);
  command.working_dir = cwd_str;
  command.compiler_hash = hash->str();
  command.env = std::move(envp);
  if (lang->equals_insensitive("c++") || lang->equals_insensitive("cxx")) {
    command.lang = pasta::TargetLanguage::kCXX;
  }
  return true;
}

bool Importer::ImportCMakeCompileCommand(llvm::json::Object &o,
                                         const EnvVariableMap &envp) {
  auto cwd = o.getString("directory");
  auto file = o.getString("file");
  if (!cwd || !file) {
    DLOG(WARNING) << "No 'file' and/or 'directory' in JSON object";
    return false;
  }

  auto cwd_str = cwd->str();
  if (cwd_str.empty()) {
    cwd_str = d->cwd.generic_string();
  }

  auto &commands = d->commands[cwd_str];

  PathCache cache(d->fm);

  // E.g. from CMake, Blight.
  if (auto commands_str = o.getString("command")) {
    std::string args_str = commands_str->str();
    Command &command = commands.emplace_back(args_str);
    if (command.vec.Size()) {
      command.compiler_hash = std::move(args_str);
      command.working_dir = cwd_str;
      command.env = envp;
      FixEnvVariablesAndPath(command, cwd_str, cache);

      // Log after so that we can show the absolute path to the compiler if
      // it was updated by `FixEnvVariablesAndPath`.
      DLOG(INFO) << "Parsed command: " << command.vec.Join();

      // Guess at the language.
      if (commands_str->contains_insensitive("++") ||
          commands_str->contains_insensitive(".cc") ||
          commands_str->contains_insensitive(".cxx") ||
          commands_str->contains_insensitive(".cpp") ||
          commands_str->contains_insensitive(".hxx") ||
          commands_str->contains_insensitive(".hpp")) {
        command.lang = pasta::TargetLanguage::kCXX;
      }

      return true;

    } else {
      DLOG(ERROR) << "Can't parse arguments from JSON object";
      commands.pop_back();
      return false;
    }

  // E.g. from Bear (Build ear).
  } else if (auto arguments_list = o.getArray("arguments");
             arguments_list && !arguments_list->empty()) {

    auto lang = pasta::TargetLanguage::kC;
    std::stringstream ss;

    std::vector<std::string> args_vec;
    for (auto arg : *arguments_list) {
      if (auto arg_str = arg.getAsString()) {
        // Guess at the language.
        if (arg_str->contains_insensitive("++") ||
            arg_str->contains_insensitive(".cc") ||
            arg_str->contains_insensitive(".cxx") ||
            arg_str->contains_insensitive(".cpp") ||
            arg_str->contains_insensitive(".hxx") ||
            arg_str->contains_insensitive(".hpp")) {
          lang = pasta::TargetLanguage::kCXX;
        }
        auto str = arg_str->str();
        ss << ' ' << str;
        args_vec.emplace_back(std::move(str));
      } else {
        return false;
      }
    }

    auto &command = commands.emplace_back(args_vec);
    if (command.vec.Size()) {
      DLOG(INFO) << "Parsed command: " << command.vec.Join();
      command.compiler_hash = ss.str();
      command.working_dir = cwd_str;
      command.env = envp;
      FixEnvVariablesAndPath(command, cwd_str, cache);
      command.lang = lang;
      return true;

    } else {
      DLOG(ERROR) << "Can't parse arguments from JSON object";
      commands.pop_back();
      return false;
    }

  } else {
    DLOG(ERROR) << "Can't locate compiler arguments in JSON object";
    return false;
  }
}

namespace {
static std::mutex gImportLock;
}  // namespace

void Importer::Import(const ExecutorOptions &options, bool fast_import) {
  Executor per_path_exe(options);

  for (auto &[cwd, commands] : d->commands) {
    CompilerPathInfoCache cc_info_cache(fast_import);

    // Make sure that even concurrent calls to `Import` never concurrently
    // change the current working directory.
    std::unique_lock<std::mutex> locker(gImportLock);

    // Change the current working directory to match that of the commands.
    // This is a process-wide operation.
    std::error_code ec;
    std::filesystem::current_path(cwd, ec);
    if (ec) {
      LOG(ERROR)
          << "Could not change current working directory to " << cwd
          << ": " << ec.message();
      continue;
    }

    for (const Command &cmd : commands) {
      per_path_exe.EmplaceAction<BuildCommandAction>(d->fm, cmd, d->ctx,
                                                     cc_info_cache);
    }

    per_path_exe.Start();
    per_path_exe.Wait();
  }
}

}  // namespace indexer
