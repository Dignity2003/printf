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
int __print_char(va_list list, char buff[], int sign, int extent, int preceed,
int sz)
{
int __handle_write_char(char c, char buff[], int sign, int extent, int preceed,
int sz);
char a = va_arg(list, int);
return (__handle_write_char(a, buff, sign, extent, preceed, sz));
}
/**
 * __handle_write_char - It prints a string
 * @c: character
 * @buff: It is a Buffer array that handle printing
 * @sign: it is used for calculating active flags
 * @extent: it gets width
 * @preceed: specifier for precision
 * @sz: specifier for size
 * Return: Always 0
 */
int __handle_write_char(char c, char buff[], int sign, int extent, int preceed,
int sz)
{
int i = 0;
char pad = ' ';
UNUSED(preceed);
UNUSED(sz);

if (sign & ZERO_SIGN)
pad = '0';

buff[i++] = c;
buff[i] = '\0';
if (extent > 1)
{
buff[BUFF_SIZE] = '\0';
i = 0;
while (i < extent - 1)
buff[BUFF_SIZE - i - 2] = pad;
i++;
if (sign & MINUS_SIGN)
return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE - i - 1], extent - 1)
);
else
return (write(1, &buff[BUFF_SIZE - i - 1], extent - 1) + write(1, &buff[0], 1)
);
}
return (write(1, &buff[0], 1));
}
/**
 * __prints_string - it prints a string
 * @list: it is the total number of argument inputted
 * @buff: an Array buff(buffer) that handle print
 * @sign: It calculates active flags
 * @extent: it gets the width of the numbers to be printed
 * @preceed: specification for precision
 * @sz: specification for size
 * Return: total Number printed
 */
int __print_string(va_list list, char buff[], int sign, int extent, int preceed
, int sz)
{
int len, i;
char *str = va_arg(list, char *);
UNUSED(buff);
UNUSED(sign);
UNUSED(extent);
UNUSED(preceed);
UNUSED(sz);
if (str == NULL)
{
str = "(null)";
if (preceed >= 6)
str = "      ";
}
for (len = 0; str[len] != '\0'; len++)
;
if (preceed >= 0 && preceed < len)
len = preceed;

if (extent > len)
{
if (sign & MINUS_SIGN)
{
write(1, &str[0], len);
for (i = extent - len; i > 0; i--)
write(1, " ", 1);
return (extent);
}
}
return (write(1, str, len));
}
/**
 * __print_percent - it prints a percent character
 * @list: it contains all the argument
 * @buff: Array of buff(buffer) that handle print
 * @sign: it calculates total active flags
 * @extent: it gets the width of the number
 * @preceed: specifier for preicision
 * @sz: specifier for size
 * Return: It retunr total nuumber printed
 */
int __print_percent(va_list list, char buff, int sign, int extent, int preceed
, int sz)
{
UNUSED(list);
UNUSED(buff);
UNUSED(sign);
UNUSED(extent);
UNUSED(preceed);
UNUSED(sz);
return (write(1, "%%", 1));
}
