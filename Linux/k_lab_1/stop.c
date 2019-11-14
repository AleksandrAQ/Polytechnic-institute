/*
* stop.c - Пример модуля, исходный текст которого размещен в нескольких файлах
*/
#include <linux/kernel.h>
#include <linux/module.h>
/* Все-таки мы пишем код ядра! */
/* Необходим для любого модуля ядра */
void cleanup_module()
{
printk("<1>Short is the life of a kernel module\n");
}