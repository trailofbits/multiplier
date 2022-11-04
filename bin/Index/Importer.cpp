// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Importer.h"

#include <cstring>
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
#include <multiplier/Action.h>
#include <multiplier/AST.h>
#include <multiplier/Executor.h>
#include <multiplier/PASTA.h>
#include <multiplier/Result.h>
#include <multiplier/Subprocess.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>

#include "IndexCompileJob.h"

namespace indexer {
namespace {

static std::mutex gCompileJobListLock;

// static constexpr size_t kCommandsBatchSize = 256;

using CompileJobList = std::vector<std::pair<pasta::Compiler, pasta::CompileJob>>;

static inline void
FixEnvVariables(EnvVariableMap &envp, std::string &path) {
  for (const auto &[key, _]: envp) {
    if (key == "PWD" || key == "CWD") {
      envp[key] = path;
    }
  }
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

class BuildCommandAction final : public mx::Action {
 private:
  pasta::FileManager &fm;
  const Command &command;
  std::shared_ptr<IndexingContext> ctx;

  // If we are using something like CMake commands, then pull in the relevant
  // information by trying to execute the compiler directly.
  mx::Result<std::pair<std::string, std::string>, std::error_code>
  InitCompilerFromCommand(void);

  void RunWithCompiler(pasta::CompileCommand cmd, pasta::Compiler cc,
                       mx::Executor &exe);

  bool CanRunCompileJob(pasta::CompileJob &job);

 public:
  virtual ~BuildCommandAction(void) = default;

  inline BuildCommandAction(pasta::FileManager &fm_, const Command &command_,
                            std::shared_ptr<IndexingContext> ctx)
      : fm(fm_),
        command(command_),
        ctx(ctx) {}

  void Run(mx::Executor exe, mx::WorkerId) final;
};

// If we are using something like CMake commands, then pull in the relevant
// information by trying to execute the compiler directly.
mx::Result<std::pair<std::string, std::string>, std::error_code>
BuildCommandAction::InitCompilerFromCommand(void) {
  std::vector<std::string> new_args;
  for (auto arg : command.vec) {
    new_args.emplace_back(arg);
  }
  new_args.emplace_back("-Wno-missing-sysroot");
  new_args.emplace_back("-Wno-unknown-warning-option");
  new_args.emplace_back("-P");
  new_args.emplace_back("-v");
  new_args.emplace_back("-dD");

  std::string output_sysroot;
  auto ret = mx::Subprocess::Execute(
      new_args, &(command.env), nullptr, nullptr, &output_sysroot);
  if (!ret.Succeeded()) {
    return ret.TakeError();
  }

  if (auto it = output_sysroot.find("error: "); it != std::string::npos) {
    LOG(ERROR) << output_sysroot.substr(it + 7u);
    return std::make_error_code(std::errc::bad_message);
  }

  std::string output_no_sysroot;
  new_args.emplace_back("-isysroot");
  new_args.emplace_back(command.working_dir + "/xyz");
  auto ret2 = mx::Subprocess::Execute(
      new_args, &(command.env), nullptr, nullptr, &output_no_sysroot);

  // NOTE(pag): Changing the sysroot might make parts of the compilation fail.
  if (!ret2.Succeeded() && output_no_sysroot.empty()) {
    return ret2.TakeError();
  }

  return std::make_pair(output_sysroot, output_no_sysroot);
}

bool BuildCommandAction::CanRunCompileJob(pasta::CompileJob &job) {
  static const std::string lang_opt = "-x";
  static const char *lang_c = "c";
  auto args = job.Arguments();
  for (auto it = args.begin(); it != args.end(); ++it) {
    if (lang_opt == *it) {
      // Next argument after opt_x flag will be lang value; Compare
      // it with the supported language i.e. C
      auto lang_value = *(it + 1);
      auto is_c = !strcmp(lang_value, lang_c);
      if (!is_c) {
        LOG(ERROR) << "Failed to Index compile job due to unsupported lang opt "
                   << lang_value << " ! " << job.Arguments().Join();
      }
      return is_c;
    }
  }

  // Compile job should have associated opt_x value. Fallback here and return false
  // if the option does not exist.
  LOG(ERROR) << "Failed to Index compile job due to missing lang opt! "
             << job.Arguments().Join();
  return false;
}

void BuildCommandAction::RunWithCompiler(pasta::CompileCommand cmd,
                                         pasta::Compiler cc,
                                         mx::Executor &exe) {
  auto maybe_jobs = cc.CreateJobsForCommand(cmd);
  if (!maybe_jobs.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile jobs: " << maybe_jobs.TakeError();
    return;
  }

  // The build command action adds these jobs to the indexing executor, which
  // is different than `exe`, because `exe` operates (and waits), for things
  // to finish with the current working directory changed.
  for (pasta::CompileJob job : maybe_jobs.TakeValue()) {
    if (!CanRunCompileJob(job)) {
      continue;
    }
    ctx->executor.EmplaceAction<IndexCompileJobAction>(ctx, fm, job);
  }
  (void)exe;
}

// Build the compilers for the commands, then build the commands.
void BuildCommandAction::Run(mx::Executor exe, mx::WorkerId) {

  pasta::Result<pasta::CompileCommand, std::string_view> maybe_cmd =
      pasta::CompileCommand::CreateFromArguments(
          command.vec, command.working_dir);
  if (!maybe_cmd.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile command: " << maybe_cmd.TakeError();
    return;
  }

  auto cc_info = InitCompilerFromCommand();
  if (!cc_info.Succeeded()) {
    LOG(ERROR)
        << "Error invoking original compiler to find version information: "
        << cc_info.TakeError().message();
    return;
  }

  auto [cc_version_sysroot, cc_version_no_sysroot] = cc_info.TakeValue();

  pasta::Result<pasta::Compiler, std::string> maybe_cc =
      pasta::Compiler::Create(fm, command.vec[0], command.working_dir,
                              command.name, command.lang, cc_version_sysroot,
                              cc_version_no_sysroot);

  if (!maybe_cc.Succeeded()) {
    auto error = maybe_cc.TakeError();
    maybe_cc = pasta::Compiler::CreateHostCompiler(fm, command.lang);
    if (maybe_cc.Succeeded()) {
      RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue(),
                      exe);
    } else {
      LOG(ERROR)
          << "Unable to create compiler: " << error;
    }
  } else {
    RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue(),
                    exe);
  }
}

//llvm::json::Value v(std::move(o));
//std::string s;
//llvm::raw_string_ostream os(s);
//os << llvm::formatv("{0:2}", v);
//os.flush();
//std::cerr << s << std::endl;
//return true;

}  // namespace

struct Importer::PrivateData {
 public:
  // Commands, grouped by working directory.
  std::unordered_map<std::string, std::vector<Command>> commands;

  std::filesystem::path cwd;
  pasta::FileManager &fm;
  std::shared_ptr<IndexingContext> ctx;

  inline PrivateData(std::filesystem::path cwd_, pasta::FileManager &fm, std::shared_ptr<IndexingContext> ctx)
      : cwd(std::move(cwd_)), fm(fm), ctx(ctx) {}
};

Importer::~Importer(void) {}

Importer::Importer(std::filesystem::path cwd_, pasta::FileManager &fm, std::shared_ptr<IndexingContext> ctx)
    : d(std::make_unique<Importer::PrivateData>(std::move(cwd_), fm, ctx)) {}

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

  std::unordered_map<std::string, std::string> envp;
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

  // E.g. from CMake, Blight.
  if (auto commands_str = o.getString("command")) {
    auto args_str = commands_str->str();
    auto &command = commands.emplace_back(args_str);
    if (command.vec.Size()) {
      DLOG(INFO) << "Parsed command: " << command.vec.Join();

      command.compiler_hash = std::move(args_str);
      command.working_dir = cwd_str;
      command.env = envp;
      FixEnvVariables(command.env, cwd_str);

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
      FixEnvVariables(command.env, cwd_str);
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

template <typename Iter, typename C>
static void ForEachInterval(Iter begin, Iter end,
                            size_t interval_size, C cb) {
  auto to = begin;
  while (to != end) {
    auto from = to;
    size_t counter = static_cast<size_t>(std::distance(from, end));
    if (counter > interval_size) {
      counter = interval_size;
    }
    std::advance(to, counter);
    cb(from, to);
  }
}

void Importer::Import(mx::Executor &exe) {
  mx::Executor per_path_exe;
  for (auto &[cwd, commands] : d->commands) {

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
      per_path_exe.EmplaceAction<BuildCommandAction>(d->fm, cmd, d->ctx);
    }

    per_path_exe.Start();
    per_path_exe.Wait();

//    typedef decltype(commands.begin()) iter_t;
//    ForEachInterval(commands.begin(), commands.end(),
//                    kCommandsBatchSize,
//                    [&](iter_t from, iter_t to) {
//
//      for (iter_t &it = from; it != to; it++) {
//        per_path_exe.EmplaceAction<BuildCommandAction>(d->fm, *it, d->ctx);
//      }
//
//      per_path_exe.Start();
//      per_path_exe.Wait();
//    });
  }
  (void)exe;
}

}  // namespace indexer
