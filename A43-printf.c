#include "main.h"
/**
 * __print_hexadecimal - it will print unsigned number in hexadecimal notation
 * @list: It contains list of Argument
 * @buff: array buff (BUFFER) that handle print
 * @sign: it checkes for active flags
 * @extent: it gets the width of the number
 * @preceed: specifer for precision
 * @sz: specifier fo size
 * Return: it reurns number of characters printed
 */
int __print_hexadecimal(va_list list, char buff[], int sign, int extent,
int preceed, int sz)
{
int __print_hexa(va_list list, char map_to[], char buff[], int sign,
char sign_ch, int extent, int preceed, int sz);
return (__print_hexa(list, "0123456789abcdef", buff, sign, 'x', extent,
preceed, sz));
}
/**
 * __print_hexa_upper - it will print an unsigned number in upper hexadecimal
 * notation
 * @list: it contains list of argument
 * @buff: Array buff that handle print
 * @sign: it checkes for active flags
 * @extent: it gets the width of the number
 * @preceed: specifier for precision
 * @sz: specifier size
 * Return: total number printed
 */
int __print_hexa_upper(va_list list, char buff[], int sign, int extent,
int preceed, int sz)
{
int __print_hexa(va_list list, char map_to[], char buff[], int sign,
char sign_ch, int extent, int preceed, int sz);
return (__print_hexa(list, "0123456789ABCDEF", buff, sign, 'X', extent,
preceed, sz));
}
/**
 * __print_hexa - it will print a hexadecimal in upper or in lower
 * @list: it contains the list of arguments
 * @map_to: array to map number to
 * @buff: array buff handles print
 * @sign: it checks for active flags
 * @sign_ch: it checks for active flags
 * @extent: it gets the width of the number
 * @preceed: specifier for precision
 * @sz: size specifier
 * @sz: size specifier
 * Return: it Returns the total number of character printed
 */
int __print_hexa(va_list list, char map_to[], char buff[], int sign,
char sign_ch, int extent, int preceed, int sz)
{
long int __convert_size_unsignd(unsigned long int dig, int sz);
int __write_unsignd(int is_negative, int index, char buff[], int sign,
int extent, int preceed, int sz);
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(list, unsigned long int);
unsigned long int initial_num = num;
UNUSED(extent);
num = __convert_size_unsignd(num, sz);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = map_to[num % 16];
num /= 16;
}
if (sign & HASH_SIGN && initial_num != 0)
{
buff[i--] = sign_ch;
buff[i--] = '0';
}
i++;
return (__write_unsignd(0, i, buff, sign, extent, preceed, sz));
}
/**
 * __convert_size_unsignd - it changes the datatype of a number with a
 * specified size * @dig: the number to be changed
 * @sz: It indicates the datatype to change the number to
 * Return: Always 0
 */
long int __convert_size_unsignd(unsigned long int dig, int sz)
{
if (sz == SZ_LONG)
{
return (dig);
}
else if (sz == SZ_SHORT)
{
return ((unsigned short) dig);
}
return ((unsigned int) dig);
}
/**
 * __write_unsignd - it prints an unsigned number
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
