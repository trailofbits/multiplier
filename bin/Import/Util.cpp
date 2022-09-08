// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Util.h"

#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <mutex>
#include <system_error>

#ifndef PATH_MAX
# ifdef MAX_PATH
#  define PATH_MAX MAX_PATH
# else
#  define PATH_MAX 1024
# endif
#endif

#if __has_include(<mach-o/dyld.h>)
# include <mach-o/dyld.h>
#else
namespace {
static int _NSGetExecutablePath(char *, uint32_t *) {
  return -1;
}
}  // namespace
#endif

#if __has_include(<libproc.h>)
#include <libproc.h>
#else
namespace {
static int proc_pidpath(int pid, void * buffer, uint32_t  buffersize) {
  return -1;
}
}  // namespace
#endif

#if __has_include(<fcntl.h>)
#include <fcntl.h>
#endif

#if __has_include(<unistd.h>)
#include <unistd.h>
#else
namespace {
static int getpid(void) {
  return -1;
}
static ssize_t readlink(const char *restrict pathname, char *restrict buf,
                        size_t bufsiz) {
  return -1;
}
}  // namespace
#endif

namespace importer {
namespace {

std::optional<std::filesystem::path> BaseExecutablePath(void) {
  static constexpr unsigned kExePathLen = PATH_MAX * 16;

  std::unique_ptr<char[]> raw_path(new char[kExePathLen]);
  memset(raw_path.get(), 0, kExePathLen);

  uint32_t path_len = kExePathLen - 1u;

  if (!_NSGetExecutablePath(raw_path.get(), &path_len)) {
    raw_path[path_len] = '\0';
    return std::filesystem::path(raw_path.get());
  }

  if (!proc_pidpath(getpid(), raw_path.get(), kExePathLen - 1u)) {
    return std::filesystem::path(raw_path.get());
  }

  if (!readlink("/proc/self/exe", raw_path.get(), kExePathLen - 1u)) {
    return std::filesystem::path(raw_path.get());
  }

  if (!readlink("/proc/curproc/file", raw_path.get(), kExePathLen - 1u)) {
    return std::filesystem::path(raw_path.get());
  }

  if (!readlink("/proc/self/path/a.out", raw_path.get(), kExePathLen - 1u)) {
    return std::filesystem::path(raw_path.get());
  }

  if (auto path = getenv("_")) {
    return std::filesystem::path(path);
  }

  return std::nullopt;
}

static std::mutex gRetLock;
static std::optional<std::filesystem::path> gRet;
static bool gHasRet{false};

}  // namespace

std::optional<std::filesystem::path> ExecutablePath(void) {
  std::unique_lock<std::mutex> locker(gRetLock);

  if (gHasRet) {
    return gRet;
  }

  auto base = BaseExecutablePath();
  if (!base) {
    return std::nullopt;
  }

  std::error_code ec;
  auto ret = std::filesystem::absolute(*base, ec);
  if (ec) {
    return std::nullopt;
  }

  gRet.emplace(std::move(ret));
  gHasRet = true;
  return gRet;
}

}  // namespace importer

