#include "main.h"
/**
 * __is_printable - it checks if a character is printable
 * @c: character to be checked
 * Return: Always 0
 */
int __is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}
/**
 * __append_hexa_code - appends ASCII code in hexadecimal code to buffer
 * @buffer: Array of chars
 * @i: index at which to start appending
 * @ascii: ASCII code
 * Return: Always three
 */
int append_hexa_code(char ascii, char buff[], int i)
{
char map[] = "0123456789ABCDEF";
/*hexa format code is always 2 digits long*/
if (ascii < 0)
ascii *= -1;
buff[i++] = '\\';
buff[i++] = 'x';
buff[i++] = map[ascii / 16];
buff[i] = map[ascii % 16];
return (3);
}
/**
 * __is_digit - checks if a character is an inted
 * @c: Character to be checked
 * Return: if c is an integer return 1, else 0
 */
int __is_digit(char c)
{
if (c >= '0' && c <= '9')
{
return (1);
}
return (0);
}
/**
 * __convert_size_number - allocates a specified size to a number
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
 * convert_size_unsigned - it changes the datatype of a number with a specified size
 * @dig: the number to be changed
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
