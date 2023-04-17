KMOD = smp
MAIN = main
KDIR = /lib/modules/$(shell uname -r)/build

obj-m += $(KMOD).o
$(KMOD)-y := entry.o $(MAIN).o

$(MAIN).o: $(MAIN).asm
	nasm -f elf64 -o $@ $^ && echo "" > .main.o.cmd && make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean

install:
	insmod $(KMOD).ko

uninstall:
	rmmod $(KMOD)