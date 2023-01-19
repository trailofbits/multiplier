// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

struct sqlite3_context;
struct sqlite3_value;

namespace sqlite {
void ZstdCompress(sqlite3_context *ctx, int argc, sqlite3_value **argv);
void ZstdDecompress(sqlite3_context *ctx, int argc, sqlite3_value **argv);

void ZstdCreateCDict(sqlite3_context *ctx, int argc, sqlite3_value **argv);
void ZstdCreateDDict(sqlite3_context *ctx, int argc, sqlite3_value **argv);

void ZstdCreateCCtx(sqlite3_context *ctx, int argc, sqlite3_value **argv);
void ZstdCreateDCtx(sqlite3_context *ctx, int argc, sqlite3_value **argv);

void ZstdCompressDict(sqlite3_context *ctx, int argc, sqlite3_value **argv);
void ZstdDecompressDict(sqlite3_context *ctx, int argc, sqlite3_value **argv);

void ZstdCompressDictCtx(sqlite3_context *ctx, int argc, sqlite3_value **argv);
void ZstdDecompressDictCtx(sqlite3_context *ctx, int argc, sqlite3_value **argv);
}