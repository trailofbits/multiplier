# `mx-list-redeclarations`

This utility lists all redeclarations of an entity given its entity ID. This
applies to types as well as functions. For example:

```shell
% mx-list-functions --db /tmp/curl.db
...                                 
1152921504606846985 2305843009214749003 9475573622777053184 gethostname decl
...
```

First, copy the entity ID, `9475573622777053184`, of the `gethostname`
declaration. Then pass this to `mx-list-redeclarations` as follows:

```shell
% mx-list-redeclarations --db /tmp/curl.db --declaration_id 9475573657371672576                 
1152921504606847989 2305843009214781996 9281918873395789824 def FUNCTION  gethostname
1152921504606846985 2305843009214749003 9475573622777053184 decl  FUNCTION  gethostname
1152921504606847988 2305843009214781995 9475573657371672576 decl  FUNCTION  gethostname
```

The output format is `<file_id> <fragment_id> <declaration_id> <def|decl> <kind> <name>`.
The `--show_locations` command-like option can also be passed to show the source
location of each redeclaration.