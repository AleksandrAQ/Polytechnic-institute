/*
* hello-3.c - Использование макроопределений __init, __initdata и __exit.
*/
#include <linux/module.h>
/* Необходим для любого модуля ядра */
#include <linux/kernel.h>
/* Здесь находится определение KERN_ALERT */
#include <linux/init.h>
/* Здесь находятся определения макросов */
static int hello3_data __initdata = 3;
static int __init hello_3_init(void)
{
printk(KERN_ALERT "Hello, world %d\n", hello3_data);
return 0;
}static void __exit hello_3_exit(void)
{
printk(KERN_ALERT "Goodbye, world 3\n");
}
module_init(hello_3_init);
module_exit(hello_3_exit);