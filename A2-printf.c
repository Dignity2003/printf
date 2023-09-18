#include "main.h"
/**
 * _printf - It prints out data
 * @format: The format we want to print something out on the buffer
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
va_list list;
int a, total_char = 0;
va_start(list, format);
if (format == NULL)
return (-1);
for (a = 0; format[a]; a++)
{
if (format[a] != '%')
{
putchar(format[a]);
total_char++;
}
else
{
a++;
if (format[a] == '\0')
break;
if (format[a] == 'd')
{
putchar(va_arg(list, int));
total_char++;
}
if (format[a] == 'i')
{
putchar(va_arg(list, int));
total_char++;
}
}
}
va_end(list);
return (total_char);
}
