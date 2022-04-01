#!/usr/bin/env python3
#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

import argparse
import collections
import importlib
import json
import os
import re
import shutil
import subprocess
import sys
import traceback

from mxbuild.config import *
from mxbuild.docker import *

mx_import = "@MX_IMPORT@"


def check_version(version):
    return version.major >= 3 and version.minor >= 5


if check_version(sys.version_info) == False:
    print("[+] Exiting! Please use python version > 3.5")
    exit(0)

DEFAULT_BUILD_ARGS = {
    "UBUNTU_VERSION": "20.04",
    "GCC_VERSION": "10",
    "CLANG_VERSION": "12",
}


def generate_entrypoint(config, workspace_dir):
    """Generate entrypoint script for the docker image"""
    entryfile = workspace_dir + "/entrypoint.sh"
    with open(entryfile, "w") as out_f:
        out_f.write(
            """#!/usr/bin/env bash

"""
        )
        system_envs = config.system_environments
        for var, value in system_envs.items():
            out_f.write(f"export {var}={value}\n")

        out_f.write(
            """
export BLIGHT_WRAPPED_CC="${CC}"
eval $(blight-env --guess-wrapped)
export BLIGHT_ACTIONS="CompileCommand"
export BLIGHT_ACTION_COMPILECOMMAND="output=/tmp/"
"""
        )
        out_f.write(
            """

get_or_update_repo () {
  if [[ ! -d "$1" ]]; then
    git clone "${2}" --branch "$3" --recurse-submodules $1
  else
    pushd "$1"
    git pull
    git checkout "$3"
    popd
  fi
}

execute () {
  local cmd=$1
  shift
  if [ -z "$@" ]; then
    bash -c "eval $(blight-env --guess-wrapped); ${cmd}"
  else
    bash -c "${@}; eval $(blight-env --guess-wrapped); ${cmd}"
  fi
}

execute_in_dir () {
  local cwd=$1
  shift
  local cmd=$1
  shift
  if [ -z "$@" ]; then
    bash -c "cd ${cwd}; eval $(blight-env --guess-wrapped); ${cmd}"
  else
    bash -c "${@}; cd ${cwd}; eval $(blight-env --guess-wrapped); ${cmd}"
  fi
}


"""
        )
        source_list = config.sources
        for source in source_list:
            out_f.write("PROJECT_NAME={}\n".format(source.directory))
            out_f.write("PROJECT_REPO={}\n".format(source.git))
            out_f.write("PROJECT_BRANCH={}\n".format(source.branch))
            out_f.write(
                'get_or_update_repo "${PROJECT_NAME}" "${PROJECT_REPO}" "${PROJECT_BRANCH}"'
            )
            out_f.write("\n\n")

        commands = config.commands
        for sub_commands in commands:
            out_f.write("WSDIR={}\n".format(sub_commands.directory))
            if sub_commands.environment != "":
                out_f.write('ENVS="export {}"\n'.format(sub_commands.environment))
            else:
                out_f.write("ENVS=\n")
            out_f.write(
                'CMDS="{}"\n'.format(
                    " ".join(str(item) for item in sub_commands.command)
                )
            )
            if sub_commands.directory:
                out_f.write('execute_in_dir "${WSDIR}" "${CMDS}" "${ENVS}"')
            else:
                out_f.write('execute "${CMDS}" "${ENVS}"')
            out_f.write("\n\n")

    print("[x] Finish generating entrypoint file")


def install_blight_local(config, workspace):
    with open("/tmp/blight.sh", "w") as out_f:
        out_f.write(
            """#!/usr/bin/env bash

get_or_update_repo () {
  if [[ ! -d "$1" ]]; then
    git clone "${2}" --branch "$3" --recurse-submodules $1
  else
    pushd "$1"
    git pull
    git checkout "$3"
    popd
  fi
}

PROJECT_NAME="blight"
PROJECT_REPO="https://github.com/trailofbits/blight.git"
PROJECT_BRANCH="kumarak/embed_compile_command"

get_or_update_repo \"${PROJECT_NAME}\" \"${PROJECT_REPO}\" \"${PROJECT_BRANCH}\"
cd blight && sudo python3 setup.py install

"""
        )
    cmd = ["bash", "/tmp/blight.sh"]
    execute_process(cmd, {})


def mx_import_local(config, workspace):
    """Import the target binaries after compilation"""
    for target in config.targets:
        cmd = [mx_import, "--path", workspace + "/" + target]
        execute_process(cmd, {})


def build_and_run_container(config, workspace):
    """Build the docker image from the dockerfile and
    execute the build commands in the container
    """
    container = config.container
    docker = DockerContainer(container.name, container.tag)
    docker.patch_dockerfile(config, workspace)
    docker.build_images(workspace, DEFAULT_BUILD_ARGS, {})

    generate_entrypoint(config, workspace)
    cmd = ["bash", "entrypoint.sh"]
    docker.execute_commands(cmd, workspace, {})


def build_and_run_local(config, workspace):
    """Build container from the configuration"""
    entryfile = workspace + "/entrypoint.sh"
    install_blight_local(config, workspace)
    generate_entrypoint(config, entryfile, workspace)
    execute_process(["bash", entryfile], {})


def create_build_setup(project_spec, workspace, local_build, index=False):
    """Create the docker setup for building the instrumented version
    of the project.
    """
    try:
        with open(project_spec) as fd:
            config = Config(json.load(fd))
            print("[+] Compiling project {}".format(config.name))
            if local_build:
                build_and_run_local(config, workspace)
                if index:
                    mx_import_local(config, workspace)
            else:
                build_and_run_container(config, workspace)

    except FileNotFoundError:
        print(traceback.format_exc())
        sys.exit('[!] ERROR: missing specification file "{}"'.format(project_spec))


def parse_args(args):
    """Function to parse the arguments and set the project
    name and workspace
    """
    parser = argparse.ArgumentParser(
        description="Build project inside " "vspell-container"
    )

    parser.add_argument("--workspace", required=True, help="Workspace path")

    parser.add_argument("--project", required=True, help="Project JSON spec")

    parser.add_argument("--build_locally", dest="build_local", action="store_true")
    parser.set_defaults(build_local=False)

    parser.add_argument("--also_import", dest="also_import", action="store_true")
    parser.set_defaults(also_import=False)

    return parser.parse_args(args)


def main():
    """main function for building the project from the
    specification provided in the JSON format
    """
    args = parse_args(sys.argv[1:])

    if args.project:
        if not os.path.isfile(args.project):
            sys.exit(
                '[!] ERROR: can\'t find the project specification "{}"'.format(
                    args.project
                )
            )

    if args.workspace:
        if not os.path.isdir(args.workspace):
            print(
                "[!] WARNING: can't find the workspace. Setting the script directory as workspace"
            )
            args.workspace = SCRIPT_DIR

    print("[+] Going to build project {}".format(args.project))

    create_build_setup(args.project, args.workspace, args.build_local, args.also_import)


if __name__ == "__main__":
    main()
