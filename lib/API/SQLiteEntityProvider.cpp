// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"
#include "API.h"
#include "Compress.h"
#include "Re2.h"
#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <multiplier/Types.h>
#include <multiplier/SQLiteStore.h>
#include <memory>
#include <multiplier/IndexStorage.h>

namespace mx {

class SQLiteEntityProvider::Impl {
 public:
  sqlite::Connection db;
  IndexStorage storage;

  Impl(std::filesystem::path path) : db(path), storage(db) {}
};

SQLiteEntityProvider::SQLiteEntityProvider(std::filesystem::path path)
  : d(std::make_unique<Impl>(path)) {}
SQLiteEntityProvider::~SQLiteEntityProvider() noexcept {}

void SQLiteEntityProvider::ClearCache() {}

unsigned SQLiteEntityProvider::VersionNumber(void) {
  return d->storage.version_number;
}

unsigned SQLiteEntityProvider::VersionNumber(const Ptr &) {
  return VersionNumber();
}

void SQLiteEntityProvider::VersionNumberChanged(unsigned) {}

FilePathList SQLiteEntityProvider::ListFiles(const Ptr &) {
  FilePathList res;
  d->storage.file_id_to_path.ScanPrefix(
      mx::Empty{},
      [=, &res] (mx::RawEntityId file_id, std::string file_path) {
        res.emplace(file_path, file_id);
        return true;
      });

  return res;
}

std::vector<RawEntityId> SQLiteEntityProvider::ListFragmentsInFile(const Ptr &, RawEntityId file_id) {
  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);

  // Collect the fragments associated with this file.
  d->storage.file_fragment_ids.ScanPrefix(
      file_id,
      [file_id, &fragment_ids] (mx::RawEntityId found_file_id,
                                mx::RawEntityId fragment_id) {
        fragment_ids.push_back(fragment_id);
        return file_id == found_file_id;
      });
  return fragment_ids;
}

std::shared_ptr<const FileImpl> SQLiteEntityProvider::FileFor(const Ptr &self, RawEntityId file_id) {
  std::optional<std::string> maybe_contents =
      d->storage.file_id_to_serialized_file.TryGet(file_id);
  if (!maybe_contents) {
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{
      ((maybe_contents->size() + 7u / 8u)),
      0u};

  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(maybe_contents.value().data()),
      maybe_contents.value().size());

  auto ret = std::make_shared<PackedFileImpl>(file_id, self, contents_reader);
  auto ret_ptr = ret.get();
  return FileImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<const FragmentImpl> SQLiteEntityProvider::FragmentFor(const Ptr &self, RawEntityId fragment_id) {
  std::optional<std::string> maybe_contents =
      d->storage.fragment_id_to_serialized_fragment.TryGet(fragment_id);
  if (!maybe_contents) {
    return {};
  }

  capnp::MessageSize size{maybe_contents->size() + 7u / 8u, 0u};

  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(maybe_contents.value().data()),
      maybe_contents.value().size());

  auto ret = std::make_shared<PackedFragmentImpl>(fragment_id, self, contents_reader);
  auto ret_ptr = ret.get();
  return FragmentImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<WeggliQueryResultImpl> SQLiteEntityProvider::Query(const Ptr &self, const WeggliQuery &query_tree) {
  std::map<unsigned, unsigned> eol_offset_to_line_num;
  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
  for(RawEntityId file_id = kMinEntityIdIncrement;
        file_id < d->storage.next_file_id;
        ++file_id) {
    // Get the contents of the file. We may fail, which is OK, and generally
    // implies a bad file id. There can be small gaps in the file ID space, which
    // otherwise mostly occupies the range `[1, N)`.
    auto maybe_contents = d->storage.GetSerializedFile(file_id);
    if (!maybe_contents) {
      continue;  // Bad file ID. This is expected for the way we get them.
    }

    WithUncompressedMessageImpl(
      "file", maybe_contents.value(),
      [=, this, &eol_offset_to_line_num, &line_results] (capnp::MessageReader &reader) {
    mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
    std::string_view file_contents(file.getData().cStr(),
                                   file.getData().size());

    eol_offset_to_line_num.clear();
    for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
      eol_offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
    }

    query_tree.ForEachMatch(
        file_contents,
        [=, this, &line_results] (const mx::WeggliMatchData &match) -> bool {
          unsigned prev_line = 0;
          for (auto i = match.begin_offset; i < match.end_offset; ++i) {
            auto line_it = eol_offset_to_line_num.upper_bound(i);
            if (line_it != eol_offset_to_line_num.end()) {
              auto line = line_it->second;
              if (line != prev_line) {
                prev_line = line;
                line_results.emplace(file_id, line);
              }
            }
          }
          return true;
        });
    });
  }

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);
  // Convert the file file:line pairs into overlapping fragment IDs.
  for (auto prefix : line_results) {
    d->storage.file_fragment_lines.ScanPrefix(
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

  return std::make_shared<WeggliQueryResultImpl>(query_tree, self, fragment_ids);
}

std::shared_ptr<RegexQueryResultImpl> SQLiteEntityProvider::Query(const Ptr &self, const RegexQuery &regex) {
  std::map<unsigned, unsigned> offset_to_line_num;
  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
  for(RawEntityId file_id = kMinEntityIdIncrement;
        file_id < d->storage.next_file_id;
        ++file_id) {
    // Get the contents of the file. We may fail, which is OK, and generally
    // implies a bad file id. There can be small gaps in the file ID space, which
    // otherwise mostly occupies the range `[1, N)`.
    auto maybe_contents = d->storage.GetSerializedFile(file_id);
    if (!maybe_contents) {
      continue;  // Bad file ID. This is expected for the way we get them.
    }

    WithUncompressedMessageImpl(
        "file", maybe_contents.value(),
        [=, this, &offset_to_line_num, &line_results] (capnp::MessageReader &reader) {
      mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
      std::string_view file_contents(file.getData().cStr(),
                                     file.getData().size());

      offset_to_line_num.clear();
      for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
        offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
      }

      regex.ForEachMatch(
          file_contents,
          [=, this, &line_results] (std::string_view, unsigned begin, unsigned end) -> bool {
            unsigned prev_line = 0;
            for (auto i = begin; i < end; ++i) {
              auto line_it = offset_to_line_num.upper_bound(i);
              if (line_it != offset_to_line_num.end()) {
                auto line = line_it->second;
                if (line != prev_line) {
                  prev_line = line;
                  line_results.emplace(file_id, line);
                }
              }
            }
            return true;
          });
    });
  }

  std::vector<mx::RawEntityId> fragment_ids;
  fragment_ids.reserve(128u);
  // Convert the file file:line pairs into overlapping fragment IDs.
  for (auto prefix : line_results) {
    d->storage.file_fragment_lines.ScanPrefix(
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

  return std::make_shared<RegexQueryResultImpl>(regex, self, fragment_ids);
}

std::vector<RawEntityId> SQLiteEntityProvider::Redeclarations(const Ptr &, RawEntityId id) {
  mx::EntityId eid{id};
  mx::VariantId vid = eid.Unpack();

  if (!std::holds_alternative<mx::DeclarationId>(vid)) {
    return {};
  }

  return d->storage.FindRedeclarations(eid);
}

void SQLiteEntityProvider::FillUses(const Ptr &self, RawEntityId eid,
                                    std::vector<RawEntityId> &redecl_ids_out,
                                    std::vector<RawEntityId> &fragment_ids_out) {
  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  redecl_ids_out = Redeclarations(self, eid);
  for (mx::RawEntityId eid : redecl_ids_out) {
    d->storage.entity_id_use_to_fragment_id.ScanPrefix(
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

void SQLiteEntityProvider::FillReferences(const Ptr &self, RawEntityId eid,
                                          std::vector<RawEntityId> &redecl_ids_out,
                                          std::vector<RawEntityId> &fragment_ids_out) {
  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  redecl_ids_out = Redeclarations(self, eid);
  for (mx::RawEntityId eid : redecl_ids_out) {
    d->storage.entity_id_reference.ScanPrefix(
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
  entity_ids = d->storage.database.QueryEntities(
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
}