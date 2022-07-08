// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Configuration.h"

#include "CodeTheme.h"

#include <cstdlib>

#if __has_include(<mach-o/dyld.h>)
# include <mach-o/dyld.h>
#else
int _NSGetExecutablePath(char *, uint32_t *) {
  return -1;
}
#endif

namespace mx::gui {
namespace {

static char gExePath[PATH_MAX * 8];

static void LocateIndexerAndImporter(mx::gui::Configuration &config) {
  uint32_t path_len = sizeof(gExePath) - 1u;
  memset(gExePath, 0, path_len + 1u);

  if (_NSGetExecutablePath(&(gExePath[0]), &path_len)) {
    if (auto path = getenv("_")) {
      auto env_path_len = static_cast<uint32_t>(strlen(path));
      memset(gExePath, 0, path_len + 1u);
      memcpy(gExePath, path, std::min(env_path_len, path_len));
    }
  }

  if (strstr(gExePath, ".app/Contents/MacOS/Multiplier")) {
    std::filesystem::path exe_path(gExePath);
    auto contents_path = exe_path.parent_path().parent_path();
    auto indexer_path = contents_path / "bin" / "mx-index";
    auto importer_path = contents_path / "bin" / "mx-import";

    std::error_code ec;
    std::ignore = std::filesystem::status(indexer_path, ec);
    if (ec) {
      return;
    }

    std::ignore = std::filesystem::status(importer_path, ec);
    if (ec) {
      return;
    }

    config.indexer_exe_path = std::move(indexer_path);
    config.importer_exe_path = std::move(importer_path);
  }

  // TODO(pag): Do something with this for Linux, perhaps. See:
  //            https://stackoverflow.com/a/1024937
}

} // namespace
Configuration::Configuration(void)
    : theme(&(CodeTheme::DefaultTheme())) {
  LocateIndexerAndImporter(*this);
}

}  // namespace mx::gui
