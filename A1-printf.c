#include "main.h"
/**
 * print_char - Prints a char
 * @list: total number of argument
 * @buff: Array named Buff(Buffer) that handle print
 * @sign: it use for calculation of active flags
 * @extent: the size of the width
 * @preceed: specifier for precision
 * @sz: specifier for size
 * Return: total number of Character printed
 */
int __print_char(va_list list, char buff[], int sign, int extent, int preceed,int sz)
{
char a = va_arg(list, int);
return (__handle_write_char(a, buff, sign, extent, preceed, sz));
}
