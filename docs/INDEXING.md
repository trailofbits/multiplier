# Indexing code

## Basic usage

Once installed, a build of a codebase can be indexed by the `mx-index` binary.
Indexing produces a [SQLite](https://sqlite.org/) database, whose path is
specified using the `--db` command-line option. If you omit `--db` then the
index is stored in `./mx-index.db`.

Indexing is computationally expensive, and could take up to 30x for C code and
300x for C++ code the time to build / compile the target codebase. Because of
the nature of the indexing workload, `mx-index` also creates a
[RocksDB](https://rocksdb.org/) key-value store, which is stored in the
directory specified by `--workspace`. If you don't specify a workspace
directory, then `./mx-workspace` will be used.

**Pro-tip:** Multiple independent builds can be stored in the same index
database. One way to do this is to accumulate all build information into a
single `compile_commands.json` file. Another way to do this is to run `mx-index`
once for each independent `compile_commands.json`, and share the same `--db` and
`--workspace`. Note that only one `mx-index` can operate on a given workspace at
a time.

**Pro-tip:** Once you're done indexing, you can take the SQLite database path
specified by `--database` and discard the rest. That is, you can delete the
workspace directory specified by `--workspace`. The SQLite database can be
shared with anyone who has the SDK or GUI.

**Pro-tip:** Use the optional `--env` command-line argument to specify a path to
a text file containing saved environment variables as of the start of the build
of your target codebase. For example, prior to running make all on your target,
save the environment variables with `env > env_vars.txt`. This will help
Multiplier more accurately reproduce the original build environment from the
compile commands.

```shell
/opt/multiplier/bin/mx-index \
      --db /path/to/database.db \                 # Output index database.
      --target /path/to/compile_commands.json \   # Compile commands
      --workspace /path/to/workspace \            # Workspace directory
      --env /path/to/environment-vars \           # Saved environment variables
      --show_progress                             # Show progress indicators
```

**Note:** You generally should run `mx-index` on the same machine / environment
as the build. `mx-index` will invoke the original build compiler in the original
build directories as an oracle to gather relevant information. If you aren't
using the original build environemnt, then you'll likely need to modify paths
in your `compile_commands.json` files.

**Pro-tip:** If your target program is small (e.g. fewer compile commands than
your machine has cores), then you should expect indexing time to take longer.
You may be able to mitigate this problem by duplicating the compile commands,
and modifying each duplicate to be slightly different, e.g. the first can have
`-DMX_GO_BRR=0`, the second can have `-DMX_GO_BRR=1`, the third `-DMX_GO_BRR=2`,
etc. These apparently useless macro definitions in the duplicate compile
commands introduce enough difference for mx-index to treat each compile command
as different.

**Note:** `mx-index` may report errors as it indexes. This is "fine" as long as
it finishes and exits normally (as opposed to crashing). If you're concerned
about some of the reported errors, then please [file an issue](https://github.com/trailofbits/multiplier/issues/new).

## Compatible Builds
As mentioned above, Multiplier indexes builds of codebases. More specifically,
Multiplier is currently limited to [Clang](https://clang.llvm.org/) builds of a
codebase. For the best results, configure your build with a version of Clang. On
macOS, we recommend using AppleClang, i.e. `/usr/bin/clang`, and *not*
[Homebrew](https://brew.sh/) Clang. On Linux, use whatever Clang gets the job
done.

We have made some progress on more faithfully reproducing GCC-based builds
out-of-the-box, but more work is needed. We have not yet implemented support for
`clang-cl`-based Windows builds. If supporting a specific build system is
valuable to you, then please reach out and let us know!

## Best Effort Builds
Sometimes you just can't build your target with Clang. There are a few
remediations. One is to modify `compile_commands.json` directly, replacing all
uses of a compiler like `gcc` with `clang`. If this works then call it a win!
This might, however, result in Clang reporting a lot of errors about unsupported
command-line options, and that could be bad. With effort, this may be fixable
(e.g. by removing the relevant command-line options from the
`compile_commands.json`.

If this doesn't work then a hacky approach around this problem is to formulate a
"best effort" environment for Multiplier to be able to succeed. Start by
producing your `compile_commands.json` as you normally would.

Let's suppose it is for a GCC-based build. The next step is to capture the
relevant environment variables, i.e. using `env > env_vars.txt`. Then, using any
available Clang installation, invoke the following:

```shell
clang -x c -fsyntax-only -v - </dev/null
```

The output of this command will look something like the following:

```
Ubuntu clang version 15.0.7
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/10
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12
Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12
Candidate multilib: .;@m64
Selected multilib: .;@m64
 (in-process)
 "/usr/lib/llvm-15/bin/clang" -cc1 ... -resource-dir /usr/lib/llvm-15/lib/clang/15.0.7 ... -x c -
clang -cc1 version 15.0.7 based upon LLVM 15.0.7 default target x86_64-pc-linux-gnu
ignoring nonexistent directory "/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../x86_64-linux-gnu/include"
ignoring nonexistent directory "/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/llvm-15/lib/clang/15.0.7/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
```

The important paths to extract from the above are the resource directory and
the include directories.

 * `resource-dir`: `/usr/lib/llvm-15/lib/clang/15.0.7`
 * `include-dir1`: `/usr/lib/llvm-15/lib/clang/15.0.7/include`
 * ...
 * `include-dirN`: `/usr/include`

Open the previously saved `env_vars.txt` and modify it, adding or modifying the
existing environment variables as follows:

```
LIBRARY_PATH=<resource-dir>
CPATH="-resource-dir <resource-dir>:<include-dir1>:...:<include-dirN>"
CPPFLAGS="-nostdinc -nobuiltininc"
```

Yes, that is a command-line option embedded into `CPATH`. This is really just a
backdoor to sneak information to some string matching code in
[PASTA](https://github.com/trailofbits/pasta) (a Clang wrapper used by
Multiplier) that tries to identify resource directories. For the above example,
we would input the following:

```
LIBRARY_PATH=/usr/lib/llvm-15/lib/clang/15.0.7
CPATH="-resource-dir /usr/lib/llvm-15/lib/clang/15.0.7:/usr/lib/llvm-15/lib/clang/15.0.7/include:/usr/local/include:/usr/include/x86_64-linux-gnu:/usr/include"
CPPFLAGS="-nostdinc -nobuiltininc"
```

Then, pass this modified (or newly created) `env_vars.txt` to `mx-index` using
`--env env_vars.txt`. The purpose of this is to make GCC behave slightly more
like Clang for the sake of Multiplier's "compiler oracle" knowledge gathering
phase. 

## Getting `compile_commands.json`
There are several ways to get a `compile_commands.json` file from your build.

### Clang
If you project can be configured to build with Clang then you're in luck, because
you can get Clang to collect the compile commands on your behalf with a few tricks.

Suppose your normal build command is `make all` or `ninja all`. Then you will
run it as follows:

```shell
mkdir -p /tmp/clang_compile_commands

rm /tmp/clang_compile_commands/*.json

CCC_OVERRIDE_OPTIONS="# +-gen-cdb-fragment-path +$/tmp/clang_compile_commands " \
ninja all
```

The above commands:

 - Create the directory `/tmp/compile_commands` if it doesn't yet exist
 - Remove all JSON files from within that directory if any remain. This is an
   optional step, and you'd want to do that if you did a `make clean` or
   `ninja clean` step prior to running your build command.
 - Run your build command, in this case `ninja all`, with the `CCC_OVERRIDE_OPTIONS`
   environment variable set. This environment variable allows one to rewrite Clang
   compile commands. In this case, the rewriting introduces the command-line
   option `-gen-cdb-fragment-path /tmp/clang_compile_commands`. This option
   instructs Clang to save JSON compile commands into the `/tmp/clang_compile_commands`
   directory.

Next, run the following command:

```shell
python3 /path/to/multiplier-checkout/scripts/combine_compile_commands.py /tmp/clang_compile_commands/*.json > compile_commands.json
```

This invokes the [combine_compile_commands.py](../scripts/combine_compile_commands.py) script
to combine the JSON files into a single file, and saves it into the current working
directory under the name `compile_commands.json`.

### CMake
Add the following option to your [CMake](https://cmake.org/) configuration command:
[`-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`](https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html). This will save a `compile_commands.json`
file in the build directory.

### Bear
Install [Bear](https://github.com/rizsotto/Bear) and then prefix your build
command, such as `make`, with `bear --`, for example: `bear -- make`. This will
save a `compile_commands.json` file in the build directory.

### `scan-build`
Install [`scan-build`](https://github.com/rizsotto/scan-build) and then prefix
your build command, such as `make`, with `intercept-build`, for example: `intercept-build make`. This will save a `compile_commands.json` file in the current directory.

## Importing builds from target binaries
Install a [branch](https://github.com/trailofbits/blight/tree/kumarak/embed_compile_command) of [Blight](https://github.com/trailofbits/blight), ideally into a Python virtual environment (to isolate it from your globally installed Python packages), as follows:

```shell
python -m pip install git+https://github.com/trailofbits/blight@kumarak/embed_compile_command
```

Optionally, you may need to use Blight as part of the configuration step of your
build, e.g.:

```shell
blight-exec --swizzle-path -- ./configure
```

Then, use Blight again but this time on your build command, e.g. make, and
specify an action to embed specially-formatted compile commands into the build
artifacts:

```shell
mkdir -p /tmp/commands

BLIGHT_ACTION_EMBEDCOMMANDS="output=/tmp/commands" \
blight-exec --action EmbedCommands --swizzle-path -- make
```

If this works, then every object file, library, and binary should embed an
additional section containing detailed compilation commands relevant to the
binary. These embedded compile commands include environment variables, and so
passing `--env` to `mx-index` is not necessary.

Choose one of the output binaries from the build process, and pass its path to
the `--target` option of `mx-index`. Yes, that is right -- `mx-index` can take
a program executable as a target!
