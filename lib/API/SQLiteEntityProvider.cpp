// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"

#include <multiplier/Re2.h>
#include <multiplier/Types.h>

#include "API.h"
#include "Compress.h"
#include "Re2.h"
#include "../Common/SQLiteStore.h"

namespace mx {

class SQLiteEntityProvider::Context {
 private:
  sqlite::Connection db;
  sqlite::Statement::Ptr get_file_by_id;
  sqlite::Statement::Ptr get_frag_by_id;
  sqlite::Statement::Ptr get_version_number;
  sqlite::Statement::Ptr get_file_paths;
  sqlite::Statement::Ptr get_file_fragments;
  sqlite::Statement::Ptr get_file_data;
  sqlite::Statement::Ptr get_fragment_data;
  sqlite::Statement::Ptr get_redecls_by_mangled_name;
  sqlite::Statement::Ptr get_redecls_by_entity_id;

 public:

  Context(std::filesystem::path path)
      : db(path, true  /* read-only */),
        get_file_by_id(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_frag_by_id(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        get_version_number(db.Prepare(
            "SELECT COUNT(*) FROM versions")),
        get_file_paths(db.Prepare(
            "SELECT file_id, path FROM file_path")),
        get_file_fragments(db.Prepare(
            "SELECT fragment_id FROM fragment WHERE file_id = ?1")),
        get_file_data(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_fragment_data(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        get_redecls_by_mangled_name(db.Prepare(
            R"(SELECT b.entity_id
               FROM mangled_name AS a
               LEFT JOIN mangled_name AS b
               ON a.data = b.data
               WHERE a.entity_id = ?1)")),
        get_redecls_by_entity_id(db.Prepare(
            "SELECT redecl_id FROM redeclaration WHERE decl_id = ?1")) {}
};

SQLiteEntityProvider::SQLiteEntityProvider(std::filesystem::path path)
    : db_path(path),
      thread_context([this] (unsigned) -> Context * {
        return new Context(db_path);
      }){}

SQLiteEntityProvider::~SQLiteEntityProvider(void) noexcept {}

void SQLiteEntityProvider::ClearCache(void) {}

unsigned SQLiteEntityProvider::VersionNumber(void) {
  unsigned version_number = 0u;

  std::shared_ptr<Context> context = thread_context.Lock();
  auto stmt = context->get_version_number.get();
  if (stmt->ExecuteStep()) {
    auto result = stmt->GetResult();
    result.Columns(version_number);
  }
  return version_number;
}

unsigned SQLiteEntityProvider::VersionNumber(const Ptr &) {
  return VersionNumber();
}

void SQLiteEntityProvider::VersionNumberChanged(unsigned) {}

FilePathMap SQLiteEntityProvider::ListFiles(const Ptr &) {
  FilePathMap res;
  std::shared_ptr<Context> context = thread_context.Lock();
  auto query = context->get_file_paths.get();
  while (query->ExecuteStep()) {
    RawEntityId id = kInvalidEntityId;
    std::filesystem::path path;
    query->GetResult().Columns(id, path);

    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FileId>(vid)) {
      res.emplace(std::move(path), std::get<FileId>(vid));
    } else {
      assert(false);
    }
  }

  return res;
}

FragmentIdList SQLiteEntityProvider::ListFragmentsInFile(
    const Ptr &, SpecificEntityId<FileId> file_id) {

  FragmentIdList res;
  res.reserve(128u);

  std::shared_ptr<Context> context = thread_context.Lock();
  auto query = context->get_file_fragments.get();
  query->BindValues(file_id.Pack());

  while (query->ExecuteStep()) {
    RawEntityId id = kInvalidEntityId;
    query->GetResult().Columns(id);

    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      res.emplace_back(std::get<FragmentId>(vid));
    } else {
      assert(false);
    }
  }

  return res;
}

std::shared_ptr<const FileImpl> SQLiteEntityProvider::FileFor(
    const Ptr &self, SpecificEntityId<FileId> file_id) {

  std::shared_ptr<Context> context = thread_context.Lock();
  auto query = context->get_file_data.get();
  query->BindValues(file_id.Pack());

  if (!query->ExecuteStep()) {
    return {};
  }

  std::string data;
  query->GetResult().Columns(data);
  if (data.empty()) {
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<PackedFileImpl>(
      file_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FileImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<const FragmentImpl> SQLiteEntityProvider::FragmentFor(
    const Ptr &self, SpecificEntityId<FragmentId> fragment_id) {

  std::shared_ptr<Context> context = thread_context.Lock();
  auto query = context->get_file_data.get();
  query->BindValues(fragment_id.Pack());

  if (!query->ExecuteStep()) {
    return {};
  }

  std::string data;
  query->GetResult().Columns(data);
  if (data.empty()) {
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<PackedFragmentImpl>(
      fragment_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FragmentImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<WeggliQueryResultImpl> SQLiteEntityProvider::Query(
    const Ptr &self, const WeggliQuery &query_tree) {
  (void) self;
  (void) query_tree;
//  std::map<unsigned, unsigned> eol_offset_to_line_num;
//  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
//  auto &storage = d->GetStorage();
//  for(RawEntityId file_id = kMinEntityIdIncrement;
//        file_id < d->next_file_id;
//        ++file_id) {
//
//    // Get the contents of the file. We may fail, which is OK, and generally
//    // implies a bad file id. There can be small gaps in the file ID space,
//    // which otherwise mostly occupies the range `[1, N)`.
//    auto maybe_contents = storage.GetSerializedFile(file_id);
//    if (!maybe_contents) {
//      continue;  // Bad file ID. This is expected for the way we get them.
//    }
//
//    WithUncompressedMessageImpl(
//      "file", maybe_contents.value(),
//      [=, this, &eol_offset_to_line_num, &line_results]
//      (capnp::MessageReader &reader) {
//        mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
//        std::string_view file_contents(file.getData().cStr(),
//                                       file.getData().size());
//
//        eol_offset_to_line_num.clear();
//        for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
//          eol_offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
//        }
//
//        query_tree.ForEachMatch(
//            file_contents,
//            [=, this, &line_results] (const mx::WeggliMatchData &match) -> bool {
//              unsigned prev_line = 0;
//              for (auto i = match.begin_offset; i < match.end_offset; ++i) {
//                auto line_it = eol_offset_to_line_num.upper_bound(i);
//                if (line_it != eol_offset_to_line_num.end()) {
//                  auto line = line_it->second;
//                  if (line != prev_line) {
//                    prev_line = line;
//                    line_results.emplace(file_id, line);
//                  }
//                }
//              }
//              return true;
//            });
//        });
//  }
//
//  std::vector<mx::RawEntityId> fragment_ids;
//  fragment_ids.reserve(128u);
//
//  // Convert the file file:line pairs into overlapping fragment IDs.
//  for (auto prefix : line_results) {
//    storage.file_fragment_lines.GetByPrefix(
//        prefix,
//        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
//          if (fragment_ids.empty() || fragment_ids.back() != id) {
//            fragment_ids.push_back(id);
//          }
//          return true;
//        });
//  }
//
//  // Keep only unique fragment ids.
//  std::sort(fragment_ids.begin(), fragment_ids.end());
//  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
//  fragment_ids.erase(it, fragment_ids.end());
//
//  return std::make_shared<WeggliQueryResultImpl>(
//      query_tree, self, std::move(fragment_ids));
}

std::shared_ptr<RegexQueryResultImpl> SQLiteEntityProvider::Query(
    const Ptr &self, const RegexQuery &regex) {
  (void) self;
  (void) regex;
//
//  std::map<unsigned, unsigned> offset_to_line_num;
//  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
//  auto &storage = d->GetStorage();
//  for(RawEntityId file_id = kMinEntityIdIncrement;
//        file_id < d->next_file_id;
//        ++file_id) {
//    // Get the contents of the file. We may fail, which is OK, and generally
//    // implies a bad file id. There can be small gaps in the file ID space, which
//    // otherwise mostly occupies the range `[1, N)`.
//    auto maybe_contents = storage.GetSerializedFile(file_id);
//    if (!maybe_contents) {
//      continue;  // Bad file ID. This is expected for the way we get them.
//    }
//
//    WithUncompressedMessageImpl(
//        "file", maybe_contents.value(),
//        [=, this, &offset_to_line_num, &line_results]
//        (capnp::MessageReader &reader) {
//          mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
//          std::string_view file_contents(file.getData().cStr(),
//                                         file.getData().size());
//
//          offset_to_line_num.clear();
//          for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
//            offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
//          }
//
//          regex.ForEachMatch(
//              file_contents,
//              [=, this, &line_results] (std::string_view, unsigned begin,
//                                        unsigned end) -> bool {
//                unsigned prev_line = 0;
//                for (auto i = begin; i < end; ++i) {
//                  auto line_it = offset_to_line_num.upper_bound(i);
//                  if (line_it != offset_to_line_num.end()) {
//                    auto line = line_it->second;
//                    if (line != prev_line) {
//                      prev_line = line;
//                      line_results.emplace(file_id, line);
//                    }
//                  }
//                }
//                return true;
//              });
//        });
//  }
//
//  std::vector<mx::RawEntityId> fragment_ids;
//  fragment_ids.reserve(128u);
//  // Convert the file file:line pairs into overlapping fragment IDs.
//  for (auto prefix : line_results) {
//    storage.file_fragment_lines.GetByPrefix(
//        prefix,
//        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
//          if (fragment_ids.empty() || fragment_ids.back() != id) {
//            fragment_ids.push_back(id);
//          }
//          return true;
//        });
//  }
//  // Keep only unique fragment ids.
//  std::sort(fragment_ids.begin(), fragment_ids.end());
//  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
//  fragment_ids.erase(it, fragment_ids.end());
//
//  return std::make_shared<RegexQueryResultImpl>(
//      regex, self, std::move(fragment_ids));
}

DeclarationIdList SQLiteEntityProvider::Redeclarations(
    const Ptr &, SpecificEntityId<DeclarationId> id) {

  RawEntityId raw_id = id.Pack();
  std::shared_ptr<Context> context = thread_context.Lock();
  auto mangled_name_query = context->get_redecls_by_mangled_name.get();
  auto redecl_query = context->get_redecls_by_entity_id.get();

  // All of the declaration kinds need to actually match.
  DeclarationId did = id.Unpack();
  DeclarationIdList all_ids;
  std::vector<RawEntityId> next_new_ids;
  std::vector<RawEntityId> new_ids;
  next_new_ids.reserve(16);
  all_ids.reserve(16);
  new_ids.reserve(16);
  next_new_ids.push_back(raw_id);

  // Expand the set of IDs via name mangling.
  switch (did.kind) {
    case DeclKind::FUNCTION:
    case DeclKind::CXX_METHOD:
    case DeclKind::CXX_DESTRUCTOR:
    case DeclKind::CXX_CONVERSION:
    case DeclKind::CXX_CONSTRUCTOR:
    case DeclKind::CXX_DEDUCTION_GUIDE:

    case DeclKind::VAR:
    case DeclKind::DECOMPOSITION:
    case DeclKind::IMPLICIT_PARAM:
    case DeclKind::OMP_CAPTURED_EXPR:
    case DeclKind::PARM_VAR:
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      mangled_name_query->BindValues(raw_id);
      while (mangled_name_query->ExecuteStep()) {
        RawEntityId next_id = kInvalidEntityId;
        mangled_name_query->GetResult().Columns(next_id);
        if (next_id != kInvalidEntityId && next_id != raw_id) {
          next_new_ids.push_back(next_id);
        }
      }
      break;

    default:
      break;
  }

  all_ids.reserve(next_new_ids.size());

  // Expand the set of declarations via fixpoint using the redeclaration
  // graph.
  while (!next_new_ids.empty()) {
    next_new_ids.swap(new_ids);
    next_new_ids.clear();
    for (RawEntityId new_raw_id : new_ids) {

      const VariantId new_vid = EntityId(new_raw_id).Unpack();
      if (!std::holds_alternative<DeclarationId>(new_vid)) {
        assert(false);
        continue;
      }

      const DeclarationId new_did = std::get<DeclarationId>(new_vid);
      if (new_did.kind != did.kind) {
        assert(false);
        continue;
      }

      SpecificEntityId<DeclarationId> new_id(new_did);
      if (std::find(all_ids.begin(), all_ids.end(), new_id) != all_ids.end()) {
        continue;
      }

      all_ids.push_back(new_id);
      redecl_query->BindValues(new_raw_id);
      while (redecl_query->ExecuteStep()) {
        RawEntityId other_id = kInvalidEntityId;
        redecl_query->GetResult().Columns(other_id);
        next_new_ids.push_back(other_id);
      }
    }
  }

  // Sort the redeclaration IDs to that they are always in the same order,
  // regardless of which one we ask for first, then partition them and move
  // the definitions before the declarations.
  std::sort(all_ids.begin(), all_ids.end());
  std::partition(
      all_ids.begin(), all_ids.end(),
      [] (SpecificEntityId<DeclarationId> eid) {
        return eid.Unpack().is_definition;
      });

  return all_ids;
}

void SQLiteEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid, DeclarationIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  redecl_ids_out = Redeclarations(self, eid);
  for (mx::RawEntityId eid : redecl_ids_out) {
    d->GetStorage().entity_id_use_to_fragment_id.GetByField<0>(
        eid,
        [&fragment_ids_out] (mx::RawEntityId, mx::RawEntityId frag_id) {
          fragment_ids_out.push_back(frag_id);
          return true;
        });
  }

  std::sort(fragment_ids_out.begin(), fragment_ids_out.end());
  auto it = std::unique(fragment_ids_out.begin(), fragment_ids_out.end());
  fragment_ids_out.erase(it, fragment_ids_out.end());
}

void SQLiteEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid, std::vector<RawEntityId> &redecl_ids_out,
    std::vector<RawEntityId> &fragment_ids_out) {

  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  redecl_ids_out = Redeclarations(self, eid);
  for (mx::RawEntityId eid : redecl_ids_out) {
    d->GetStorage().entity_id_reference.GetByField<0>(
        eid,
        [&fragment_ids_out] (mx::RawEntityId, mx::RawEntityId frag_id) {
          fragment_ids_out.push_back(frag_id);
          return true;
        });
  }

  std::sort(fragment_ids_out.begin(), fragment_ids_out.end());
  auto it = std::unique(fragment_ids_out.begin(), fragment_ids_out.end());
  fragment_ids_out.erase(it, fragment_ids_out.end());
}

void SQLiteEntityProvider::FindSymbol(const Ptr &, std::string symbol,
                                      mx::DeclCategory category,
                                      std::vector<RawEntityId> &entity_ids) {
  entity_ids = d->GetStorage().database.QueryEntities(
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
}

EntityProvider::Ptr EntityProvider::from_database(std::filesystem::path path) {
  return std::make_shared<SQLiteEntityProvider>(path);
}

}  // namespace mx
