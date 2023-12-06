// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
# define MX_PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__ANDROID__) || defined(__linux__) || defined(_POSIX_VERSION)
# define MX_PLATFORM_POSIX
#else
# error "Unsupported platform."
#endif

#if defined(MX_PLATFORM_WINDOWS)
# define MX_DECL_EXPORT __declspec(dllexport)
#elif defined(MX_PLATFORM_POSIX)
# define MX_DECL_EXPORT __attribute__((visibility("default")))
#else
# define MX_DECL_EXPORT
#endif

#if defined(MX_PLATFORM_WINDOWS)
# define MX_DECL_IMPORT __declspec(dllimport)
#else
# define MX_DECL_IMPORT
#endif

#if defined(MX_BUILD)
#  define MX_EXPORT MX_DECL_EXPORT
#else
#  define MX_EXPORT MX_DECL_IMPORT
#endif