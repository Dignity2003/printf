#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
/*FLAGS*/
#define HASH_SIGN 8
#define ZERO_SIGN 4
#define PLUS_SIGN 2
#define SPACE_SIGN 16
#define MINUS_SIGN 1
/*SIZE*/
#define SZ_LONG 2
#define SZ_SHORT 1
/**
 * struct fomat - Struct op
 * @fomat: Format
 * @func: Functions associated
 */
struct fomat
{
char fomat;
int (*func)(va_list, char[], int, int, int, int);
} fomat_t;
/**
 * typedef struct fomat fomat_t - struct op
 * @fomat: D format
 * @fomat_t: functions associated
 */
typedef struct fomat fomat_t;
int handle_print(const char *fomat, int *i, va_list list, char buff[], int sign, int extent, int sz);
/*functions to writes characters and strings*/
int __print_char(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_str(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_percent(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*functions that prints numbers*/
int __print_int(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_binary(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_octal(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_unsigned(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_hexadecimal(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_hexa(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
int __print_hexa_upper(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*Function that prints non printable charcters*/
int __print_non_printable(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*function that prints memory of address*/
int __print_pointers(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*functions for handling other specifiers*/
int __get_sign(const char *format, int *i);
int __get_extent(const char *format, int *i, va_list list);
int __get_preceed(const char *format, int *i, va_list list);
int __get_sz(const char *format, int *i);
/*functions for string reverse*/
int __print_reverse(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*function  to print a string in rot 13*/
int __print_rot13strings(va_list list2, char buff[], int sign, int extent, int preceed, int sz);
/*functions for width handler*/
int __handle_write_char(char c, char buff[], int sign, int extent, int preceed, int sz);
int __write_number(int is_positive, int index, char buff[], int sign, int extent, int preceed, int sz);
int __write_num(int index, char buff[], int sign, int extent, int preceed, int len, char pad, char ext_c);
int __write_pointer(int index, char buff[], int sign, int extent, int preceed, int len, char pad, char ext_c, int pad_start);
int __write_unsigned(int is_negative, char buff[], int sign, int extent, int preceed, int sz);
/*utils*/
int __is_printable(char);
int __append_hexa_code(char, char[], int);
int __is_digit(char);
long int convert_size_number(long int digit, int sz);
long int convert_size_unsgnd(unsigned long int digit, int sz);
#endif /*MAIN.H*/
