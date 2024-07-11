# Variant analysis of regreSSHion (CVE-2024-6387)

This variant analysis looks for calls to signal-unsafe functions by signal handlers. Note that the scope of this analysis is limited to identifying the potential of apparently reachable unsafe paths, not verifying whether reachibility conditions, nor verifying whether or not those paths are exploitable.

This analysis starts with showing how to checkout and index the relevant version of the code, then how to discover the unsafe paths through the call graph manually using example tools, and finally how to use the Python API to script up a simple but generic checker for this kind of issue.

* [Getting and indexing the code](#getting-and-indexing-the-code)
  * [Configuring the build](#configuring-the-build)
  * [Building the code](#building-the-code)
  * [Indexing the code](#indexing-the-code)
* [Manually finding the issue](#manually-finding-the-issue)
  * [Finding `SIGALRM` handlers](#finding-sigalrm-handlers)
  * [Finding paths from signal handlers to `free`](#finding-paths-from-signal-handlers-to-free)
  * [Confirming reachability](#confirming-reachability)
* [Automating the analysis](#automating-the-analysis)
  * [Setting up a virtual environment](#setting-up-a-virtual-environment)
  * [Interacting with a database](#interacting-with-a-database)
  * [Problem analysis](#problem-analysis)
  * [Discovering signal handlers](#discovering-signal-handlers)
    * [Finding `signal`](#finding-signal)
    * [Finding `sigaction`](#finding-sigaction)

## Getting and indexing the code

### Getting the code

```bash
git clone https://github.com/openssh/openssh-portable.git
cd openssh-portable
```

Then, checkout OpenSSH [9.7p1](https://github.com/openssh/openssh-portable/releases/tag/V_9_7_P1:

```bash
git checkout 86bdd3853f4d32c85e295e6216a2fe0953ad93f0
```

### Configuring the build

```bash
autoreconf
CC=`which clang` CXX=`which clang++` ./configure --with-ssl-dir=$HOME/.brew/opt/openssl
```

**Note:** You may need to fiddle with the `configure` invocation. For example, I needed to specify `--with-ssl-dir` on my machine to avoid a `libcrypto` issue.

### Building the code

```bash
mkdir /tmp/clang_compile_commands
CCC_OVERRIDE_OPTIONS="# +-gen-cdb-fragment-path +/tmp/clang_compile_commands " \
make all
```

After this, we should see the following:

```bash
% ls /tmp/clang_compile_commands 
addr.c.5e13.json      fnmatch.c.730f.json     session.c.caa5.json
addrmatch.c.aa04.json     freezero.c.2da8.json      setenv.c.4b9f.json
arc4random.c.ef99.json      getcwd.c.cb71.json      setproctitle.c.9167.json
```

### Indexing the code

Using the [combine_compile_commands.py](../scripts/combine_compile_commands.py) to create a single compilation database for indexing.

```bash
% python3 /path/to/multiplier-checkout/scripts/combine_compile_commands.py /tmp/clang_compile_commands/*.json >compile_commands.json
```

Next, we'll run `mx-index` to index OpenSSH.

```bash
% time ./bin/mx-index --db /tmp/openssh.db --workspace /tmp/openssh.ws --target compile_commands.json --generate_sourceir --show_progress
Commands                       (237 / 237)           100% [||||||||||||||||||||||||||||||||||||||||]
Evaluated commands             (237 / 237)           100% [||||||||||||||||||||||||||||||||||||||||]
Parsing                        (237 / 237)           100% [||||||||||||||||||||||||||||||||||||||||]
File serialization             (663 / 663)           100% [||||||||||||||||||||||||||||||||||||||||]
AST partitioning               (237 / 237)           100% [||||||||||||||||||||||||||||||||||||||||]
Fragment serialization         (30601 / 30601)       100% [||||||||||||||||||||||||||||||||||||||||]
Type serialization             (18416 / 18416)       100% [||||||||||||||||||||||||||||||||||||||||]
SourceIR                       (  0 / 237)             0% [                                        ]

mx-index --db /tmp/openssh.db --workspace /tmp/openssh.ws --target    246.65s user 48.49s system 523% cpu 56.417 total
```

Here we told `mx-index` to save its database to `/tmp/openssh.db` (we'll need this soon), and its temporary workspace to the directory `/tmp/openssh.ws`. We can now delete `/tmp/openssh.ws`, as its only needed if we wanted to index additional projects into the same database.

The `--generate_sourceir` flag is optional if you plan to do the Python scripting. It will produce a lot more errors as output, but the indexer should finish.

```bash
rm -rf /tmp/openssh.ws
```

## Manually finding the issue

The [description](https://www.qualys.com/2024/07/01/cve-2024-6387/regresshion.txt) of regreSSHion states:

> The `SIGALRM` handler of this OpenSSH version calls `packet_close()`, which calls `buffer_free()`, which calls `xfree()` and hence `free()`, which is not async-signal-safe.

We'll start by checking this with the test tools provided in the SDK. This is not the actual way I would recommend doing anything in practice, as these tools are designed as examples of how to use the API, as well as functionality tests of the API -- they are not designed specifically for productivity or composition. Later we'll use scripting to turn this into automated checker.

### Finding `SIGALRM` handlers

We'll start by trying to understand the specific `SIGALRM` signal. First, lets locate the entity:

```bash
% mx-find-symbol --db /tmp/openssh.db --name SIGALRM --exact
1152921504606847020 2305843009214760458 13314892317121839104  SIGALRM DEFINE_DIRECTIVE
```

The third id, `13314892317121839104`, is the entity ID of `SIGALRM`. Next, lets go and find all uses of `SIGALRM`:

```bash
% mx-highlight-references --db /tmp/openssh.db --entity_id 13314892317121839104
```

The first reference looks like this:

![First reference to SIGALRM](images/openssh-variant-analysis-sigalrm-ref-0.png)

So this says there's a function, `ssh_signal`, taking in a signal number `signum` and a signal handler `handler`, and it attaches `handler` to the `signum` using `sigaction`. In some other uses, we see a handler `sig_alarm` and `grace_alarm_handler` registered for `SIGALRM` via `ssh_signal`: 

![Registering sig_alarm for SIGALRM](images/openssh-variant-analysis-sigalrm-ref-1.png)
![Registering grace_alarm_handler for SIGALRM](images/openssh-variant-analysis-sigalrm-ref-2.png)

### Finding paths from signal handlers to `free`

So next we can look for paths between `sig_alarm` or `grace_alarm_handler` and a async signal unsafe function, such as `free`.

Next, we'll find `free`:

```bash
% mx-find-symbol --db /tmp/openssh.db --name free --exact
1152921504606847195 2305843009214751135 9475573625012617216 free  FUNCTION
```

The third number, `9475573625012617216`, is the entity ID of `free`. Now lets
look for `sig_alarm` and `grace_alarm_handler`:

```bash
% mx-find-symbol --db /tmp/openssh.db --name sig_alarm --exact
1152921504606847411 2305843009214762518 9281918852971626496 sig_alarm FUNCTION
1152921504606847411 2305843009214762498 9475573636927586304 sig_alarm FUNCTION
```

There are two of them, so one is probably a definition and the other is probably a declaration. We can choose
the entity ID of either of them.

```bash
% mx-find-symbol --db /tmp/openssh.db --name grace_alarm_handler --exact
1152921504606847515 2305843009214768730 9281918859485380608 grace_alarm_handler FUNCTION
```

Next, lets see if we can find a path from `sig_alarm` or `grace_alarm_handler` to `free`:

```bash
% mx-print-call-graph --db /tmp/openssh.db --entity_id 9475573625012617216 --reachable_from_entity_id 9281918852971626496 >/tmp/sig_alarm_to_free.dot
```

```bash
% mx-print-call-graph --db /tmp/openssh.db --entity_id 9475573625012617216 --reachable_from_entity_id 9281918859485380608 >/tmp/grace_alarm_handler_to_free.dot
```

This creates the call graphs of `free` rooted at `sig_alarm` and `grace_alarm_handler`, respectively. The output of the `mx-print-call-graph` is a [DOT digraph](https://graphviz.org/doc/info/lang.html). There are no edges in the `sig_alarm` to `free` graph, so we'll focus on the `grace_alarm_handler` to `free` graph:

### Confirming reachability

```bash
% xdot /tmp/grace_alarm_handler_to_free.dot
```

With output looking like this:

![Call graph paths from grace_alarm_handlers to free](images/openssh-variant-analysis-grace_alarm_handler-to-free.png)

We can see that from `grace_alarm_handler`, we can reach `sshfata` via `xmalloc` or `get_sock_port`, and from there `cleanup_exit` provides paths to `free`.

We have now manually confirmed the rough reachability details of the CVE, i.e. that an async-signal unsafe function can potentially be invoked by a signal handler in OpenSSH.

## Automating the analysis

We can automate the analysis using Multiplier's Python API.

### Setting up a virtual environment

If you have unpacked a [release](https://github.com/trailofbits/multiplier/releases) of Multiplier to `/path/to/multiplier`, then inspect the `lib` subdirectory to see the Python version against which the API is built:

```bash
% ls /path/to/multiplier/lib
cmake     libLTO.so.18.1    libRemarks.so.18.1  libgap-coro.a   libmultiplier.so  python3.11
```

Above we see a `python3.11` subdirectory inside of `lib`. Next, create and enter a virtual environment using a Python interpreter with a matching version number:

```bash
% python3.11 -m venv /path/to/multiplier
% source /path/to/multiplier/bin/activate
(multiplier) %
```

### Interacting with a database

Inside your virtual environment, open your Python interpreter and try the following:

```bash
% python
Python 3.11 ...
Type "help", "copyright", "credits" or "license" for more information.
>>> import multiplier as mx
>>>
```

Next, we'll open a connection to the OpenSSH database. We do two things here: we open the database by its path, then we wrap that connection in an in-memory cache. In practice, you always want to wrap the connection in the cache. Having this as a separate API may seem strange or unintuitive; however, it's important to remember that the Python API is derived from the C++ API, and so this allows users of the C++ API to decide how many caches they want to have, giving them a measure of concurrency control (e.g. if there are multiple analysis threads).

```python
>>> index = mx.Index.in_memory_cache(mx.Index.from_database("/tmp/openssh.db"))
```

Lets verify that we can indeed find `SIGALRM` as before:

```python
>>> sigalrm = next(index.query_entities("SIGALRM"))
>>> sigalrm
<multiplier.frontend.DefineMacroDirective object at 0x104328c90>
>>> sigalrm.use_tokens.file_tokens.data
'#define SIGALRM 14'
```

Alright, we're now in a position to start actually attacking the overarching problem of discovering instances, or variants, of the same underlying bug across a whole codebase. Lets break things down into sub problems and then we can attack each sub problem in turn.

### Problem analysis

 1. The first problem we need to solve is discovering signal handlers. There are two ways of registering signal handlers: the `signal` function, and the `sigaction` function.

 2. The second problem we need to solve is identifying async-unsafe functions. We're going to simplify our lives and hard code a list of such functions.

 3. The last problem is finding paths in the call graph between signal handlers and async-unsafe functions.

### Discovering signal handlers

Lets go inspect the prototypes of the signal handler registration functions:

#### Finding `signal`

```python
>>> signal = next(f for f in index.query_entities("signal") if isinstance(f, mx.ast.FunctionDecl) and f.name == "signal")
>>> print(signal.tokens.file_tokens.data)
void(*signal(int, void (*)(int)))(int);
```

The first thing to notice is the querying approach is a bit more complex than what we saw with `SIGALRM`. With OpenSSH, there are a lot of entities with `signal` in the name, so we narrowed it down to function declarations with `isinstance` and we did an exact match on the function's name.

That's easy enough: the `signal` function takes in a function pointer representing the new signal handler function, and returns a function pointer representing the old signal handler. So if we want to find signal handlers, then we need to find function pointers flowing into the only argument to `signal`.

#### Finding `sigaction`

```python
>>> sigaction = next(f for f in index.query_entities("sigaction") if isinstance(f, mx.ast.FunctionDecl) and f.name == "sigaction")
>>> print(sigaction.tokens.file_tokens.data)
int sigaction(int, const struct sigaction * __restrict,
      struct sigaction * __restrict);
```

Alright, this is a bit more complicated: `sigaction` takes in a signal number, such as `SIGALRM`, and a pointer to a `struct sigaction`. We could search for `struct sigaction` by name, but lets try to get at it via the `sigaction` function instead. This will ensure we find the *right* `struct sigaction`, because in theory there could be many same-named but differently purposed structures in a codebase.

We can get at the second parameter as follows:

```python
>>> sigaction.nth_parameter(1).type
<multiplier.ast.QualifiedType object at 0x1048991d0>
```

And we can access its type as follows:

```python
>>> sigaction.nth_parameter(1).type
<multiplier.ast.QualifiedType object at 0x1048991d0>
```

This is still opaque though -- what is this `QualifiedType` actually?

```python
>>> sigaction.nth_parameter(1).type.tokens.data
'const struct sigaction * restrict'
```

So we're on the right track. Now we want to strip off the qualifiers (`restrict`):

```python
>>> sigaction.nth_parameter(1).type.unqualified_type
<multiplier.ast.PointerType object at 0x1048980c0>
>>> sigaction.nth_parameter(1).type.unqualified_type.tokens.data
'const struct sigaction *'
```

We can also use `.unqualified_desugared_type` in place of `.unqualified_type` to strip out `typedef` types and such. That is a more robust solution.

And next we want to find the element type of the pointer:

```python
>>> sigaction.nth_parameter(1).type.unqualified_desugared_type.pointee_type
<multiplier.ast.QualifiedType object at 0x1059bbc30>
>>> sigaction.nth_parameter(1).type.unqualified_desugared_type.pointee_type.tokens.data
'const struct sigaction'
```

And finally, lets get at the `struct sigaction` type:

```python
>>> sigaction_type = sigaction.nth_parameter(1).type.unqualified_desugared_type.pointee_type.unqualified_desugared_type
>>> sigaction_type
<multiplier.ast.RecordType object at 0x104899fb0>
>>> sigaction_type.tokens.data
'struct sigaction'
```

We can get at the record declaration as follows:

```python
>>> sigaction_struct = sigaction_type.declaration
>>> sigaction_struct
<multiplier.ast.RecordDecl object at 0x104899fb0>
>>> print(sigaction_struct.tokens.file_tokens.data)
struct  sigaction {
  union __sigaction_u __sigaction_u;  /* signal handler */
  sigset_t sa_mask;               /* signal mask to apply */
  int     sa_flags;               /* see signal options below */
};
```

It looks like the signal handler is itself nested inside of a `union __sigaction_u` inside of `struct sigaction`. I'm on macOS, and there are no clear guarantees as to how deep this rabbit hole of structs and unions will go. Consulting the [Linux manual pages](https://man7.org/linux/man-pages/man2/sigaction.2.html) for this structure shows that the nature of this structure is finnicky at best:

```
The sigaction structure is defined as something like:

    struct sigaction {
        void     (*sa_handler)(int);
        void     (*sa_sigaction)(int, siginfo_t *, void *);
        sigset_t   sa_mask;
        int        sa_flags;
        void     (*sa_restorer)(void);
    };

On some architectures a union is involved: do not assign to both
sa_handler and sa_sigaction.
```

Alright, we're going to have to do some digging. We'll apply a simple work list algorithm to go and find the nested fields that have function pointer types.

```python
>>> wl = [sigaction_struct]
>>> sigaction_fields = []
>>> while len(wl):
...   frag = mx.Fragment.containing(wl.pop())
...   for field in mx.ast.FieldDecl.IN(frag):
...     if "restore" in field.name:
...       continue
...     ft = field.type.unqualified_desugared_type
...     if isinstance(ft, mx.ast.PointerType):
...       sigaction_fields.append(field)
...     elif isinstance(ft, mx.ast.RecordType):
...       wl.append(ft.declaration)
...
>>> sigaction_fields
[<multiplier.ast.FieldDecl object at 0x105a1eeb0>, <multiplier.ast.FieldDecl object at 0x105a1f000>]
```

Lets see what we found:

```python
>>> render_opts = mx.ast.QualifiedNameRenderOptions(fully_qualified=True)
>>> [f.qualified_name(render_opts).data for f in sigaction_fields]
['__sigaction_u::__sa_handler', '__sigaction_u::__sa_sigaction']
```

Alright, it looks like our worklist algorithm has discovered the relevant fields within `union __sigaction_u` given a starting point of `struct sigaction`. Lets describe how it worked:

 1. The worklist operates on record declarations.
 2. We get the "fragment" containing the record declaration popped off the back of the work list. Every declaration is nested inside of a fragment, which is the unit of deduplication and serialization granularity in Multiplier. Roughly, every lexically freestanding top-level declaration is placed into its own fragment, and any lexically nested declaration belongs to that fragment. There are caveats to this rule when it comes to C++ classes, methods, and templates. 
 3. Then, we find all field declarations within the fragment we're looking at, then check if their type is a pointer type. Note that we skip fields containing the word `restore` in their names. This field isn't meant to be used by user code.

#### Slicing to find reaching values

Alright, next up, we want to slice backwards through a program to discover function pointers that flow into the second argument of `signal`, or into any of our `sigaction_fields`.

```python
>>> wl = [signal.nth_parameter(1)] + sigaction_fields
>>> seen = set()
>>> render_opts = mx.ast.QualifiedNameRenderOptions(fully_qualified=True)
>>> handlers = []
>>> while len(wl):
...   ent = wl.pop()
...   if isinstance(ent, mx.Entity):
...     eid = ent.id
...     if eid in seen:
...       continue
...     seen.add(eid)
...   if isinstance(ent, mx.ast.ParmVarDecl):
...     print("Visiting {} '{}' with ID {}".format( \
...         ent.kind.name, ent.qualified_name(render_opts).data, ent.id))
...     func = ent.parent_declaration
...     n = [p.id for p in func.parameters].index(ent.id)
...     for caller in func.callers:
...       if isinstance(caller, mx.ast.CallExpr):
...         if nth_arg := caller.nth_argument(n):
...           wl.append(nth_arg)
...   elif isinstance(ent, (mx.ast.VarDecl, mx.ast.FieldDecl)):
...     print("Visiting {} '{}' with ID {}".format( \
...         ent.kind.name, ent.qualified_name(render_opts).data, ent.id))
...     for ref in mx.Reference.to(ent):
...       if brk := ref.builtin_reference_kind:
...         if brk in (mx.BuiltinReferenceKind.WRITES_VALUE, \
...                    mx.BuiltinReferenceKind.UPDATES_VALUE):
...           if decl_ref := ref.as_statement:
...             wl.append(decl_ref)
...   elif isinstance(ent, (mx.ast.DeclRefExpr, mx.ast.MemberExpr)):
...     if isinstance(ent, mx.ast.DeclRefExpr):
...       maybe_handler = ent.declaration
...       if isinstance(maybe_handler, mx.ast.FunctionDecl):
...         handlers.append(maybe_handler)
...         continue
...     print(f"Visiting {ent.kind.name} '{ent.tokens.file_tokens.data}' with ID {ent.id}")
...     for op in mx.ir.Operation.all_from(ent):
...       for use in op.uses:
...         user = use.operation
...         for other_use in user.operands:
...           if other_use != use:
...             wl.append(other_use.value)
...   elif isinstance(ent, mx.ast.CallExpr):
...     print(f"Skipping {ent.kind.name} '{ent.tokens.file_tokens.data}' with ID {ent.id}")
...   elif isinstance(ent, mx.ast.Expr):
...     print(f"Visiting {ent.kind.name} '{ent.tokens.file_tokens.data}' with ID {ent.id}")
...     for op in mx.ir.Operation.all_from(ent):
...       for use in op.operands:
...         wl.append(use.value)
...   elif isinstance(ent, mx.ir.Result):
...     wl.append(ent.operation)
...   elif isinstance(ent, mx.ir.Argument):
...     block = mx.ir.Block.containing(ent)
...     for label in block.uses:
...       print(label)
...     region = mx.ir.Region.containing(block)
...     if region.entry_block == block:
...       region_op = mx.ir.Operation.containing(block)
...       if isinstance(region_op, mx.ir.highlevel.FuncOp):
...         func_decl = mx.ast.FunctionDecl.FROM(region_op)
...         if not func_decl:
...           if decl := index.entity(int(region_op.sym_name)):
...             if isinstance(decl, mx.ast.FunctionDecl):
...               func_decl = decl
...         if func_decl:
...           wl.append(func_decl.nth_parameter(ent.index)) 
...       else:
...         wl.append(region_op.nth_operand(ent.index).value)
...   elif isinstance(ent, mx.ir.highlevel.CallOp):
...     print(f"Skipping {ent.kind.name} with ID {ent.id}")
...   elif isinstance(ent, mx.ir.highlevel.DeclRefOp):
...     print(f"Working back through {ent.kind.name} with ID {ent.id}")
...     wl.append(ent.decl)
...   elif isinstance(ent, mx.ir.Operation):
...     print(f"Working back through {ent.kind.name} with ID {ent.id}")
...     for op in ent.operands:
...       wl.append(op.value)
...   else:
...     print(f"Unknown: {ent.kind.name} {ent.tokens.file_tokens.data}")
```
