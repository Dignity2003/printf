#include "main.h"
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
int __handle_write_char(char c, char buff[], int sign, int extent, int preceed, int sz)
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
return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE -i -1], extent - 1));
else
return (write(1, &buff[BUFF_SIZE -i - 1], extent - 1) + write(1, &buff[0], 1));
}
return (write(1, &buff[0], 1));
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
int __write_num(int index, char buff[], int sign, int extent, int preceed, int len, char pad, char ext_c);
int __write_number(int is_negative, int index, char buff[], int sign, int extent, int preceed, int sz)
{
int len = BUFF_SIZE - index - 1;
char pad = ' ', ext_c = 0;
UNUSED(sz);
if((sign & ZERO_SIGN) && !(sign & MINUS_SIGN))
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
int __write_num(int index, char buff[], int sign, int extent, int preceed, int len, char pad, char ext_c)
{
int i, pad_start = 1;
if (preceed == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && extent == 0)
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
for(i = 1; i < extent - len + 1; i++)
buff[i] = pad;
buff[i] = '\0';
if (sign & MINUS_SIGN && pad == ' ') /* it asigns extra character to the left of the buffer*/
{
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[1], i - 1) + write(1, &buff[index], len));
}
else if (!(sign & MINUS_SIGN && pad == '0'))/*extra character to the left*/
{
if (ext_c)
buff[--pad_start] = ext_c;
return (write(1, &buff[--pad_start], i - pad_start) + write(1, &buff[index], len - (1 - pad_start)));
}
}
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[index], len));
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
int __write_unsigned(int is_negative, int index, char buff[], int sign, int extent, int preceed, int sz)
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
if (sign & MINUS_SIGN) /*It assign extra character to the left of the buffer[buff > pad]*/
return (write(1, &buff[index], len) + write(1, &buff[0], i));
else /*it assign extra char to left of padding[pad > buff]*/
return (write(1, &buff[0], i) + write(1, &buff[index], len));
}
return (write(1, &buff[index], len));
}
/**
 * __write_pointer - it prints a memory address
 * @buffer: array that contain charachter
 * @index: it shows the index at which th number start in the buffer
 * len: the length of the number
 * @extent: specifier for the width
 * @sign: specifier for  flags
 * @pad: pads charscters
 * @ext_c: extra character
 * @pad_start: it is the index at wich padding sholud start
 * Return: Total number printed
 */
int __write_pointer(char buff[], int index, int len, int extent, int sign, char pad, char ext_c, int pad_start)
{
int i = 3;
if (extent > len)
{
while (i < extent - len + 3)
{
buff[i] = pad;
i++;
}
buff[i] ='\0';
if (sign & MINUS_SIGN && pad == ' ')
{
buff[--index] = 'x';
buff[--index] = '0';
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[index], len) + write(1, &buff[3], i - 3));
}
else if (!(sign & MINUS_SIGN) && pad == ' ')/*extra char to the left of buff*/
{
buff[--index] = 'x';
buff[--index] = '0';
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[3], i - 3) + write(1, &buff[index], len));
}
else if (!(sign & MINUS_SIGN) && pad == '0') /*it adds character to the left of pad*/
{
if (ext_c)
buff[--pad_start] = ext_c;
buff[1] = '0';
buff[2] = 'x';
return (write(1, &buff[pad_start], i - pad_start) + write(1, &buff[index], len - (1 - pad_start) - 2));
}
}
buff[--index] = 'x';
buff[--index] = '0';
if (ext_c)
buff[--index] = ext_c;
return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
