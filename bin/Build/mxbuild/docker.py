#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

import docker
import importlib
import json
import os
import re
import subprocess
import sys

from .config import *

PY_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

sys.path.insert(0, PY_SCRIPT_DIR)

BLIGHT_PATCH = """

####################################################################
# Patched with blight #
####################################################################

RUN git clone https://github.com/trailofbits/blight.git && \\
    cd blight && \\
    git checkout kumarak/embed_compile_command && \\
    sudo python3 setup.py install

RUN echo "\\n\\n" \\
         "eval \$(blight-env --guess-wrapped)\\n" \\
         "export BLIGHT_WRAPPED_CC=clang\\n" \\
         "export BLIGHT_ACTIONS=\"CompileCommand\"\\n" \\
         "export BLIGHT_ACTION_COMPILECOMMAND=\"output=/tmp/\"\\n" >> /home/vspell/.bashrc

CMD [bash]

####################################################################
"""

docker_build_cmd = ["sudo", "docker", "build"]
docker_run_cmd = ["docker", "run"]


def execute_process(cmd, my_env={}):
    """Execute the command in a subprocess after setting
    the enviornment variables.
    """
    new_env = os.environ.copy()
    new_env.update(my_env)

    with subprocess.Popen(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        universal_newlines=True,
        bufsize=1,
        env=new_env,
    ) as process:
        for line in process.stdout:
            print("    {}".format(line), end="\r")
        return_code = process.wait()


class DockerContainer(object):
    """Class for creating docker images and run the
    commands inside the container"""

    def __init__(self, name, tag):
        self._name = name
        self._tag = tag
        self._image = "{}:{}".format(name, tag)

    def _image_exists(self, name):
        """Check if the docker image exist locally"""
        for image in self.list_images():
            if name in image.tags:
                return True
        return False

    def build_images(self, workspace, args, my_env={}):
        """Build the docker image from the given dockerfile."""
        build_images_cmd = docker_build_cmd

        build_images_cmd.extend(["-f", PY_SCRIPT_DIR + "/Dockerfile"])
        build_images_cmd.extend(
            ["--build-arg", "UBUNTU_VERSION={}".format(args["UBUNTU_VERSION"])]
        )
        build_images_cmd.extend(
            ["--build-arg", "GCC_VERSION={}".format(args["GCC_VERSION"])]
        )
        build_images_cmd.extend(
            ["--build-arg", "CLANG_VERSION={}".format(args["CLANG_VERSION"])]
        )
        build_images_cmd.extend(["-t", "{}:{}".format(self._name, self._tag)])
        build_images_cmd.extend([workspace])
        execute_process(build_images_cmd, my_env)

    def execute_commands(self, cmd, workspace, new_env):
        """Execute commands inside container"""

        run_containers_cmd = docker_run_cmd
        run_containers_cmd.extend(["-v", "{}:/home/vspell/src".format(workspace)])
        run_containers_cmd.extend(["{}:{}".format(self._name, self._tag)])
        run_containers_cmd.extend(cmd)
        print(run_containers_cmd)
        execute_process(run_containers_cmd, new_env)

    def is_dockerfile_patched(self, dockerfile):
        """Check if the dockerfile is patched"""
        with open(dockerfile, "r") as file:
            content = file.read()
            return re.search("# Patched with blight #", content)

        return False

    def patch_dockerfile(self, config, workspace_dir):
        """Patch the dockerfile to wrap and instrument the
        toolchains
        """
        if config.dockerfile != "":
            dockerfile = config.dockerfile
        else:
            dockerfile = PY_SCRIPT_DIR + "/Dockerfile"

        try:
            if not self.is_dockerfile_patched(dockerfile):
                docker_f = open(dockerfile, "a")
                docker_f.write(BLIGHT_PATCH)

        except FileNotFoundError:
            print("[!] Missing Dockerfile in workspace")
