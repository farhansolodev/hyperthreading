#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

extern int asm_init(void);

static int __init smp_driver_init(void)
{
	printk("Welcome to my driver!\n");
	asm_init();
	return 0;
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
