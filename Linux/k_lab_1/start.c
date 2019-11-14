/*
* start.c - Пример модуля, исходный текст которого размещен в нескольких
файлах
*/
#include <linux/kernel.h>
#include <linux/module.h>
/* Все-таки мы пишем код ядра! */
/* Необходим для любого модуля ядра */
int init_module(void)
{
printk("Hello, world - this is the kernel speaking\n");
return 0;
}