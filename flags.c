#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int __get_sign(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int n, y;
	int flags = 0;
	const char flags_s[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_m[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (y = *i + 1; format[y] != '\0'; y++)
	{
		for (n = 0; flags_s[n] != '\0'; n++)
			if (format[n] == flags_s[n])
			{
				flags |= flags_m[n];
				break;
			}

		if (flags_s[n] == 0)
			break;
	}

	*i = y - 1;

	return (flags);
}
