#ifndef MAIN_H
#define MAIN_H

#define NULL_STRING "(null)"

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/** Sizes **/
#define SIZES_SHORT 1
#define SIZES_LONG 2


/** Flags **/
#define FLAGS_ZERO 4
#define FLAGS_PLUS 2
#define FLAGS_SPACE 16
#define FLAGS_MINUS 1
#define FLAGS_HASH 8

long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);

/**
 * struct format - Defines a structure for symbols and functions
 *
 * @Fmt: The Format
 * @Fn: The function associated
 */
struct format
{
	char Fmt;
	int (*Fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct Fmt Fmt_t - struct to choose the right function depending
 *
 * @Fmt: The format.
 * @Fmt_t: The function associated.
 */
typedef struct Fmt Fmt_t;

int _printf(const char *format, ...);
int Handle_printf(const char *Fmt, int *I,
va_list list, char buf[], int flag, int wid, int preci, int size);

/** THE FUNCTIONS **/

/** For numbers **/

int print_hexa(va_list ap, char map_t[],
char buf[], int flag, char flag_2, int wid, int preci, int size);

int print_binary(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_octal(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_int(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_unsigned(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_hexa_upper(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_hexadecimal(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

/** For width handler **/

int Handle_write_pointer(char buf[], int ind, int len,
	int wid, int flag, char Padd, char extra_ch, int Padd_start);

int Handle_write_char(char c, char buf[],
	int flag, int wid, int preci, int size);

int Handle_write_number(int posi_tive, int ind, char buf[],
	int flag, int wid, int preci, int size);

int Handle_write_unsgnd(int nega_tive, int ind, char buf[],
	int flag, int wid, int preci, int size);

int Handle_write_num(int ind, char buf[], int flag, int wid, int preci,
	int len, char Padd, char extra_ch);

/** For chars and strings **/

int print_percent(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_string(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

int print_char(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

/** For non printable characters **/

int print_non_printable_c(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

/** To handle other specifiers **/

int get_precision(const char *format, int *j, va_list list);

int get_flags(const char *format, int *j);

int get_size(const char *format, int *j);

int get_width(const char *format, int *j, va_list list);

/** For memory address **/

int print_pointer(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

/**For string in rot 13**/

int print_rot13_string(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

/**For string in reverse**/

int print_reverse(va_list ap, char buf[],
	int flag, int wid, int preci, int size);

#endif
