#include "main.h"
/**
 * get_width - Calc the width.
 * @format: Formatted string.
 * @i: arguments.
 * @list:arguments.
 * Return: width.
 */
int __get_extent(const char *format, int *i, va_list list)
{
	int ptr;
	int width = 0;

	for (ptr = *i + 1; format[ptr] != '\0'; ptr++)
	{
		if (__is_digit(format[ptr]))
		{
			width *= 10;
			width += format[ptr] - '0';
		}
		else if (format[ptr] == '*')
		{
			ptr++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ptr - 1;

	return (width);
}
