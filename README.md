# hyperthreading

### Playing with multithreading in x86 assembly (Intel + debian)

**Note: This is an unfinished project. Building and running will currently not have the expected behaviour.**

While modern Intel CPU packages will allow ring 3 code to directly issue interrupts to it's cores in order to run multithreaded code, Linux will make it impossible, forcing userland programs to instead achieve this via syscalls. Therefore, in order to to freely play around with this, you either need to write your own kernel, or write a Linux kernel module. The latter is what I am attempting here.

Build steps:
- Make sure you're building and running this on an x86 CPU. You can confirm via `uname -m` or `dpkg --print-architecture`.
- Download headers for the linux kernel you're running. You can do this by running `sudo apt install linux-headers-$(uname -r)`. If it fails, then in the worst case you are not running a mainline build of the kernel. In which case you will need to download the sources for your build, and then store them in `/lib/modules/$(uname -r)/build`. If you are running WSL2, know that the kernel Microsoft ships with WSL2 does not support kernel module loading, so you will have to rebuild the WSL2 kernel from source, which you can find [here](https://github.com/microsoft/WSL2-Linux-Kernel). This is what I had to do but I will outline the steps for it in the future.
- Once you have the headers, you can start with kernel module development. Run `make` to build the module. Run `sudo make install` to load the built module into your kernel.
- To confirm that your module is installed, run `lsmod`. If you see `smp`, then you're all good.
- If you've made changes to the code and wish to rebuild and reinstall, first clean the working directory via `make clean`, then uninstall your module via `sudo make uninstall`. Now you may rerun the commands to build and install the kernel module. Alternatively, you can simply run `sudo make reinstall` to do all of these steps in one go after you've made changes to the code.
