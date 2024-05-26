# Installing the Multiplier SDK

The Multiplier SDK has been tested on Ubuntu 23.10. Run the following command
to install the Debian package:

```shell
sudo apt install ./multiplier-2.0_1.linux_x86_64.deb
```

If you see an error such as: "Download is performed unsandboxed as root" then
you can fix it in one of two ways. The simplest and least intrusive way to fix
this is by moving the `.deb` file into your `/tmp` directory, and then install
it from there. Alternatively, you can run the following command:

```shell
sudo chown -R _apt:root /var/lib/apt/lists
```

The above command will install the Multiplier SDK into the `/opt/multiplier`
directory. For example, Multiplier's build indexer will be installed to
`/opt/multiplier/bin/mx-index`.

Over time, the package version numbers are likely to change so you will need to
adjust the `.deb` file name. For the sake of simplicity in packaging, the SDK
includes all of Multiplier's vendored dependencies, and these may conflict with
binaries/libraries already installed on your system. You should not assume that
Multiplier's vendored dependencies are drop-in compatible with your system ones,
as our dependency building process often toggles specific compilation flags that
set or restrict specific features, and thus the enabled features may be
incompatible with those from Aptitude or the Debian package manager.

You can use dpkg to install the debian package as well. In case you encounter
issues related to missing dependencies, force install them using `apt`.

```shell
sudo dpkg -i multiplier-2.0_1.linux_x86_64.deb
sudo apt install -f   # if you see error related to dependencies
```
