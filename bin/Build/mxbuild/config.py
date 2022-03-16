#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

import json
import os
import re
import sys

from functools import reduce
from typing import Dict, Any, Union, List
from collections import namedtuple
from dataclasses import dataclass


from .exc import *
from .util import *

Container = namedtuple("Container", ["name", "tag"])

Compiler = namedtuple("Compiler", ["lang", "version", "path"])

Command = namedtuple("Command", ["command", "directory", "environment"])

Source = namedtuple("Source", ["git", "branch", "directory"])


def escape_special_chars(string):
    return string.translate(
        str.maketrans({" ": r"\ ", "'": r"\'", '"': r"\\", "\\": r"\\"})
    )


def is_lang_c(lang):
    return lang.lower() in ["c", "cc"]


def is_lang_cxx(lang):
    return lang.lower() in ["cpp", "cxx", "c++"]


class VariableManager(object):
    """Variable manager that manages the exported variables in the spec"""

    def __init__(self):
        self._vars: Dict[str, Any] = {}
 
    def keys(self):
        return self._vars.keys()

    def add(self, name: str, value: Any):
        assert "%" not in name
        key_name = f"%{name}%"
        if key_name in self._vars.keys():
            if value != self.get(key_name):
                raise Exception(
                    f"Variable {name} is already defined. The value can't be updated"
                )
        self._vars[key_name] = value

    def get(self, name: str) -> Any:
        assert "%" in name
        return self._vars[name]

    def __setitem__(self, name: str, value: Any):
        self.add(name, value)

    def __getitem__(self, key: str) -> Any:
        return self.get(key)

    def substitute(self, data: str) -> str:
        if "%" in data:
            for name, value in self._vars.items():
                data = data.replace(name, value)
        return data

    def substitute_path(self, path: List[str]) -> str:
        path_str = os.path.join(*path)
        return reduce(
            lambda s, repl: s.replace(*repl),
            [("//", "/"), ("\\\\", "\\")],
            self.substitute(path_str),
        )

    def substitute_env(self, value: Union[str, List[str]]) -> str:
        if isinstance(value, list):
            return self.substitute_path(value)
        else:
            return self.substitute(value)


class Environment(object):
    """Interface class for the environment variable object"""

    def __init__(self, tag: str, bases: Any = None):
        self._bases = bases
        self._tag = tag
        self._vars = {}

    def add_variable(self, key: str, value: str):
        """Add environment variable with key and value to the list"""
        self._vars[key] = value

    def add_variables(self, variables: Dict):
        """Add set of environment variables to the list"""
        self._vars.extend(variables)

    @property
    def variables(self) -> Dict:
        return self._vars

    @property
    def bases(self) -> str:
        return self._bases

    @property
    def variables_as_string(self) -> str:
        vars_string = ""
        for key, value in self._vars.items():
            vars_string += "{}={} ".format(key, escape_special_chars(value))

        # if {CC} environment variable is set; also set BLIGHT_WRAPPED_CC.
        # blight will check the env variable to wrap the compiler
        if "CC" in self._vars.keys():
            vars_string += "BLIGHT_WRAPPED_CC={}".format(self._vars["CC"])

        return vars_string


class Config(object):
    """The interface class for parsing and loading the json
    formatted configuration
    """

    def __init__(self, spec, workspace=None):
        self._spec = AttrDict(spec)
        self._vars = VariableManager()
        self._envs = {}
        self._init_meta_variables()
        self._workspace = workspace

    def _init_meta_variables(self):
        self._vars["root"] = "/"
        self._vars["sysroot"] = "/"
        self._envs["system"] = Environment("system")

    @property
    def arch(self) -> str:
        try:
            return self._spec.arch
        except KeyError:
            print("[!] WARNING! missing target architecture from specification!")

    @property
    def os(self) -> str:
        try:
            return self._spec.os
        except KeyError:
            print("[!] WARNING! missing os from specification!")

    @property
    def name(self) -> str:
        try:
            return self._spec.project
        except KeyError:
            print("[!] WARNING! missing project name")
            return ""

    @property
    def workspace(self) -> str:
        try:
            if self._workspace is not None:
                cwd = self._workspace
            else:
                cwd = self._vars.substitute_path(self._spec.workspace)
            self._vars["workspace"] = cwd
            return cwd
        except AttributeError:
            raise MXBuildException(
                f"Missing workspace directory from the spec : {self._spec}"
            )

    @property
    def container(self) -> Container:
        try:
            return Container(self._spec.container.name, self._spec.container.tag)
        except AttributeError:
            raise MXBuildException(
                f"[!] ERROR: missing container name and tag in the specification '{self._spec}'"
            )

    def __process_compiler(self, compiler) -> List[Compiler]:
        """Process the compiler object provided in the
        specification
        """
        try:
            path = self._vars.substitute_path(compiler.path)
            if "export" in compiler.keys():
                self._vars[compiler.export] = path

            if is_lang_cxx(compiler.lang):
                self._envs["system"].add_variable("CXX", path)

            elif is_lang_c(compiler.lang):
                self._envs["system"].add_variable("CC", path)

            else:
                raise UnhandledKeysException("Unsupported compiler language")

            return Compiler(compiler.lang, compiler.version, path)

        except KeyError:
            raise MXBuildException(
                '[!] WARNING: missing compiler in the specification "{}"'.format(
                    self._spec
                )
            )

    @property
    def compiler(self) -> List[Compiler]:
        try:
            compiler = []
            for item in self._spec.compiler:
                compiler.append(self.__process_compiler(item))
            return compiler
        except AttributeError:
            raise MXBuildException(f"Missing compiler from the spec : {self._spec}")

    @property
    def commands(self) -> List[Command]:
        _ = self.workspace
        _ = self.compiler

        try:
            commands = []
            envs = ""
            for cmds in self._spec.commands:
                directory = self._vars.substitute_path(cmds.directory)
                if (
                    hasattr(cmds, "environment")
                    and cmds.environment in self.envionments.keys()
                ):
                    envs = self.envionments[cmds.environment].variables_as_string
                commands.append(Command(cmds.command, directory, envs))
            return commands
        except AttributeError:
            raise MXBuildException(f"Missing commands from the spec : {self._spec}")

    @property
    def sources(self) -> List[Source]:
        try:
            sources = []
            for src in self._spec.sources:
                sources.append(
                    Source(
                        src.git, src.branch, self._vars.substitute_path(src.directory)
                    )
                )
            return sources
        except AttributeError:
            raise MXBuildException(f"Invalid sources in the spec: {self._spec}")

    @property
    def system_environments(self) -> Dict:
        _ = self.compiler
        _ = self.envionments
        return self._envs["system"].variables

    def __process_targets(self, target_list: List) -> List[str]:
        """Process the target from the specification"""
        targets = []
        for item in target_list:
            targets.append(self._vars.substitute_path(item))
        return targets

    @property
    def targets(self):
        _ = self.workspace
        try:
            return self.__process_targets(self._spec.targets)
        except:
            raise MXBuildException(f"Missing targets from the spec: {self._spec}")

    def _process_environment(self, key, spec):
        if key in self._envs.keys():
            return self._envs[key]

        try:
            bases = spec.bases if hasattr(spec, "bases") else None
            envset = Environment(key, bases)
            for env, value in spec.vars.items():
                envset.add_variable(env, self._vars.substitute_env(value))

            # Look for the bases and inherit the environment variables
            # from the set
            for key in bases:
                if key not in self._spec.environments.keys():
                    continue

                if key in self._envs.keys():
                    base_env.add_variables(self._envs[key].variables)
                else:
                    envset.add_variables(
                        self._process_environment(
                            key, self._spec.environments[key]
                        ).variables
                    )
            return envset

        except KeyError as err:
            raise UnhandledKeysException(
                f"Unhandled keys exception {err.args} {err.message} "
            )

    @property
    def envionments(self):
        _ = self.compiler
        _ = self.workspace

        try:
            for key, value in self._spec.environments.items():
                self._envs[key] = self._process_environment(
                    key, self._spec.environments[key]
                )
            return self._envs
        except:
            raise MXBuildException(
                f"Failed to parse environments field from spec: {self._spec}"
            )

    @property
    def dockerfile(self) -> str:
        try:
            return self._spec.dockerfile
        except AttributeError:
            return ""
