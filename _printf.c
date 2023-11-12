#include "main.h"
#include <stdlib.h>

/**
 * itoa - Converts an integer to a string
 * @val: Integer to convert
 * @base: Number base for conversion
 *
 * Return: Pointer to the converted string
 */
char *itoa(int val, int base) {
    static char buf[32] = {0};
    int i = 30;

    for (; val && i; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i + 1];
}


/**
 * _printf - Custom printf function to format and print data
 * @format: format string containing the directives
 * 
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char ch;
    char *str;
    int val;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    ch = (char)va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    val = va_arg(args, int);
                    str = itoa(val, 10);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
