// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteCompression.h"

#include <sqlite3.h>
#include <zstd.h>
#include <memory>

namespace sqlite {
namespace {
static constexpr const char *kCDictId = "ZSTD_CDict";
static constexpr const char *kDDictId = "ZSTD_DDict";

static void DeleteCharArray(void *arr) {
  delete [] reinterpret_cast<char *>(arr);
}

static void FreeZStdDict(void *dict) {
  ZSTD_freeCDict(reinterpret_cast<ZSTD_CDict *>(dict));
}

}  // namespace

void ZstdCompress(sqlite3_context *sql_ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));

  ZSTD_CCtx *cctx = static_cast<ZSTD_CCtx*>(sqlite3_user_data(sql_ctx));

  auto bound = ZSTD_compressBound(blob_size);
  std::unique_ptr<char[]> res(new char[bound]);

  auto result_size =
      ZSTD_compressCCtx(cctx, res.get(), bound, blob_data, blob_size,
                        ZSTD_maxCLevel());
  if (ZSTD_isError(result_size)) {
    sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
    return;
  }

  sqlite3_result_blob64(sql_ctx, res.release(), result_size, DeleteCharArray);
}

void ZstdDecompress(sqlite3_context *sql_ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));

  ZSTD_DCtx *dctx = static_cast<ZSTD_DCtx *>(sqlite3_user_data(sql_ctx));

  auto bound = ZSTD_getFrameContentSize(blob_data, blob_size);
  std::unique_ptr<char[]> res(new char[bound]);

  auto result_size =
      ZSTD_decompressDCtx(dctx, res.get(), bound, blob_data, blob_size);

  if (ZSTD_isError(result_size)) {
    sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
    return;
  }

  sqlite3_result_blob64(sql_ctx, res.release(), result_size, DeleteCharArray);
}

void ZstdCreateCDict(sqlite3_context *ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));

  auto dict = ZSTD_createCDict(blob_data, blob_size, ZSTD_maxCLevel());
  if (!dict) {
    sqlite3_result_error(ctx, "Couldn't create dictionary", -1);
    return;
  }
  sqlite3_result_pointer(ctx, dict, kCDictId, FreeZStdDict);
}

void ZstdCreateDDict(sqlite3_context *ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));

  auto dict = ZSTD_createDDict(blob_data, blob_size);
  if (!dict) {
    sqlite3_result_error(ctx, "Couldn't create dictionary", -1);
    return;
  }
  sqlite3_result_pointer(ctx, dict, kDDictId, FreeZStdDict);
}

void ZstdCompressDict(sqlite3_context *sql_ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));
  auto dict = static_cast<const ZSTD_CDict*>(
      sqlite3_value_pointer(argv[1], kCDictId));

  ZSTD_CCtx *cctx = static_cast<ZSTD_CCtx*>(sqlite3_user_data(sql_ctx));

  auto bound = ZSTD_compressBound(blob_size);
  std::unique_ptr<char[]> res(new char[bound]);

  auto result_size =
      ZSTD_compress_usingCDict(cctx, res.get(), bound, blob_data, blob_size,
                               dict);
  if (ZSTD_isError(result_size)) {
    sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
    return;
  }

  sqlite3_result_blob64(sql_ctx, res.release(), result_size, DeleteCharArray);
}

void ZstdDecompressDict(sqlite3_context *sql_ctx, int, sqlite3_value **argv) {
  auto blob_data = sqlite3_value_blob(argv[0]);
  auto blob_size = static_cast<unsigned>(sqlite3_value_bytes(argv[0]));
  auto dict = static_cast<const ZSTD_DDict*>(
      sqlite3_value_pointer(argv[1], kDDictId));

  ZSTD_DCtx *dctx = static_cast<ZSTD_DCtx *>(sqlite3_user_data(sql_ctx));

  auto bound = ZSTD_getFrameContentSize(blob_data, blob_size);
  std::unique_ptr<char[]> res(new char[bound]);

  auto result_size = ZSTD_decompress_usingDDict(
      dctx, res.get(), bound, blob_data, blob_size, dict);
  if (ZSTD_isError(result_size)) {
    sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
    return;
  }

  sqlite3_result_blob64(sql_ctx, res.release(), result_size, DeleteCharArray);
}

}  // namespace indexer
