// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Server.h"

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <glog/logging.h>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <kj/exception.h>
#include <kj/string.h>
#include <multiplier/Executor.h>
#include <multiplier/PersistentMap.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Result.h>
#include <set>
#include <sstream>
#include <mutex>
#include <vector>

#include "Context.h"
#include "Database.h"
#include "IndexCompileJob.h"
#include "RegexSearchAction.h"
#include "WeggliSearchAction.h"

namespace indexer {

class ServerContext;
class SearchingContext;
class IndexingContext;

namespace {

// Get the arguments from the compile command as an argument vector.
static pasta::ArgumentVector GetArguments(
    const mx::rpc::CompileCommand::Reader &command) {
  std::vector<std::string> args;
  args.emplace_back(command.getCompilerPath());
  for (auto arg : command.getArguments()) {
    args.emplace_back(arg);
  }
  return args;
}

}  // namespace

class ServerImpl final {
 public:
  // Worker pool for processing various commands and such.
  mx::Executor executor;

  // Workspace directory.
  std::filesystem::path workspace_dir;

  // Should we show progress bars?
  const bool show_progress_bars;

  // Should generate source IR?
  const bool generate_sourceir;

  ServerContext server_context;

  std::mutex indexing_context_lock;
  std::weak_ptr<IndexingContext> indexing_context;

  // Native file system.
  //
  // TODO(pag): Eventually, implement a `pasta::FileSystem` layer that caches
  //            into RocksDB, and investigate using Cap'n Proto capabilities
  //            to pass a file system interface to compile command indexing
  //            requests.
  std::shared_ptr<pasta::FileSystem> native_file_system;

  ServerImpl(ServerOptions &options);

  // Get or create an indexing context. If there are concurrent indexing
  // jobs underway then they'll share the same context. When they're all done
  // the context will go away as well.
  std::shared_ptr<IndexingContext> GetOrCreateIndexingContext(void);
};

// Initialize the server.
ServerImpl::ServerImpl(ServerOptions &options)
    : executor(options.executor_options),
      workspace_dir(options.workspace_dir),
      show_progress_bars(options.show_progress_bars),
      generate_sourceir(options.generate_sourceir),
      server_context(options.workspace_dir),
      native_file_system(pasta::FileSystem::CreateNative()) {}

// Get or create an indexing context. If there are concurrent indexing
// jobs underway then they'll share the same context. When they're all done
// the context will go away as well.
std::shared_ptr<IndexingContext>
ServerImpl::GetOrCreateIndexingContext(void) {
  std::unique_lock<std::mutex> locker(indexing_context_lock);
  auto ic = indexing_context.lock();
  if (ic) {
    return ic;
  } else {
    ic = std::make_shared<IndexingContext>(server_context, executor);
    if (show_progress_bars) {
      ic->InitializeProgressBars();
    }
    if (generate_sourceir) {
      ic->InitializeCodeGenerator();
    }
    indexing_context = ic;
    return ic;
  }
}

Server::~Server(void) {
  d->executor.Wait();
}

// Initialize the server.
std::shared_ptr<ServerImpl> Server::Build(ServerOptions &options_) {
  auto ret = std::make_shared<ServerImpl>(options_);
  ret->executor.Start();
  return ret;
}

// Enqueue actions to index zero or more compile commands / jobs.
kj::Promise<void> Server::indexCompileCommands(
    IndexCompileCommandsContext context) {

  mx::rpc::Multiplier::IndexCompileCommandsParams::Reader params =
      context.getParams();

  mx::rpc::Multiplier::IndexCompileCommandsResults::Builder result =
      context.initResults();

  if (!params.hasCommands()) {
    LOG(WARNING)
        << "Got request to index with no commands";
    context.setResults(result);
    result.setSuccess(true);
    return kj::READY_NOW;
  }

  pasta::FileManager fm(d->native_file_system);
  auto maybe_cc = pasta::Compiler::CreateHostCompiler(
      fm, pasta::TargetLanguage::kC);
  auto maybe_cxx = pasta::Compiler::CreateHostCompiler(
      fm, pasta::TargetLanguage::kCXX);

  if (!maybe_cc.Succeeded()) {
    LOG(ERROR)
        << "Unable to create host C compiler: "
        << maybe_cc.TakeError();

    result.setSuccess(false);
    return kj::READY_NOW;

  } else if (!maybe_cxx.Succeeded()) {
    LOG(ERROR)
        << "Unable to create host C++ compiler: "
        << maybe_cxx.TakeError();

    result.setSuccess(false);
    return kj::READY_NOW;
  }

  auto cc = maybe_cc.TakeValue();
  auto cxx = maybe_cxx.TakeValue();
  auto which_cc = [&cc, &cxx] (mx::rpc::TargetLanguage tl) {
    switch (tl) {
      case mx::rpc::TargetLanguage::C: return cc;
      default:
      case mx::rpc::TargetLanguage::CXX: return cxx;
    }
  };

  auto ic = d->GetOrCreateIndexingContext();
  for (mx::rpc::CompileCommand::Reader command : params.getCommands()) {
    mx::ProgressBarWork command_progress(ic->command_progress.get());
    IndexingCounterRes(ic->stat, kStatCompileCommand);

    auto argv = GetArguments(command);

    // NOTE(pag): The command arguments are for a `-cc1` command, and contain
    //            hard-coded
    auto maybe_cmd = pasta::CompileCommand::CreateFromArguments(
        argv, command.getWorkingDirectory());
    if (!maybe_cmd.Succeeded()) {
      LOG(ERROR)
          << "Could not create a compile command for arguments "
          << argv.Join() << ": " << maybe_cmd.TakeError();
      continue;
    }

    auto cmd = maybe_cmd.TakeValue();
    auto maybe_jobs = which_cc(command.getLanguage()).CreateJobsForCommand(cmd);
    if (!maybe_jobs.Succeeded()) {
      LOG(ERROR)
          << "Could not create one or more compile jobs from command "
          << cmd.Arguments().Join() << ": " << maybe_jobs.TakeError();
      continue;
    }

    for (pasta::CompileJob job : maybe_jobs.TakeValue()) {
      DLOG(INFO)
          << "Enqueuing indexing job for main source file "
          << job.SourceFile().Path().generic_string();
      d->executor.EmplaceAction<IndexCompileJobAction>(ic, fm, std::move(job));
    }
  }

  result.setSuccess(true);
  return kj::READY_NOW;
}

// Say hello to the server.
kj::Promise<void> Server::hello(HelloContext context) {
  unsigned version_number = d->server_context.version_number.load();
  auto result = context.initResults();
  result.setVersionNumber(version_number);
  return kj::READY_NOW;
}

// Download a list of file info (file id, path).
kj::Promise<void> Server::downloadFileList(
    DownloadFileListContext context) {
  unsigned version_number = d->server_context.version_number.load();

  std::vector<std::pair<mx::RawEntityId, std::string>> paths;
  d->server_context.file_id_to_path.ScanPrefix(
      mx::Empty{},
      [=, &paths] (mx::RawEntityId file_id, std::string file_path) {
        DCHECK_NE(file_id, mx::kInvalidEntityId);
        DCHECK(!file_path.empty());
        paths.emplace_back(file_id, std::move(file_path));
        return true;
      });

  auto num_files = static_cast<unsigned>(paths.size());
  auto result = context.initResults();
  result.setVersionNumber(version_number);

  auto files_builder = result.initFiles(num_files);
  for (auto i = 0u; i < num_files; ++i) {
    const auto &path = paths[i];
    mx::rpc::FileInfo::Builder info = files_builder[i];
    info.setId(path.first);
    info.setPath(path.second);
  }

  return kj::READY_NOW;
}

// Download a file associated with a specific file ID.
kj::Promise<void> Server::downloadFile(DownloadFileContext context) {
  mx::rpc::Multiplier::DownloadFileParams::Reader params =
      context.getParams();

  unsigned version_number = d->server_context.version_number.load();

  mx::RawEntityId file_id = params.getId();
  std::optional<std::string> maybe_contents =
      d->server_context.file_id_to_serialized_file.TryGet(file_id);
  if (!maybe_contents) {
    std::stringstream err;
    err << "Invalid file id " << file_id;
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{
      ((maybe_contents->size() + 7u / 8u)),
      0u};

  mx::rpc::Multiplier::DownloadFileResults::Builder result =
      context.initResults(size);
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(maybe_contents.value().data()),
      maybe_contents.value().size());

  result.setVersionNumber(version_number);
  result.setFile(contents_reader);

  return kj::READY_NOW;
}

// Download a fragment containing a token with a specific ID.
kj::Promise<void> Server::downloadFragment(DownloadFragmentContext context) {
  mx::rpc::Multiplier::DownloadFragmentParams::Reader params =
      context.getParams();

  std::stringstream err;
  mx::RawEntityId fragment_id = params.getId();

  std::optional<std::string> maybe_contents =
      d->server_context.fragment_id_to_serialized_fragment.TryGet(fragment_id);
  if (!maybe_contents) {
    err << "Invalid fragment id " << fragment_id << "; missing data";
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  capnp::MessageSize size{maybe_contents->size() + 7u / 8u, 0u};
  mx::rpc::Multiplier::DownloadFragmentResults::Builder result =
      context.initResults(size);
  result.setFragment(kj::arrayPtr(
      reinterpret_cast<const capnp::byte *>(maybe_contents.value().data()),
      maybe_contents.value().size()));

  return kj::READY_NOW;
}

// Search code fragments that match with the query.
kj::Promise<void> Server::weggliQueryFragments(
    WeggliQueryFragmentsContext context) {

  // Get params and result context
  mx::rpc::Multiplier::WeggliQueryFragmentsParams::Reader params =
      context.getParams();

  auto result = context.initResults();
  result.setVersionNumber(d->server_context.version_number.load());

  std::string syntax_string(params.getQuery().cStr(), params.getQuery().size());
  if (syntax_string.empty()) {
    (void) result.initFragmentIds(0u);
    return kj::READY_NOW;
  }

  auto sc = std::make_shared<SearchingContext>(d->server_context);

  const bool is_cpp = params.getIsCpp();

  // Run N parallel search actions on every file.
  mx::ExecutorOptions opts;
  opts.num_workers = static_cast<int>(d->executor.NumWorkers());
  mx::Executor executor(opts);
  executor.Start();
  for (auto i = 0; i < opts.num_workers; ++i) {
    executor.EmplaceAction<WeggliSearchAction>(sc, syntax_string, is_cpp);
  }
  executor.Wait();

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);

  // Convert the file file:line pairs into overlapping fragment IDs.
  for (auto prefix : sc->line_results) {
    d->server_context.file_fragment_lines.ScanPrefix(
        prefix,
        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
          if (fragment_ids.empty() || fragment_ids.back() != id) {
            fragment_ids.push_back(id);
          }
          return true;
        });
  }

  // Keep only unique fragment ids.
  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());

  auto num_fragments = fragment_ids.size();
  std::stringstream err;
  if (num_fragments >= std::numeric_limits<unsigned>::max()) {
    err << "Too many fragments found: " << num_fragments
        << "; for weggli: " << syntax_string;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto fragments = result.initFragmentIds(static_cast<unsigned>(num_fragments));
  auto index = 0u;
  for (mx::RawEntityId fragment_id : fragment_ids) {
    fragments.set(index++, fragment_id);
  }

  return kj::READY_NOW;
}

// Query for a regular expression match, and return the list of fragment ids
// overlapping with the matches.
kj::Promise<void> Server::regexQueryFragments(
    RegexQueryFragmentsContext context) {
  // Get params and result context
  mx::rpc::Multiplier::RegexQueryFragmentsParams::Reader params =
      context.getParams();

  auto result = context.initResults();
  result.setVersionNumber(d->server_context.version_number.load());

  std::string pattern(params.getRegex().cStr(), params.getRegex().size());
  if (pattern.empty()) {
    (void) result.initFragmentIds(0u);
    return kj::READY_NOW;
  }

  auto sc = std::make_shared<SearchingContext>(d->server_context);
  mx::ExecutorOptions opts;
  opts.num_workers = static_cast<int>(d->executor.NumWorkers());
  mx::Executor executor(opts);
  executor.Start();
  for (auto i = 0; i < opts.num_workers; ++i) {
    executor.EmplaceAction<RegexSearchAction>(sc, pattern);
  }
  executor.Wait();

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);

  // Convert the file file:line pairs into overlapping fragment IDs.
  for (auto prefix : sc->line_results) {
    d->server_context.file_fragment_lines.ScanPrefix(
        prefix,
        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
          if (fragment_ids.empty() || fragment_ids.back() != id) {
            fragment_ids.push_back(id);
          }
          return true;
        });
  }

  // Keep only unique fragment ids.
  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());

  auto num_fragments = fragment_ids.size();
  std::stringstream err;
  if (num_fragments >= std::numeric_limits<unsigned>::max()) {
    err << "Too many fragments found: " << num_fragments
        << "; for regex: " << pattern;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto match_builder = result.initFragmentIds(
      static_cast<unsigned>(num_fragments));
  auto index = 0u;
  for (mx::RawEntityId frag_id : fragment_ids) {
    match_builder.set(index++, frag_id);
  }

  return kj::READY_NOW;
}

// Expand a list of redeclarations to try to cover all redeclarations across
// all translation units. The first redeclaration in the list should be the
// definition.
kj::Promise<void> Server::findRedeclarations(FindRedeclarationsContext context) {
  mx::rpc::Multiplier::FindRedeclarationsParams::Reader params =
      context.getParams();

  // Check the input entity IDs. They all need to be declaration IDs.
  mx::EntityId eid(params.getDeclId());
  mx::VariantId vid = eid.Unpack();

  if (!std::holds_alternative<mx::DeclarationId>(vid)) {
    return kj::Exception(
        kj::Exception::Type::FAILED, __FILE__, __LINE__,
        kj::heapString("Cannot complete operation with non-declaration entity ID"));
  }

  std::vector<mx::RawEntityId> redecl_ids =
      d->server_context.FindRedeclarations(eid);

  mx::rpc::Multiplier::FindRedeclarationsResults::Builder result =
      context.initResults();

  result.setVersionNumber(d->server_context.version_number.load());
  auto rib = result.initRedeclarationIds(
      static_cast<unsigned>(redecl_ids.size()));
  auto i = 0u;
  for (mx::RawEntityId redecl_id : redecl_ids) {
    rib.set(i++, redecl_id);
  }

  return kj::READY_NOW;
}

// Given a list of declaration IDs that all logically represent the same
// declaration, return a list of fragment IDs that contain some kind of use
// of the declarations.
kj::Promise<void> Server::findUses(FindUsesContext context) {
  mx::rpc::Multiplier::FindUsesParams::Reader params =
      context.getParams();

  mx::rpc::Multiplier::FindUsesResults::Builder result =
      context.initResults();

  result.setVersionNumber(d->server_context.version_number.load());

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(16u);

  for (mx::RawEntityId eid : params.getRedeclarationIds()) {
    d->server_context.entity_id_use_to_fragment_id.ScanPrefix(
        eid,
        [&fragment_ids] (mx::RawEntityId, mx::RawEntityId frag_id) {
          fragment_ids.push_back(frag_id);
          return true;
        });
  }

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());

  auto num_fragments = fragment_ids.size();
  std::stringstream err;
  if (num_fragments >= std::numeric_limits<unsigned>::max()) {
    err << "Too many fragments found: " << num_fragments;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto fib = result.initFragmentIds(static_cast<unsigned>(num_fragments));
  auto i = 0u;
  for (mx::RawEntityId frag_id : fragment_ids) {
    fib.set(i++, frag_id);
  }

  return kj::READY_NOW;
}

// Given a list of declaration IDs that all logically represent the same
// declaration, return a list of statement entity ids that reference any of
// the declarations. This focuses on `DeclRefExpr` and `MemberExpr` references.
kj::Promise<void> Server::findReferences(FindReferencesContext context) {
  mx::rpc::Multiplier::FindReferencesParams::Reader params =
      context.getParams();

  mx::rpc::Multiplier::FindReferencesResults::Builder result =
      context.initResults();

  result.setVersionNumber(d->server_context.version_number.load());

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(16u);

  for (mx::RawEntityId eid : params.getRedeclarationIds()) {
    d->server_context.entity_id_reference.ScanPrefix(
        eid,
        [&fragment_ids] (mx::RawEntityId, mx::RawEntityId frag_id) {
          fragment_ids.push_back(frag_id);
          return true;
        });
  }

  std::sort(fragment_ids.begin(), fragment_ids.end());
  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
  fragment_ids.erase(it, fragment_ids.end());

  auto num_fragments = fragment_ids.size();
  std::stringstream err;
  if (num_fragments >= std::numeric_limits<unsigned>::max()) {
    err << "Too many fragments found: " << num_fragments;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto fib = result.initFragmentIds(static_cast<unsigned>(num_fragments));
  auto i = 0u;
  for (mx::RawEntityId frag_id : fragment_ids) {
    fib.set(i++, frag_id);
  }

  return kj::READY_NOW;
}

// Find the list of fragment IDs associated with a specific file.
kj::Promise<void> Server::findFileFragments(FindFileFragmentsContext context) {
  mx::rpc::Multiplier::FindFileFragmentsParams::Reader params =
      context.getParams();

  mx::rpc::Multiplier::FindFileFragmentsResults::Builder result =
      context.initResults();

  result.setVersionNumber(d->server_context.version_number.load());

  mx::RawEntityId file_id = params.getFileId();

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);

  // Collect the fragments associated with this file.
  d->server_context.file_fragment_ids.ScanPrefix(
      file_id,
      [file_id, &fragment_ids] (mx::RawEntityId found_file_id,
                                mx::RawEntityId fragment_id) {
        DCHECK_EQ(file_id, found_file_id);
        fragment_ids.push_back(fragment_id);
        return file_id == found_file_id;
      });

  auto num_fragments = fragment_ids.size();
  std::stringstream err;
  if (num_fragments >= std::numeric_limits<unsigned>::max()) {
    err << "Too many fragments found: " << num_fragments;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto fragments = result.initFragmentIds(static_cast<unsigned>(num_fragments));
  for (auto i = 0u; i < num_fragments; ++i) {
    fragments.set(i, fragment_ids[i]);
  }

  return kj::READY_NOW;
}

kj::Promise<void> Server::findSymbols(FindSymbolsContext context) {
  mx::rpc::Multiplier::FindSymbolsParams::Reader params = context.getParams();
  mx::rpc::Multiplier::FindSymbolsResults::Builder result =
      context.getResults();

  result.setVersionNumber(d->server_context.version_number.load());

  std::string symbol(params.getQuery().cStr(), params.getQuery().size());
  mx::DeclCategory category = static_cast<mx::DeclCategory>(
      params.getCategory());

  std::vector<mx::RawEntityId> entity_ids =
      d->server_context.database.QueryEntities(
          symbol, category);

  // Sort the redeclaration IDs to that they are always in the same order,
  // regardless of which one we ask for first, then partition them and move
  // the definitions before the declarations.
  std::sort(entity_ids.begin(), entity_ids.end());
  std::partition(
      entity_ids.begin(), entity_ids.end(),
      [] (mx::RawEntityId eid) {
        return std::get<mx::DeclarationId>(
            mx::EntityId(eid).Unpack()).is_definition;
      });

  std::stringstream err;
  auto num_entities = entity_ids.size();
  if (num_entities >= std::numeric_limits<unsigned>::max()) {
    err << "Too many results returned: " << num_entities;
    LOG(ERROR) << err.str();
    return kj::Exception(kj::Exception::Type::FAILED, __FILE__, __LINE__,
                         kj::heapString(err.str()));
  }

  auto info = result.initDeclarationIds(
      static_cast<unsigned>(num_entities));
  for (auto i = 0u; i < num_entities; ++i) {
    info.set(i, entity_ids[i]);
  }

  return kj::READY_NOW;
}

}  // namespace indexer
