# hyperthreading

Playing with multithreading in x86 assembly (linux)

Build steps [unfinished]:
- Make sure you're building and running this on an x86 CPU. You can confirm via `uname -m` or `dpkg --print-architecture`.
- Download headers for the linux kernel you're running. You can do this by running `sudo apt install linux-headers-$(uname -r)`. If it fails, then in the worst case you are not running a mainline build of the kernel. In which case you will need to download the sources for your build, and then store them in `/lib/modules/$(uname -r)/build`. If you are running WSL2, know that the kernel Microsoft ships with WSL2 does not support kernel module loading, so you will have to rebuild the WSL2 kernel from source, which you can find [here](https://github.com/microsoft/WSL2-Linux-Kernel). This is what I had to do but I will outline the steps for it in the future.
- Once you have the headers, you can start with kernel module development. Run `make` to build the module. Run `sudo make install` to load the built module into your kernel.
- To confirm that your module is installed, run `lsmod`. If you see `smp`, then you're all good.
- If you've made changes to the code and wish to rebuild and reinstall, first clean the working directory via `make clean`, then uninstall your module via `sudo make uninstall`. Now you may run the commands in the previous step.
