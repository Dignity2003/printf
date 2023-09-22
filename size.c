#include "main.h"
/**
 * get_size - Calc the size.
 * @format: Formatted string.
 * @i: arguments.
 * Return: Precision.
 */
int __get_sz(const char *format, int *i)
{
	int ptr = *i + 1;
	int size = 0;

	if (format[ptr] == 'l')
		size = SZ_LONG;
	else if (format[ptr] == 'h')
		size = SZ_SHORT;
	if (size == 0)
		*i = ptr - 1;
	else
		*i = ptr;

	return (size);
}
