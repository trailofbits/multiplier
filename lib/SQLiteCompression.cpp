// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteCompression.h"

#include <sqlite3.h>
#include <zstd.h>
#include <vector>
#include <memory>

namespace sqlite {
void ZstdCompress(sqlite3_context *sql_ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);

    ZSTD_CCtx *cctx = static_cast<ZSTD_CCtx*>(sqlite3_user_data(sql_ctx));

    auto bound = ZSTD_compressBound(blob_size);
    std::vector<char> res;
    res.resize(bound);

    auto result_size =
        ZSTD_compressCCtx(cctx, res.data(), bound, blob_data, blob_size, ZSTD_maxCLevel());
    if(ZSTD_isError(result_size)) {
        sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
        return;
    }

    sqlite3_result_blob(sql_ctx, res.data(), result_size, SQLITE_TRANSIENT);
}

void ZstdDecompress(sqlite3_context *sql_ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);

    ZSTD_DCtx *dctx = static_cast<ZSTD_DCtx*>(sqlite3_user_data(sql_ctx));

    auto decompressed_size = ZSTD_getFrameContentSize(blob_data, blob_size);
    std::vector<char> res;
    res.resize(decompressed_size);

    auto result_size =
        ZSTD_decompressDCtx(dctx, res.data(), decompressed_size, blob_data, blob_size);
    if(ZSTD_isError(result_size)) {
        sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
        return;
    }

    sqlite3_result_blob(sql_ctx, res.data(), result_size, SQLITE_TRANSIENT);
}

static constexpr const char *kCDictId = "ZSTD_CDict";
static constexpr const char *kDDictId = "ZSTD_DDict";

void ZstdCreateCDict(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);

    auto dict = ZSTD_createCDict(blob_data, blob_size, ZSTD_maxCLevel());
    if(!dict) {
        sqlite3_result_error(ctx, "Couldn't create dictionary", -1);
        return;
    }
    sqlite3_result_pointer(ctx, dict, kCDictId,
        [](void *dict) { ZSTD_freeCDict(static_cast<ZSTD_CDict *>(dict)); });
}

void ZstdCreateDDict(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);

    auto dict = ZSTD_createDDict(blob_data, blob_size);
    if(!dict) {
        sqlite3_result_error(ctx, "Couldn't create dictionary", -1);
        return;
    }
    sqlite3_result_pointer(ctx, dict, kDDictId,
        [](void *dict) { ZSTD_freeDDict(static_cast<ZSTD_DDict *>(dict)); });
}

void ZstdCompressDict(sqlite3_context *sql_ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);
    auto dict =
        static_cast<const ZSTD_CDict*>(sqlite3_value_pointer(argv[1], kCDictId));

    ZSTD_CCtx *cctx = static_cast<ZSTD_CCtx*>(sqlite3_user_data(sql_ctx));

    auto bound = ZSTD_compressBound(blob_size);
    std::vector<char> res;
    res.resize(bound);

    auto result_size =
        ZSTD_compress_usingCDict(cctx, res.data(), bound, blob_data, blob_size, dict);
    if(ZSTD_isError(result_size)) {
        sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
        return;
    }

    sqlite3_result_blob(sql_ctx, res.data(), result_size, SQLITE_TRANSIENT);
}

void ZstdDecompressDict(sqlite3_context *sql_ctx, int argc, sqlite3_value **argv) {
    auto blob_data = sqlite3_value_blob(argv[0]);
    auto blob_size = sqlite3_value_bytes(argv[0]);
    auto dict =
        static_cast<const ZSTD_DDict*>(sqlite3_value_pointer(argv[1], kDDictId));

    ZSTD_DCtx *dctx = static_cast<ZSTD_DCtx*>(sqlite3_user_data(sql_ctx));

    auto decompressed_size = ZSTD_getFrameContentSize(blob_data, blob_size);
    std::vector<char> res;
    res.resize(decompressed_size);

    auto result_size =
        ZSTD_decompress_usingDDict(dctx, res.data(), decompressed_size, blob_data, blob_size, dict);
    if(ZSTD_isError(result_size)) {
        sqlite3_result_error(sql_ctx, ZSTD_getErrorName(result_size), -1);
        return;
    }

    sqlite3_result_blob(sql_ctx, res.data(), result_size, SQLITE_TRANSIENT);
}
}