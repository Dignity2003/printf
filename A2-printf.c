#include "main.h"
/**
 * __print_int - it prints  digits
 * @list: it contains all the argument
 * @buff: Array buff(Buffer) that handle print
 * @sign: it checks for active flags
 * @extent: it gets the width of the number
 * @preceed: specifiers for precision
 * @sz: Specifiers for size
 * Return: It return total number printed
 */
int __print_int(va_list list, char buff[], int sign, int extent, int preceed
, int sz)
{
long int __conver_size_number(long int dig, int sz);
int __write_number(int is_negative, int index, char buff[], int sign,
int extent, int preceed, int sz);
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int j = va_arg(list, long int);
unsigned long int n;
j = __conver_size_number(n, sz);
if (j == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
n = (unsigned long int)j;
if (j < 0)
{
n = (unsigned long int)((-1) * j);
is_negative = 1;
}
while (n > 0)
{
buff[i--] = (n % 10) + '0';
n /= 10;
}
i++;
return (__write_number(is_negative, i, buff, sign, extent, preceed, sz));
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
 * __write_number - it prints strings
 * @is_negative: argument list
 * @index: charcter types
 * @buff: it handles print
 * @sign: it use for calculating active flags
 * @extent: it is for getting the width
 * @preceed: specifiers for precision
 * @sz: specifier for size
 * Return: Always 0
 */
int __write_number(int is_negative, int index, char buff[], int sign,
int extent, int preceed, int sz)
{
int __write_num(int index, char buff[], int sign, int extent,
int preceed, int len, char pad, char ext_c);
int len = BUFF_SIZE - index - 1;
char pad = ' ', ext_c = 0;
UNUSED(sz);
if ((sign & ZERO_SIGN) && !(sign & MINUS_SIGN))
pad = '0';
if (is_negative)
ext_c = '-';
else if (sign & PLUS_SIGN)
ext_c = '+';
else if (sign & SPACE_SIGN)
ext_c = ' ';
return (__write_num(index, buff, sign, extent, preceed, len, pad, ext_c));
}
/**
 * __write_num - It prints a number using buffer
 * @index: it shows the index at which the number starts on the buffer
 * @buff: Buffer Array
 * @sign: it is the flags
 * @extent: for getting the widths
 * @preceed: specifier for precision
 * @len: the numbers length
 * @pad: pads character
 * @ext_c: extra charcter
 * Return: Always 0
 */
int __write_num(int index, char buff[], int sign, int extent, int preceed,
int len, char pad, char ext_c)
{
int i, pad_start = 1;
if (preceed == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && extent == 0
)
return (0); /*printf(".0d",0) no charcter is printed*/
if (preceed == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
buff[index] = pad = ' '; /*width is displayed with padding ' '*/
if (preceed > 0 && preceed < len)
pad = ' ';
while (preceed > len)
buff[--index] = '0', len++;
if (ext_c != 0)
len++;
if (extent > len)
{
for (i = 1; i < extent - len + 1; i++)
buff[i] = pad;
buff[i] = '\0';
if (sign & MINUS_SIGN && pad == ' ')
{
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[1], i - 1) + write(1, &buff[index], len));
}
else if (!(sign & MINUS_SIGN && pad == '0'))/*extra character to the left*/
{
if (ext_c)
buff[--pad_start] = ext_c;
return (write(1, &buff[--pad_start], i - pad_start) + write(1, &buff[index],
len - (1 - pad_start)));
}
}
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[index], len));
}
