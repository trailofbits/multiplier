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

#include <drlojekyll/Runtime/Bytes.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <llvm/Support/Format.h>
#include <llvm/Support/FormatVariadic.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>
#include <multiplier/Action.h>
#include <multiplier/Datalog.h>
#include <multiplier/Executor.h>
#include <multiplier/Result.h>
#include <multiplier/Subprocess.h>
#include <multiplier/Tool.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>

DECLARE_string(system_compiler);
DECLARE_string(sysroot_dir);
DECLARE_string(resource_dir);

namespace importer {
namespace {

using BuilderList = std::vector<std::unique_ptr<mx::DatalogMessageBuilder>>;

struct Command {
 public:
  std::string compiler_hash;
  std::string working_dir;
  std::unordered_map<std::string, std::string> env;
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
  const BuilderList &builders;

  // If we are using something like CMake commands, then pull in the relevant
  // information by trying to execute the compiler directly.
  std::pair<std::string, std::string> InitCompilerFromCommand(void);

  void RunWithCompiler(pasta::CompileCommand cmd, pasta::Compiler cc,
                       mx::DatalogMessageBuilder &builder);

 public:
  virtual ~BuildCommandAction(void) = default;

  inline BuildCommandAction(pasta::FileManager &fm_, Command &command_,
                            const BuilderList &builders_)
      : fm(fm_),
        command(command_),
        builders(builders_) {}

  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

// If we are using something like CMake commands, then pull in the relevant
// information by trying to execute the compiler directly.
std::pair<std::string, std::string>
BuildCommandAction::InitCompilerFromCommand(void) {
  std::vector<std::string> new_args;
  for (auto arg : command.vec) {
    new_args.emplace_back(arg);
  }
  new_args.emplace_back("-Wno-missing-sysroot");
  new_args.emplace_back("-E");
  new_args.emplace_back("-v");
  pasta::ArgumentVector cmd_sysroot(new_args);

  new_args.emplace_back("-isysroot");
  new_args.emplace_back(command.working_dir + "/xyz");
  pasta::ArgumentVector cmd_no_sysroot(new_args);

  std::stringstream output_sysroot;
  std::stringstream output_no_sysroot;
  (void) mx::Subprocess::Execute(
      cmd_sysroot, &(command.env), nullptr, nullptr, &output_sysroot);

  (void) mx::Subprocess::Execute(
      cmd_no_sysroot, &(command.env), nullptr, nullptr, &output_no_sysroot);

  return {output_sysroot.str(), output_no_sysroot.str()};
}

void BuildCommandAction::RunWithCompiler(pasta::CompileCommand cmd,
                                         pasta::Compiler cc,
                                         mx::DatalogMessageBuilder &builder) {
  auto maybe_jobs = cc.CreateJobsForCommand(cmd);
  if (!maybe_jobs.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile jobs: " << maybe_jobs.TakeError();
    return;
  }

  std::vector<flatbuffers::Offset<flatbuffers::String>> arg_list;
  std::vector<flatbuffers::Offset<mx::IncludePath>> path_list;

  for (pasta::CompileJob job : maybe_jobs.TakeValue()) {

    flatbuffers::FlatBufferBuilder fbb;
    auto sp = fbb.CreateString(job.SourceFile().Path().generic_string());
    auto cp = fbb.CreateString(cc.ExecutablePath().generic_string());

    // NOTE: Force the working directory to the source file path to avoid
    //       issues while creating jobs from the compiled args.
    auto cwd = fbb.CreateString(job.SourceFile().Path().parent_path().generic_string());
    auto srd = fbb.CreateString(job.SystemRootIncludeDirectory().generic_string());
    auto rd = fbb.CreateString(job.ResourceDirectory().generic_string());
    auto id = fbb.CreateString(cc.InstallationDirectory().generic_string());

    path_list.clear();
    cc.ForEachSystemIncludeDirectory(
        [&] (const std::filesystem::path &path,
             pasta::IncludePathLocation ipl) {
          auto p = fbb.CreateString(path.generic_string());
          mx::IncludePathBuilder ipb(fbb);
          ipb.add_Directory(std::move(p));
          ipb.add_Location(mx::FromPasta(ipl));
          path_list.emplace_back(ipb.Finish());
        });

    auto sips = fbb.CreateVector(path_list);

    path_list.clear();
    cc.ForEachUserIncludeDirectory(
        [&] (const std::filesystem::path &path,
             pasta::IncludePathLocation ipl) {
          auto p = fbb.CreateString(path.generic_string());
          mx::IncludePathBuilder ipb(fbb);
          ipb.add_Directory(std::move(p));
          ipb.add_Location(mx::FromPasta(ipl));
          path_list.emplace_back(ipb.Finish());
        });

    auto uips = fbb.CreateVector(path_list);

    path_list.clear();
    cc.ForEachFrameworkDirectory(
        [&] (const std::filesystem::path &path,
             pasta::IncludePathLocation ipl) {
          auto p = fbb.CreateString(path.generic_string());
          mx::IncludePathBuilder ipb(fbb);
          ipb.add_Directory(std::move(p));
          ipb.add_Location(mx::FromPasta(ipl));
          path_list.emplace_back(ipb.Finish());
        });

    auto fips = fbb.CreateVector(path_list);

    arg_list.clear();
    for (auto arg : job.Arguments()) {
      arg_list.push_back(fbb.CreateSharedString(arg, strlen(arg)));
    }

    auto args = fbb.CreateVector(arg_list);

    mx::CompileCommandBuilder ccb(fbb);
    ccb.add_SourcePath(std::move(sp));
    ccb.add_CompilerPath(std::move(cp));
    ccb.add_WorkingDirectory(std::move(cwd));
    ccb.add_SystemRootDirectory(std::move(srd));
    ccb.add_ResourceDirectory(std::move(rd));
    ccb.add_InstallationDirectory(std::move(id));
    ccb.add_SystemIncludePaths(std::move(sips));
    ccb.add_UserIncludePaths(std::move(uips));
    ccb.add_FrameworkPaths(std::move(fips));
    ccb.add_Arguments(std::move(args));
    ccb.add_Compiler(mx::FromPasta(cc.Name()));
    ccb.add_Language(mx::FromPasta(cc.TargetLanguage()));
    fbb.Finish(ccb.Finish());
    auto data_ptr = fbb.GetCurrentBufferPointer();
    hyde::rt::Bytes data(data_ptr, &(data_ptr[fbb.GetSize()]));
    builder.compile_command_1(data);
  }
}

// Build the compilers for the commands, then build the commands.
void BuildCommandAction::Run(mx::Executor exe, mx::WorkerId worker_id) {

  pasta::Result<pasta::CompileCommand, std::string_view> maybe_cmd =
      pasta::CompileCommand::CreateFromArguments(
          command.vec, command.working_dir);
  if (!maybe_cmd.Succeeded()) {
    LOG(ERROR)
        << "Unable to create compile command: " << maybe_cmd.TakeError();
    return;
  }

  auto [cc_version_sysroot, cc_version_no_sysroot] = InitCompilerFromCommand();

  pasta::Result<pasta::Compiler, std::string> maybe_cc =
      pasta::Compiler::Create(fm, command.vec[0], command.working_dir,
                              command.name, command.lang, cc_version_sysroot,
                              cc_version_no_sysroot);

  mx::DatalogMessageBuilder &builder =
      *(builders[static_cast<unsigned>(worker_id)]);

  if (!maybe_cc.Succeeded()) {
    auto error = maybe_cc.TakeError();
    maybe_cc = pasta::Compiler::CreateHostCompiler(fm, command.lang);
    if (maybe_cc.Succeeded()) {
      RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue(),
                      builder);
    } else {
      LOG(ERROR)
          << "Unable to create compiler: " << error;
    }
  } else {
    RunWithCompiler(maybe_cmd.TakeValue(), maybe_cc.TakeValue(),
                    builder);
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
};

Importer::~Importer(void) {}

Importer::Importer(void)
    : d(std::make_unique<Importer::PrivateData>()) {}

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

  auto &command = d->commands[cwd->str()].emplace_back(args_vec);
  command.working_dir = cwd->str();
  command.compiler_hash = hash->str();
  command.env = std::move(envp);
  if (lang->equals_insensitive("c++") || lang->equals_insensitive("cxx")) {
    command.lang = pasta::TargetLanguage::kCXX;
  }
  return true;
}


bool Importer::ImportCMakeCompileCommand(llvm::json::Object &o) {
  auto args = o.getString("command");
  auto cwd = o.getString("directory");
  auto file = o.getString("file");
  if (!args || !cwd || !file) {
    return false;
  }

  auto &commands = d->commands[cwd->str()];
  auto args_str = args->str();
  auto &command = commands.emplace_back(args_str);
  if (command.vec.Size()) {
    command.compiler_hash = std::move(args_str);
    command.working_dir = cwd->str();

    // Guess at the language.
    if (args->contains_insensitive("++") || args->contains_insensitive(".cc") ||
        args->contains_insensitive(".cxx") || args->contains_insensitive(".cpp") ||
        args->contains_insensitive(".hxx") || args->contains_insensitive(".hpp")) {
      command.lang = pasta::TargetLanguage::kCXX;
    }

    return true;

  } else {
    commands.pop_back();
    return false;
  }
}

void Importer::Build(mx::DatalogClient &client) {
  mx::Executor exe;

  // Make one builder per worker thread. This is a sort of thread-locat storage.
  BuilderList builders;
  for (auto i = 0u, max_i = exe.NumWorkers(); i < max_i; ++i) {
    builders.emplace_back(new mx::DatalogMessageBuilder);
  }

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

    // Now re-build a host file sytem, and let it observe the changed working
    // directory.
    auto host_fs = pasta::FileSystem::CreateNative();
    pasta::FileManager fm(host_fs);

    // Run all commands relevant to just this working directory.
    for (Command &command : commands) {
      exe.EmplaceAction<BuildCommandAction>(fm, command, builders);
    }
    exe.Start();
    exe.Wait();

    // If we've got any messages, then send them out. The granularity is likely
    // to be small because we don't expect many files to operate in the same
    // working directory, though if they do, then at least we still have the
    // benefit of the N-way split from the executor.
    for (const auto &builder : builders) {
      if (builder->HasAnyMessages()) {
        if (!client.Publish(*builder)) {
          LOG(ERROR)
              << "Unable to publish compile jobs to mx-server";
        }
      }
    }
  }
}

}  // namespace importer
