#include "main.h"
/**
 * _printf - It prints out data
 * @format: The format we want to print something out on the buffer
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
va_list list;
char *str;
int i, j, total_char = 0;
va_start(list, format);
if (format == NULL)
return (-1);
for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
putchar(format[i]);
total_char++;
}
else
i++;
if (format[i] == '\0')
break;
if (format[i] == 'c')
{
putchar(va_arg(list, int));
total_char++;
}
if (format[i] == 's')
{
str = va_arg(list, char *);
if (str != NULL)
for (j = 0; str[j]; j++)
{
putchar(str[j]);
total_char++;
}
}
if (format[i] == '%')
{
putchar('%');
total_char++;
}
}
return (total_char);
va_end(list);
}
