#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define SPECIFIERS_SIZE 14
#define LENGTH_SPECS_SIZE 8
#define FLAGS_SPECS_SIZE 6

#define ERROR -2
#define INVALID -1
#define EMPTY 0
#define OK 1

/**
 * struct spec_data - specifiers data
 *
 * @spec_flags: - +   0 ' #
 * @spec_width: minimum number of characters to output
 * @spec_prec: maximum limit on the output, depending on the type
 * @spec_length: hh h l ll L z j t
 * @fmt_spec: % d,i u f,F e,E g,G x,X o s,S c p a,A n b r,R
 * @fmt_len: length of the format specifier
 * @status: return value of extract functions
 */

typedef struct spec_data
{
	char fmt_spec;
	char *spec_length;
	int spec_prec;
	int spec_width;
	char *spec_flags;
	int fmt_len;
	int status;
} spec_data_t;

/**
 * struct pf_buf - _printf buffer
 *
 * @buf: the buffer
 * @len: the size of the string to add to main buffer
 * @index: index of last char in main buffer
 */

typedef struct pf_buf
{
	char *buf;
	int len;
	int index;
} pf_buf_t;

/**
 * struct specs - specifiers structure containing associated funcions
 *
 * @spec: the specifier
 * @func: the print function associated to the specifier
 */

typedef struct specs
{
	char spec;
	pf_buf_t *(*func)(va_list, spec_data_t*);
} specs_t;

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_bnr(va_list arguments, char *buf, unsigned int ibuf);
int print_unt(va_list arguments, char *buf, unsigned int ibuf);
int print_oct(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_upx(va_list arguments, char *buf, unsigned int ibuf);
int print_usr(va_list arguments, char *buf, unsigned int ibuf);
int print_add(va_list arguments, char *buf, unsigned int ibuf);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int prinlint(va_list arguments, char *buf, unsigned int ibuf);
int prinlunt(va_list arguments, char *buf, unsigned int ibuf);
int prinloct(va_list arguments, char *buf, unsigned int ibuf);
int prinlhex(va_list arguments, char *buf, unsigned int ibuf);
int prinlupx(va_list arguments, char *buf, unsigned int ibuf);
int prinhint(va_list arguments, char *buf, unsigned int ibuf);
int prinhunt(va_list arguments, char *buf, unsigned int ibuf);
int prinhoct(va_list arguments, char *buf, unsigned int ibuf);
int prinhhex(va_list arguments, char *buf, unsigned int ibuf);
int prinhupx(va_list arguments, char *buf, unsigned int ibuf);
int prinpint(va_list arguments, char *buf, unsigned int ibuf);
int prinnoct(va_list arguments, char *buf, unsigned int ibuf);
int prinnhex(va_list arguments, char *buf, unsigned int ibuf);
int prinnupx(va_list arguments, char *buf, unsigned int ibuf);
int prinsint(va_list arguments, char *buf, unsigned int ibuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);
char *extract_format(const char *format, int size);
char *extract_length(char *str, spec_data_t *data);
int extract_prec(char *str, spec_data_t *data);
int extract_width(char *str, spec_data_t *data);
char *extract_flags(char *str, spec_data_t *data);
void *spec_data_t_delete(spec_data_t *data);
spec_data_t *spec_data_t_new(void);
int spec_data_t_parse(spec_data_t *data, const char *format);
int spec_data_t_leave(char *str, int status);
int is_in_format_specifiers(char c)

#endif
