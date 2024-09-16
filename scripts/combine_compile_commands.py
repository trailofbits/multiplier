#
# Copyright (c) 2021-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# find ./ -type f -name '*.json' ! -name 'compile_commands.json' ! -name 'manifest.json' ! -name 'build-request.json' | xargs python3 ./combine_json_files.py >compile_commands.json

import json
import os
import sys

if __name__ == "__main__":
  parts = []
  for file_name in sys.argv[1:]:
    if not file_name.endswith(".json"):
      continue
    if not os.path.isfile(file_name):
      continue
    with open(file_name, "r") as open_file:
      parts.append(open_file.read().strip(" \r\n\t[],"))

  all_data = "[{}]".format(",\n".join(parts))
  commands = json.loads(all_data)
  filtered_commands = []
  for command in commands:
    if "file" in command:
      input_file = command["file"].lower()
      if input_file.endswith(".i") or \
         input_file.endswith(".ii") or \
         input_file.endswith(".ir") or \
         input_file.endswith(".bc") or \
         input_file.endswith(".s"):
        continue
    filtered_commands.append(command)

  print(json.dumps(filtered_commands, indent=2))