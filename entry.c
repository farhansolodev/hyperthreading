#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

extern int asm_init(void);

void welcome(void) {
	printk("Welcome to my driver!\n");
}

static int __init smp_driver_init(void)
{
    welcome();
	return asm_init();
}

static void __exit smp_driver_exit(void)
{
	printk("Leaving my driver!\n");
	return;
}

module_init(smp_driver_init);
module_exit(smp_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gerooq");
MODULE_DESCRIPTION("Testing multithreading using x86 assembly");
MODULE_VERSION("1.0");
