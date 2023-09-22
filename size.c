#include "main.h"
/**
 * get_size - Calculates the size.
 * @format: Formatted string.
 * @i: List of arguments.
 * Return: Precision.
 */
int __get_sz(const char *format, int *i)
{
	int ptr = *i + 1;
	int size = 0;

	if (format[ptr] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = ptr - 1;
	else
		*i = ptr;

	return (size);
}
