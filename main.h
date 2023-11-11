#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct PrintFormat - Struct to represent a print format
 *
 * @specifier: The format specifier.
 * @printFunction: The function associated with the specifier.
 */
struct PrintFormat
{
    char specifier;
    int (*printFunction)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct PrintFormat PrintFormat_t - Typedef for struct PrintFormat
 *
 * @specifier: The format specifier.
 * @printFunction: The function associated with the specifier.
 */
typedef struct PrintFormat PrintFormat_t;

int my_printf(const char *format, ...);
int handle_print_format(const char *specifier, int *index,
                        va_list args, char buffer[],
                        int flags, int width, int precision, int size);

/****************** PRINT FUNCTIONS ******************/

/* Character and String Printing Functions */
int print_character(va_list args, char buffer[],
                    int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
                 int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
                  int flags, int width, int precision, int size);

/* Number Printing Functions */
int print_integer(va_list args, char buffer[],
                  int flags, int width, precision, int size);
int print_binary(va_list args, char buffer[],
                 int flags, int width, int precision, int size);
int print_unsigned_integer(va_list args, char buffer[],
                           int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
                int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
                      int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list args, char buffer[],
                            int flags, int width, int precision, int size);

/* Miscellaneous Printing Functions */
int print_non_printable(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int print_pointer_address(va_list args, char buffer[],
                          int flags, int width, int precision, int size);
int print_reversed_string(va_list args, char buffer[],
                          int flags, int width, int precision, int size);
int print_rot13_encoded_string(va_list args, char buffer[],
                               int flags, int width, int precision, int size);

/* Utility Functions */
int get_flags_from_format(const char *format, int *index);
int get_width_from_format(const char *format, int *index, va_list args);
int get_precision_from_format(const char *format, int *index, va_list args);
int get_size_from_format(const char *format, int *index);

#endif /* PRINTF_H */