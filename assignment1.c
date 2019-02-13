/**
*assignment1.c
*
*To compile, run makefile by entering "make"
*
*To test, run makefile by entering "make test"
*
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
unsigned long js, h, je, a;
unsigned b;
/* This function is called when the module is loaded. */
static int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "[Golden Ratio Prime : %lu]\n", GOLDEN_RATIO_PRIME);
       js = jiffies;
       h = HZ;
       printk(KERN_INFO "\n[Jiffies start value : %lu]\n[Jiffies value in HZ : %lu]\n", js, h);

       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	//a = 3300;
	//b = 24;
	//unsigned long gcd(a, b);
	je = jiffies;
	printk(KERN_INFO "\n[Jiffies end value: %lu]\n", je);
	
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Alvin");
