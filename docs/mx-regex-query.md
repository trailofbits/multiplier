# `mx-regex-query`

This tool allows one to perform regular expression queries over the code. What is unique about it is that the matched results are based on parsed tokens, not original file tokens, and match groups are as much as possible aligned with their matching entities. This is more relevant when using the actual API, rather than the command-line tool.

```shell
% mx-regex-query --db /tmp/curl.db --query '([^ ]*) = \(([^)]*)\)\s*malloc\((.*)\);'
```

The following is the output of the above command:

```
2305843009214767275 1152921504606847553 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/include/MacTypes.h"
  [0] =   l = (struct BarList*) malloc( sizeof(BarList) + count * sizeof(Bar) );
  [1] =   l
  [2] =   struct BarList*
  [3] =    sizeof(BarList) + count * sizeof(Bar) 


2305843009214771345 1152921504606847574 "/Users/pag/Code/curl/lib/mime.c"
  [0] =   mime = (curl_mime *) malloc(sizeof(*mime));
  [1] =   mime
  [2] =   curl_mime *
  [3] =   sizeof(*mime)


2305843009214779044 1152921504606847726 "/Users/pag/Code/curl/src/tool_cb_wrt.c"
  [0] =   wc_buf = (wchar_t*) malloc(wc_len * sizeof(wchar_t));
  [1] =   wc_buf
  [2] =   wchar_t*
  [3] =   wc_len * sizeof(wchar_t)
```

This output shows `[0]` as representing the complete capture, i.e. everything matched by the regular expression, and each subsequent index, e.g. `[1]`, corresponds to a specific capture group (parenthesized expression in the regular expression).

This tool can be restricted to operate on specific fragments with `--fragment_id` or all fragments within a specific file with `--file_id`.

An interesting aspect of Multiplier is that the underlying APIs that enact regex queries attempts to bind the captures to specific tokens, enabling one to jump back into the AST by way of [token contexts](mx-print-token-graph.md).
