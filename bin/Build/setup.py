#!/usr/bin/env python3

#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

import setuptools
import sys
import os

setuptools.setup(
    name="mxbuild",
    version="1.0.0",
    description="",
    author="",
    author_email="",
    url="",
    license="AGPL 3",
    data_files=[("mxbuild", ["mxbuild/build_images.sh"])],
    py_modules=[
        "mxbuild.__init__",
        "mxbuild.config",
        "mxbuild.docker",
        "mxbuild.exc" "mxbuild.util",
    ],
)
