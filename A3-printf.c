#include "main.h"
/**
 * __print_binary - it prints aan unsigned number
 * @list: It contains all the argument
 * @buff: Array of Buff(Buffer) to handle print
 * @sign: It checks for active flags
 * @extent: it getsthe width of the number
 * @preceed: specifiers for precision
 * @sz: specifier for size
 * Return: It returns total characters printed
 */
int __print_binary(va_list list, char buff[], int sign, int extent,
int preceed, int sz)
{
unsigned int i, j, n, sum;
unsigned int a[32];
int count;

UNUSED(buff);
UNUSED(sign);
UNUSED(extent);
UNUSED(preceed);
UNUSED(sz);

i = va_arg(list, unsigned int);
j = 2147483648; /* (2 ^ 31) */
a[0] = i / j;
for (n = 1; i < 32; n++)
{
j /= 2;
a[n] = (i / j) % 2;
}
for (n = 0, sum = 0, count = 0; n < 32; n++)
{
sum += a[n];
if (sum || n == 31)
{
char z = '0' + a[n];
write(1, &z, 1);
}
}
return (count);
}
