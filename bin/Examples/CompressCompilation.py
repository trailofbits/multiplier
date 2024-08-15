# Copyright 2024, Peter Goodman. All rights reserved.

import argparse
import os.path
import pathlib
import tarfile
import json

import multiplier as mx


def make_compile_commands(comp: mx.frontend.Compilation, root_path: pathlib.PurePath):
    with open(str(root_path / "compile_commands.json"), "w") as cc:
        cc.write(json.dumps([ {
            "directory": str(comp.working_directory),
            "file": str(comp.main_source_file_path),
            "arguments": [arg for arg in comp.arguments]
        }], indent="  "))


def harness(comp: mx.frontend.Compilation, root_path: pathlib.PurePath):
    for file in comp.files:
        for path in file.paths:
            nested = root_path / pathlib.PurePath("." + str(path))
            parent_dir = nested.parent
            os.makedirs(parent_dir, exist_ok=True)
            with open(str(nested), "w") as file_copy:
                file_copy.write(file.data)

    make_compile_commands(comp, root_path)

    with open(str(root_path / "builtin-macros.h"), "w") as macros:
        index = mx.Index.containing(comp)
        for macro in mx.frontend.DefineMacroDirective.IN(index):
            file = mx.frontend.File.containing(macro)
            if not file:
                macros.write(" ".join(t.data for t in macro.generate_use_tokens))
                macros.write('\n')

    with tarfile.open(str(root_path) + ".tar.gz", "w:gz") as tar:
        tar.add(str(root_path), arcname=root_path.name)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Extract and compress a compilation")
    parser.add_argument('--db', type=str,
                        required=True,
                        help="Path to mx-index-produced database")
    parser.add_argument('--entity_id', type=int, required=True,
                        help="Id of the entity to harness")
    parser.add_argument('--working_dir', type=str, required=True,
                        help="The working directory into which to place files that will be compresed")

    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    if entity := index.entity(args.entity_id):
        if comp := mx.frontend.Compilation.containing(entity):
            if not os.path.isdir(args.working_dir):
                os.makedirs(args.working_dir, exist_ok=True)

            harness(comp, pathlib.PosixPath(args.working_dir))
        else:
            print(f"Could not find compilation containing entity {entity.id}")
    else:
        print(f"Invalid entity ID {args.entity_id}")
