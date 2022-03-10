#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#


class MXBuildException(Exception):
    pass


class UnhandledKeysException(MXBuildException):
    def __init__(self, msg, ty=None):
        super(UnhandledKeysException, self).__init__(msg)
        self.type = ty
