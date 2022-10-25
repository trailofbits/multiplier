// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"
#include "API.h"
#include "multiplier/Index.h"
#include "multiplier/Types.h"
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
        DCHECK_NE(file_id, mx::kInvalidEntityId);
        DCHECK(!file_path.empty());
        res.insert({file_path, file_id});
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
        DCHECK_EQ(file_id, found_file_id);
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

std::shared_ptr<WeggliQueryResultImpl> SQLiteEntityProvider::Query(const Ptr &, const WeggliQuery &) {
  // TODO(frabert)
  return {};
}

std::shared_ptr<RegexQueryResultImpl> SQLiteEntityProvider::Query(const Ptr &, const RegexQuery &) {
  // TODO(frabert)
  return {};
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