#
# Copyright (c) 2021-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# Common settings
set(CPACK_PACKAGE_DESCRIPTION "IRENE")
set(CPACK_PACKAGE_NAME "IRENE")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VENDOR "Trail of Bits")
set(CPACK_PACKAGE_CONTACT "peter@trailofbits.com")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://www.trailofbits.com")

# DEB settings
set(CPACK_DEBIAN_PACKAGE_PRIORITY "extra")
set(CPACK_DEBIAN_PACKAGE_SECTION "default")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "${CPACK_PACKAGE_HOMEPAGE_URL}")

# RPM settings
set(CPACK_RPM_PACKAGE_RELEASE "${CPACK_PACKAGE_VERSION}")
set(CPACK_RPM_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_PACKAGE_DESCRIPTION "${CPACK_PACKAGE_DESCRIPTION}")
set(CPACK_RPM_PACKAGE_GROUP "default")
set(CPACK_RPM_PACKAGE_LICENSE "AGPL 3")

# ZIP settings
if("${CPACK_GENERATOR}" STREQUAL "ZIP")
  set(CPACK_SET_DESTDIR ON)
endif()

include("CPack")
