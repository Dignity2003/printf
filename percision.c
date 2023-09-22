#include "main.h"
/**
 * get_precision - clac the precision
 * @format: Formatted string
 * @i: List of arguments.
 * @list: list of arguments.
 * Return: Precision.
 */
int __get_preceed(const char *format, int *i, va_list list)
{
	int ptr = *i + 1;
	int precision = -1;

	if (format[ptr] != '.')
		return (precision);

	precision = 0;

	for (ptr += 1; format[ptr] != '\0'; ptr++)
	{
		if (is_digit(format[ptr]))
		{
			precision *= 10;
			precision += format[ptr] - '0';
		}
		else if (format[ptr] == '*')
		{
			ptr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ptr - 1;
	return (precision);
}
