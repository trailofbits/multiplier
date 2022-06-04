// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include "Module.h"
#include "VirtualTable.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {
struct module_vtab {
  sqlite3_vtab base;
  std::unique_ptr<VirtualTable> tab;
};

struct module_vtab_cur {
  sqlite3_vtab_cursor base;
  std::unique_ptr<VirtualTableCursor> cur;
};

static int module_destroy(sqlite3_vtab *pVtab) {
  delete (module_vtab *)pVtab;
  return SQLITE_OK;
}

static int module_create(sqlite3 *db, void *pAux, int argc,
                         const char *const *argv, sqlite3_vtab **ppVTab,
                         char **pzErr) {
  auto mod = (Module *)pAux;
  auto res = mod->Create(db, {argv, argv + argc});
  if (res.Succeeded()) {
    auto vtab = new module_vtab();
    vtab->tab = std::move(res.TakeValue());
    *ppVTab = &(vtab->base);
  } else {
    auto err = res.Error();
    auto errlen = err.size();
    *pzErr = static_cast<char *>(sqlite3_malloc64(errlen + 1));
    if (*pzErr == nullptr) {
      return SQLITE_ERROR;
    }

    auto c_str = err.c_str();
    std::copy(c_str, c_str + errlen + 1, *pzErr);
    return SQLITE_ERROR;
  }

  return SQLITE_OK;
}

static int module_open(sqlite3_vtab *pVTab, sqlite3_vtab_cursor **pp_cursor) {
  auto table = (module_vtab *)pVTab;
  auto res = table->tab->Open();
  if (res.Succeeded()) {
    auto cur = new module_vtab_cur();
    cur->cur = std::move(res.TakeValue());
    *pp_cursor = &(cur->base);
    return SQLITE_OK;
  } else {
    return res.Error();
  }
}

static int module_close(sqlite3_vtab_cursor *pVCur) {
  delete (module_vtab_cur *)pVCur;
  return SQLITE_OK;
}

static int module_eof(sqlite3_vtab_cursor *base) {
  auto cur = (module_vtab_cur *)base;
  return cur->cur->Eof();
}

static int module_next(sqlite3_vtab_cursor *base) {
  auto cur = (module_vtab_cur *)base;
  return cur->cur->Next();
}

static int module_column(sqlite3_vtab_cursor *base, sqlite3_context *ctx,
                         int idxCol) {
  auto cur = (module_vtab_cur *)base;
  return cur->cur->Column(ctx, idxCol);
}

static int module_rowid(sqlite3_vtab_cursor *base, sqlite3_int64 *rowid) {
  auto cur = (module_vtab_cur *)base;
  auto res = cur->cur->RowId();
  if (res.Succeeded()) {
    *rowid = res.Value();
    return SQLITE_OK;
  } else {
    return res.Error();
  }
}

static int module_filter(sqlite3_vtab_cursor *base, int idxNum,
                         const char *idxStr, int argc, sqlite3_value **argv) {
  auto cur = (module_vtab_cur *)base;
  return cur->cur->Filter(idxNum, idxStr, {argv, argv + argc});
}

static int module_best_index(sqlite3_vtab *base, sqlite3_index_info *pIdxInfo) {
  auto tab = (module_vtab *)base;
  return tab->tab->BestIndex(pIdxInfo);
}

static int module_find_function(sqlite3_vtab *base, int nArg, const char *zName,
                                void (**pxFunc)(sqlite3_context *, int,
                                                sqlite3_value **),
                                void **ppArg) {
  auto tab = (module_vtab *)base;
  return tab->tab->FindFunction(nArg, zName, pxFunc, ppArg);
}

static sqlite3_module module_vtbl = {
    0,                    /* iVersion      */
    module_create,        /* xCreate       */
    module_create,        /* xConnect      */
    module_best_index,    /* xBestIndex    */
    module_destroy,       /* xDisconnect   */
    module_destroy,       /* xDestroy      */
    module_open,          /* xOpen         */
    module_close,         /* xClose        */
    module_filter,        /* xFilter       */
    module_next,          /* xNext         */
    module_eof,           /* xEof          */
    module_column,        /* xColumn       */
    module_rowid,         /* xRowid        */
    nullptr,              /* xUpdate       */
    nullptr,              /* xBegin        */
    nullptr,              /* xSync         */
    nullptr,              /* xCommit       */
    nullptr,              /* xRollback     */
    module_find_function, /* xFindFunction */
    nullptr,              /* xRename       */
    nullptr,              /* xSavepoint    */
    nullptr,              /* xRelease      */
    nullptr               /* xRollbackto   */
};

#define CHECK_ERR(e)                                                           \
  if ((err = (e)) != SQLITE_OK)                                                \
    return err;

static void delete_module(void *udata) { delete (Module *)udata; }

int VirtualTable::FindFunction(int nArg, const std::string &name,
                               void (**pxFunc)(sqlite3_context *, int,
                                               sqlite3_value **),
                               void **ppArg) {
  return 0;
}

int Module::Register(sqlite3 *db, const std::string &name) {
  int err;
  CHECK_ERR(sqlite3_create_module_v2(db, name.c_str(), &module_vtbl, this,
                                     delete_module));
  return SQLITE_OK;
}
}; // namespace sqlite_bridge