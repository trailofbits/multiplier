# `mx-find-calls-in-macro-expansions`

This tool locates calls to functions that are visible in the top-level arguments
to macros.

For example:
```shell
mx-find-calls-in-macro-expansions --db /tmp/curl.db
```

Here is one of the outputs:

![Call in macro argument](images/mx-find-calls-in-macro-expansions.png)

In the above, the `infof` function is called inside the top-level argument list
to the `DEBUGF` macro.