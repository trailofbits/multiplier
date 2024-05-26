# `mx-list-structures`

This tool lists structures (`struct`, `union`, etc.) and their fields. For
example:

```shell
% mx-list-structures --db /tmp/curl.db
0 2305843009214742530 9362983625305358336 __NSConstantString_tag
    9272911632757948416 isa
    9272911632757948417 flags
    9272911632757948418 str
    9272911632757948419 length
1152921504606847021 2305843009214747660 9266156238696087552 idtype_t::(anonymous enum)
    9263904438882402304 P_ALL
    9263904438882402305 P_PID
    9263904438882402306 P_PGID
1152921504606846996 2305843009214748559 9266156239638757376 clockid_t::(anonymous enum)
    9263904439825072128 _CLOCK_REALTIME
    9263904439825072129 _CLOCK_MONOTONIC
    9263904439825072130 _CLOCK_MONOTONIC_RAW
    9263904439825072131 _CLOCK_MONOTONIC_RAW_APPROX
    9263904439825072132 _CLOCK_UPTIME_RAW
    9263904439825072133 _CLOCK_UPTIME_RAW_APPROX
    9263904439825072134 _CLOCK_PROCESS_CPUTIME_ID
    9263904439825072135 _CLOCK_THREAD_CPUTIME_ID
...
```

The output format is `<file_id> <fragment_id> <decl_id> <structure_name>` and
for the fields, it is indented, and `<decl_id> <field_name>`. Here we see
`__NSConstantString_tag`, a built-in structure on macOS, has no file id, and
the second structure has no name.
