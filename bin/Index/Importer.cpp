// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Importer.h"

#include <algorithm>
#include <cctype>
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
#include <multiplier/AST.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/Support/Format.h>
#include <llvm/Support/FormatVariadic.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include "Action.h"
#include "Context.h"
#include "Executor.h"
#include "IndexCompileJob.h"
#include "PASTA.h"
#include "Subprocess.h"

namespace indexer {
namespace {

static const std::string_view kLanguage = "--language";
static const std::string_view kLanguageEQ = "--language=";
static const std::string_view kLanguageX = "-x";

static std::string ToLower(std::string_view view) {
  std::string data(view);
  std::transform(data.begin(), data.end(), data.begin(),
                 [](unsigned char c){ return std::tolower(c); });
  return data;
}

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

static void FixEnvVariablesAndPath(Command &command, PathCache *cache) {
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
  if (cache && envp.count(exe_name_var)) {
    std::vector<std::string> new_vec;
    if (auto exe = cache->PathOf(command.vec[0], path, command.working_dir)) {
      envp[exe_name_var] = *exe;

      // Overwrite the first argument in the vector with the fully realized
      // path of the compiler.
      for (const char *arg : command.vec.Arguments()) {
        new_vec.emplace_back(arg);
      }
      new_vec[0] = *exe;
      command.vec.Reset(new_vec);

    } else {
      envp.erase(exe_name_var);
    }
  }

  // Remove Blight-specific environment variables.
  for (const std::string &k : to_remove) {
    envp.erase(k);
  }

  // Maybe speed up the compiler we're invoking?
  envp["LC_ALL"] = "C";
  envp["LC_COLLATE"] = "C";
  envp["LANG"] = "C";
  envp["CWD"] = command.working_dir;
  envp["PWD"] = command.working_dir;
  envp["NO_COLOR"] = "1";

  envp.erase("TERM");
  envp.erase("CLICOLOR");
  envp.erase("CLICOLOR_FORCE");
}

struct CompilerPathInfo {
  std::string sysroot;
  std::string no_sysroot;
};

class BuildCommandAction final : public Action {
 private:
  pasta::FileManager &fm;
  std::shared_ptr<pasta::FileSystem> fs;
  const Command &command;
  GlobalIndexingState &ctx;
  const bool cxx_support;

  void RunWithCompiler(pasta::CompileCommand cmd, pasta::Compiler cc);

  bool CanRunCompileJob(const pasta::CompileJob &job) const;

  std::variant<CompilerPathInfo, std::string> GetCompilerInfo(void);

 public:
  virtual ~BuildCommandAction(void) = default;

  inline BuildCommandAction(pasta::FileManager &fm_, const Command &command_,
                            GlobalIndexingState &ctx_,
                            bool cxx_support_)
      : fm(fm_),
        fs(fm.FileSystem()),
        command(command_),
        ctx(ctx_),
        cxx_support(cxx_support_) {}

  void Run(void) final;
};

// If we are using something like CMake commands, then pull in the relevant
// information by trying to execute the compiler directly.
std::variant<CompilerPathInfo, std::string>
BuildCommandAction::GetCompilerInfo(void) {
  std::vector<std::string> new_args;
  bool skip = false;
  bool skip_internal_option = false;
  bool has_output = false;
  auto inferred_lang = "c";
  bool specifies_language = false;
  for (const char *arg_ : command.vec) {

    std::string_view arg(arg_);

    // Try to detect C++ code.
    if (!specifies_language && cxx_support) {
      if (arg.find("++") != std::string_view::npos) {
        inferred_lang = "c++";

      } else if (arg.find('.') != std::string_view::npos) {
        std::string arg_str = ToLower(arg);
        if (arg_str.ends_with(".cc") ||
            arg_str.ends_with(".cpp") ||
            arg_str.ends_with(".cxx") ||
            arg_str.ends_with(".hh") ||
            arg_str.ends_with(".hpp")) {
          inferred_lang = "c++";

        } else if (arg_str.ends_with(".c")) {
          inferred_lang = "c";

        } else if (arg_str.ends_with(".s")) {
          inferred_lang = "asm";
        }
      }
    }

    if (skip_internal_option) {
      skip_internal_option = false;
      continue;
    }

    if (skip) {
      skip = false;

      // NOTE(pag): Have observed things like the following in the Linux kernel:
      //
      //      ... -main-file-name -mrelocation-model ...
      //
      if (arg.front() != '-' && 1u < arg.size()) {
        continue;
      }
    }

    // Drop things like `-Wall`, `-Werror, `-fsanitize=..`, etc.
    if (arg.starts_with("-W") ||
        arg.starts_with("-pedantic") ||
        arg.starts_with("-ftrivial-auto-var-init=") ||
        arg.starts_with("-fpatchable-function-entry=") ||
        arg.starts_with("-fpatchable-function-entry-offset=") ||
        arg.starts_with("-fstrict-flex-arrays=") ||
        arg.starts_with("-mfunction-return=") ||
        arg.starts_with("-fsanitize=") ||
        arg.starts_with("-fcoverage-compilation-dir=") ||
        arg == "-pic-is-pie" ||
        arg == "-mindirect-branch-cs-prefix" ||
        arg == "-Wno-cast-function-type-strict" ||
        arg == "-Wno-c++11-narrowing-const-reference" ||
        arg == "-Wno-thread-safety-reference-return") {
      continue;  // Skip the argument.

    // Keep the argument.
    } else if (arg.starts_with("-Wno-")) {

    // Drop these, and the following argument.
    } else if (arg == "-Xclang" || arg == "-mllvm") {
      skip_internal_option = true;
      continue;

    // Drop these, and the following argument.
    } else if (arg == "-dependency-file" ||
               arg == "-diagnostic-log-file" ||
               arg == "-header-include-file" ||
               arg == "-stack-usage-file" ||
               arg == "-mrelocation-model" ||
               arg == "-pic-level" ||
               arg == "-main-file-name" ||
               arg == "-MT" ||
               arg == "-MQ") {
      skip = true;
      continue;

    // If it specifies some file, e.g. `-frandomize-layout-seed-file=...` or
    // `-fprofile-remapping-file=`, or ..., then drop it.
    } else if (strstr(arg_, "-file=") /* NOTE(pag): find anywhere */ ||
               arg.starts_with("-dependent-lib=") ||
               arg.starts_with("-stats-file=") ||
               arg.starts_with("-fprofile-list=") ||
               arg.starts_with("-fxray-always-instrument=") ||
               arg.starts_with("-fxray-never-instrument=") ||
               arg.starts_with("-fxray-attr-list=") ||
               arg.starts_with("-tsan-compound-read-before-write=") ||
               arg.starts_with("-tsan-distinguish-volatile=") ||
               arg.starts_with("-treat") ||
               arg.starts_with("-split-threshold-for-reg-with-hint=") ||
               arg.starts_with("-instcombine-lower-dbg-declare=")) {
      continue;

    // Output file, `-o <file>`, `--output <arg>`.
    } else if (arg == "-o" || arg == "--output") {
      has_output = true;
      skip = true;
      continue;

    // `--output=<arg>`
    } else if (arg.starts_with("--output=")) {
      has_output = true;
      continue;

    // `-o<file>`, or maybe another option like `-object-file-name=...`.
    } else if (arg.starts_with("-o") &&
               !arg.starts_with("-output") &&
               !arg.starts_with("-obj") &&
               arg.find('=') == std::string_view::npos) {
      has_output = true;
      continue;

    // Turns on the x87 FPU.
    } else if (arg == "-x87") {

    // `-x c`, `-xc`, `--language c`, `--language=c`, etc.
    } else if (arg == kLanguageX || arg == kLanguage ||
               arg.starts_with(kLanguageX) ||
               arg.starts_with(kLanguageEQ)) {
      specifies_language = true;

    // Something like `"-DFOO=bar"` or `'-DFOO=bar'`.
    } else if ((arg.front() == '\'' || arg.front() == '"') && arg[1] == '-' &&
               arg.back() == arg.front()) {
      continue;
    }

    new_args.emplace_back(arg_);
  }

  new_args.emplace_back("-w");  // Disable all warnings (GCC).
  new_args.emplace_back("-Wno-everything");  // Disable all warnings (Clang).
  new_args.emplace_back("-P");  // Disable preprocessor line markers.
  new_args.emplace_back("-v");

  if (!specifies_language) {
    new_args.push_back("-x");
    new_args.push_back(inferred_lang);   
  }

  // Include a non-existent file. This guarantees a fatal error in all cases,
  // which prevents any compilation jobs from proceeding.
  new_args.emplace_back("-include");
  new_args.emplace_back("/trail/of/bits");

  if (has_output) {
    new_args.emplace_back("-o");
    new_args.emplace_back("/dev/null");
  }

  // Probably not needed, but if the first argument looks like a relative path
  // then convert it to an absolute path.
  if (new_args.front().starts_with("./") ||
      new_args.front().starts_with("../")) {
    auto res = fs->ParsePath(new_args.front(), command.working_dir,
                             pasta::PathKind::kUnix);
    new_args.front() = res.generic_string();
  }

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
  if (std::holds_alternative<std::error_code>(ret) &&
      output.no_sysroot.empty()) {
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

  return output;
}

bool BuildCommandAction::CanRunCompileJob(const pasta::CompileJob &job) const {

  const auto &args = job.Arguments();
  for (auto it = args.begin(); it != args.end(); ++it) {
    std::string_view arg = *it;
    
    // `-x c`, `-x c++`, `--language c`, `--language c++`, etc.
    if (arg == kLanguageX || arg == kLanguage) {
      // Skip to the value after `-x`.
      ++it;
      if (it == args.end()) {
        break;  // No language specified?
      }
      
      // Next argument after opt_x flag will be lang value; Compare
      // it with the supported language i.e. C.
      arg = *it;

    // `--language=c`, `--language=c++`, etc.
    } else if (arg.starts_with(kLanguageEQ)) {
      arg = arg.substr(kLanguageEQ.size());

    // `-xc`, `-xc++`, etc.
    } else if (arg.starts_with(kLanguageX) && arg != "-x87") {
      arg = arg.substr(kLanguageX.size());

    // Skip.
    } else {
      continue;
    }

    if (arg == "c" || arg == "c-header" ||
        (cxx_support && (arg == "c++" || arg == "c++-header"))) {

    } else {
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

namespace {

static const std::string_view kOptNoStdInc("-nostdinc");
static const std::string_view kOptNoStdIncxx("-nostdinc++");
static const std::string_view kOptNoBuiltinInc("-nobuiltininc");
static const std::string_view kOptNoStdSystemInc("-nostdsysteminc");

static bool IsOptNeedingFixing(std::string_view arg) {
  return arg == kOptNoStdInc || arg == kOptNoStdIncxx ||
         arg == kOptNoBuiltinInc || arg == kOptNoStdSystemInc ||
         arg.starts_with("-fsanitize=");
}

// The way we do system include directory inference with the compiler means
// that we will learn what the new include dirs are. But, we use the configured
// compiler to go and form the jobs, and that process will use the detection of
// these flags to figure out if it should include the system include dirs or
// not. Therefore, if a command includes these flags which say "don't use the
// system include dirs", then we actually want to eliminate these flags, because
// we have learned the "new" system include dirs from the config, and thus want
// to use them.
static bool NeedsFixing(const pasta::ArgumentVector &argv) {
  for (auto arg : argv) {
    if (IsOptNeedingFixing(arg)) {
      return true;
    }
  }
  return false;
}

// Produce a "fixed" command that strips options that tell PASTA to ingore
// the system includes configured into the `pasta::Compiler`, which were
// themselves derived from `orig_command` and thus should be trusted.
static std::optional<pasta::CompileCommand> FixedCommand(
    const pasta::CompileCommand &orig_command) {
  std::vector<std::string> args;
  for (auto arg : orig_command.Arguments()) {
    if (!IsOptNeedingFixing(arg)) {
      args.emplace_back(arg);
    }
  }

  pasta::ArgumentVector argv(args);
  pasta::Result<pasta::CompileCommand, std::string_view> maybe_cmd =
      pasta::CompileCommand::CreateFromArguments(
          argv, orig_command.WorkingDirectory());

  if (!maybe_cmd.Succeeded()) {
    return std::nullopt;
  }

  return maybe_cmd.TakeValue();
}

}  // namespace

void BuildCommandAction::RunWithCompiler(pasta::CompileCommand cmd,
                                         pasta::Compiler cc) {
  std::optional<pasta::CompileCommand> fixed_cmd;
  if (NeedsFixing(cmd.Arguments())) {
    fixed_cmd = FixedCommand(cmd);
  }

  auto maybe_jobs = cc.CreateJobsForCommand(fixed_cmd ? *fixed_cmd : cmd);
  if (!maybe_jobs.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile jobs: " << maybe_jobs.TakeError()
        << "; command was: " << cmd.Arguments().Join();
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

    ctx.executor.EmplaceAction<IndexCompileJobAction>(ctx, fm, cc, job);
  }

  LOG_IF(ERROR, !num_jobs)
      << "Didn't create any compiler jobs for command "
      << cmd.Arguments().Join();
}

// Build the compilers for the commands, then build the commands.
void BuildCommandAction::Run(void) {

  ProgressBarWork progress_tracker(ctx.eval_command_progress);

  pasta::Result<pasta::CompileCommand, std::string_view> maybe_cmd =
      pasta::CompileCommand::CreateFromArguments(
          command.vec, command.working_dir);
  if (!maybe_cmd.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile command: " << maybe_cmd.TakeError();
    return;
  }

  auto maybe_cc_info = GetCompilerInfo();
  if (!std::holds_alternative<CompilerPathInfo>(maybe_cc_info)) {
    LOG(ERROR)
        << "Error invoking original compiler to find version information: "
        << std::get<std::string>(maybe_cc_info) << "; original command was: "
        << command.vec.Join()
        << ". Perhaps try --env /path/to/file to specify a file containing "
           "environment variables, to help me find the compiler executable";
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
      << "; skipping command " << command.vec.Join();

  // NOTE(pag): We don't fall back on `pasta::Compiler::CreateHostCompiler`
  //            because that is based on the host compiler used to compile
  //            PASTA itself, which may be on a totally different machine.
}

}  // namespace

struct Importer::PrivateData {
 public:
  // Commands, grouped by working directory.
  std::unordered_map<std::string, std::vector<Command>> commands;

  std::filesystem::path cwd;
  pasta::FileManager fm;
  GlobalIndexingState &ctx;

  inline PrivateData(std::filesystem::path cwd_,
                     const pasta::FileManager &fm_,
                     GlobalIndexingState &ctx_)
      : cwd(std::move(cwd_)),
        fm(fm_),
        ctx(ctx_) {}
};

Importer::~Importer(void) {}

Importer::Importer(std::filesystem::path cwd_,
                   const pasta::FileManager &fm,
                   GlobalIndexingState &ctx)
    : d(std::make_unique<Importer::PrivateData>(
            std::move(cwd_), fm, ctx)) {}

bool Importer::ImportBlightCompileCommand(llvm::json::Object &o) {
  ProgressBarWork progress_tracker(d->ctx.command_progress);
  auto wrapped_tool = o.getString("wrapped_tool");
  auto cwd = o.getString("cwd");
  auto args = o.getArray("canonicalized_args");
  auto lang = o.getString("lang");  // `C`, `Cxx`, `Unknown`.
  auto env = o.getObject("env");

  if (!args) {
    args = o.getArray("args");
  }

  if (!wrapped_tool || !cwd || !args || args->empty() || !env) {
    return false;
  }

  std::vector<std::string> args_vec;
  args_vec.emplace_back(wrapped_tool->str());

  auto bundle = false;

  for (llvm::json::Value &arg : *args) {
    if (auto arg_str = arg.getAsString()) {
      if (arg_str->equals("-bundle")) {
        bundle = true;
      }
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

  Command &command = d->commands[cwd_str].emplace_back(args_vec);
  command.working_dir = cwd_str;
  command.env = std::move(envp);

  if (bundle) {
    LOG(WARNING)
        << "Skipping bundle command: "
        << command.vec.Join();
    d->commands[cwd_str].pop_back();
    return true;  // Not an error.
  }

  if (!lang || lang->equals_insensitive("unknown")) {
    LOG(WARNING)
        << "Skipping command with unknown language: "
        << command.vec.Join();
    d->commands[cwd_str].pop_back();
    return true;
  }

  if (lang->equals_insensitive("c++") || lang->equals_insensitive("cxx")) {
    command.lang = pasta::TargetLanguage::kCXX;
  }

  // Compiler hash.
  if (auto hash = o.getString("hash")) {
    command.compiler_hash = hash->str();

  } else {
    command.compiler_hash = command.vec.Join();
  }

  FixEnvVariablesAndPath(command, nullptr);

  return true;
}

bool Importer::ImportCMakeCompileCommand(llvm::json::Object &o,
                                         const EnvVariableMap &envp) {

  ProgressBarWork progress_tracker(d->ctx.command_progress);

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

  auto commands_str = o.getString("command");
  auto arguments_list = o.getArray("arguments");
  auto bundle = false;

  // Blight.
  if (!arguments_list) {
    arguments_list = o.getArray("canonicalized_args");
    if (!arguments_list) {
      arguments_list = o.getArray("args");
    }
  }

  Command *command = nullptr;

  // E.g. from CMake, Blight.
  if (commands_str) {
    std::string args_str = commands_str->str();
    command = &(commands.emplace_back(args_str));
    if (!command->vec.Size()) {
      DLOG(ERROR) << "Can't parse arguments from JSON object";
      commands.pop_back();
      return false;
    }

  // E.g. from Bear (Build ear).
  } else if (arguments_list && !arguments_list->empty()) {

    std::vector<std::string> args_vec;
    for (auto arg : *arguments_list) {
      if (auto arg_str = arg.getAsString()) {
        if (arg_str->equals("-bundle")) {
          bundle = true;
        }
        args_vec.emplace_back(arg_str->str());
      } else {
        return false;
      }
    }

    command = &(commands.emplace_back(args_vec));
    if (!command->vec.Size()) {
      DLOG(ERROR) << "Can't parse arguments from JSON object";
      commands.pop_back();
      return false;
    }

    if (bundle) {
      LOG(WARNING)
          << "Skipping bundle command: "
          << command->vec.Join();
      commands.pop_back();
      return true;  // Not an error.
    }

  } else {
    DLOG(ERROR) << "Can't locate compiler arguments in JSON object";
    return false;
  }

  command->compiler_hash = command->vec.Join();
  command->working_dir = cwd_str;
  command->env = envp;
  command->lang = pasta::TargetLanguage::kC;

  for (const char *arg : command->vec.Arguments()) {
    llvm::StringRef arg_view(arg);
    if (arg_view.contains_insensitive("++") ||
        arg_view.contains_insensitive(".cc") ||
        arg_view.contains_insensitive(".cxx") ||
        arg_view.contains_insensitive(".cpp") ||
        arg_view.contains_insensitive(".hxx") ||
        arg_view.contains_insensitive(".hpp")) {
      command->lang = pasta::TargetLanguage::kCXX;
      break;
    }
  }

  FixEnvVariablesAndPath(*command, &cache);

  // Log after so that we can show the absolute path to the compiler if
  // it was updated by `FixEnvVariablesAndPath`.
  DLOG(INFO) << "Parsed command: " << command->compiler_hash;
  
  return true;
}

namespace {
static std::mutex gImportLock;
}  // namespace

void Importer::Import(const ExecutorOptions &options, bool cxx_support) {
  Executor per_path_exe(options);

  for (auto &[cwd, commands] : d->commands) {

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
                                                     cxx_support);
    }

    per_path_exe.Start();
    per_path_exe.Wait();
  }
}

}  // namespace indexer
