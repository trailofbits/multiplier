# `mx-list-files`

This tool lists the indexed files. Each file has a unique ID, however, the path
is not necessarily unique.

```shell
% mx-list-files --db /tmp/curl.db 
% ./bin/mx-list-files --db /tmp/curl.db 
1152921504606847550 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CFArray.h
1152921504606847479 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CFAttributedString.h
1152921504606847556 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CFAvailability.h
1152921504606847549 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CFBag.h
...
1152921504606847662 /Users/pag/.brew/Cellar/openssl@3/3.3.0/include/openssl/x509v3err.h
1152921504606847175 /Users/pag/.brew/include/libssh2.h
1152921504606847173 /Users/pag/.brew/include/libssh2_sftp.h
1152921504606847130 /Users/pag/Build/Debug/curl/lib/curl_config.h
1152921504606847751 /Users/pag/Build/Debug/curl/src/tool_hugehelp.c
1152921504606847140 /Users/pag/Code/curl/include/curl/curl.h
...
1152921504606847141 /Users/pag/Code/curl/include/curl/urlapi.h
1152921504606847137 /Users/pag/Code/curl/include/curl/websockets.h
1152921504606847238 /Users/pag/Code/curl/lib/altsvc.c
1152921504606847237 /Users/pag/Code/curl/lib/altsvc.h
1152921504606847131 /Users/pag/Code/curl/lib/amigaos.c
1152921504606847402 /Users/pag/Code/curl/lib/amigaos.h
...
```

The format of the output is:

```
<file_id> <file_path>
```

With the following interpretations:

* `file_id`: This is the entity ID of the file containing.
* `path`: This is the absolute path to the indexed file. 

A key thing to understand about Multiplier is that the indexed files are stored
*in the database*. Thus, the absolute paths listed may not correspond to extant
files on your machine. This could happen for many reasons, e.g. the build was
indexed and then the source code was deleted, or the build was indexed and then
the index database was copied onto a different machine.

File paths are not guaranteed to be unique. One reason this could happen is that
multiple versions of the same codebase were indexed and stored into the same
database.
