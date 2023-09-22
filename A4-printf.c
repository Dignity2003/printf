#include "main.h"
/**
 * __print_unsigned - It prints unsigned integer
 * @list: it contains list of argument
 * @buff: Array buff (Buffer) that handle print
 * @sign: it chwcks for active flags
 * @extent: it gets the width of d number
 * @preceed: specifier for precision
 * @sz: specifier for size
 * Return: Total number of characters printed
 */
int __print_unsignd(va_list list, char buff[], int sign, int extent,
int preceed, int sz)
{
int __write_unsignd(int is_negative, int index, char buff[], int sign,
int extent, int preceed, int sz);
long int __conver_size_number(long int dig, int sz);
int i = BUFF_SIZE - 2;
unsigned long int dig = va_arg(list, unsigned int);
dig = __conver_size_number(dig, sz);
if (dig == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (dig > 0)
{
buff[i--] = (dig % 10) + '0';
dig /= 10;
}
i++;
return (__write_unsignd(0, i, buff, sign, extent, preceed, sz));
}
/**
 * __conver_size_number - allocates a specified size to a number
 * @dig: Number to be allocated
 * @sz: The size to be allocated
 * Return: Always 0
 */
long int __conver_size_number(long int dig, int sz)
{
if (sz == SZ_LONG)
return (dig);
else if (sz == SZ_SHORT)
return ((short)(dig));
return ((int)dig);
}
/**
 * __write_unsigned - it prints an unsigned number
 * @is_negative: it indicates if a number is negative
 * @index: it shows the index at which number starts on buffer
 * @buff: Array that contains character
 * @sign: specifiers for flags
 * @extent: specifiers for width
 * @preceed: specifiers for precision
 * @sz: specifiers for size
 * Return: Always 0
 */
int __write_unsignd(int is_negative, int index, char buff[], int sign,
int extent, int preceed, int sz)
{
int len = BUFF_SIZE - index - 1,  i = 0;
char pad = ' ';
UNUSED(is_negative);
UNUSED(sz);
if (preceed == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
return (0);
if (preceed > 0 && preceed < len)
pad = ' ';
for (len = BUFF_SIZE - index - 1; preceed > len; len++)
buff[--index] = '0';
if ((sign & ZERO_SIGN) && !(sign & MINUS_SIGN))
pad = '0';
if (extent > len)
{
while (i < extent - len)
{
buff[i] = pad;
i++;
}
buff[i] = '\0';
if (sign & MINUS_SIGN)
return (write(1, &buff[index], len) + write(1, &buff[0], i));
else /*it assign extra char to left of padding[pad > buff]*/
return (write(1, &buff[0], i) + write(1, &buff[index], len));
}
return (write(1, &buff[index], len));
}
