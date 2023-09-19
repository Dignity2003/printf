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
write(1, &;
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
putchar(va_arg(list, int));
total_char++;
}
}
va_end(list);
return (total_char);
}

/**
 * _strlen - it prints the length of a string
 * @str: the string
 * Return: Always 0
 */
int _strlen(char *str)
{
int i = 0;
