# Group functions by type

[GroupFunctions.py](../bin/Examples/GroupFunctions.py) implements a feature [requested](https://x.com/eatonphil/status/1821573274582823247)
by Phil Eaton: being able to quickly find functions that share the same function signature.

Finding same-typed functions is more complicated than comparing their types for
identity, or superficially comparing the printed representations of those types.
One must account for `typedef`s, as well as the possibly (in)effective impact of
qualifiers.

This analysis does not compare uninstantiated function templates, or functions
that have template-dependent types. This analysis also does not treat covariant
return types of methdod overrides as being in the equivalence classes of functions
with the same type. However, this would only require a minor manual extension.

Here is some example output of this tool:

```c
///////////////////////////////////////////////////////////////
//  g_lstat @ /Users/pag/Code/openssh-portable/openbsd-compat/glob.c:1014:1
    static int
    g_lstat(Char *fn, struct stat *sb, glob_t *pglob)
    

//  g_stat @ /Users/pag/Code/openssh-portable/openbsd-compat/glob.c:1026:1
    static int
    g_stat(Char *fn, struct stat *sb, glob_t *pglob)
    

///////////////////////////////////////////////////////////////
//  glob0 @ /Users/pag/Code/openssh-portable/openbsd-compat/glob.c:474:1
    static int
    glob0(const Char *pattern, glob_t *pglob, struct glob_lim *limitp)
    

//  globexp1 @ /Users/pag/Code/openssh-portable/openbsd-compat/glob.c:239:1
    static int
    globexp1(const Char *pattern, glob_t *pglob, struct glob_lim *limitp)
    

```