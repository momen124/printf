#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Print a character
 * @args: Argument list
 * @flags: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_char(va_list args, flags_t *flags)
{
    int c = va_arg(args, int);
    return _putchar(c);
}

/**
 * print_str - Print a string
 * @args: Argument list
 * @flags: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_str(va_list args, flags_t *flags)
{
    char *s = va_arg(args, char *);
    int count = 0;
    int i = 0, j = 0;
    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            putchar(format[i]);
            count++;
        } else {
            
            i++;
            switch (format[i]) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    for (j = 0; s[j] != '\0'; j++) {
                        putchar(s[j]);
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
            }
        }
    }

    va_end(args);
    return count;
}

int main()
{
    _printf("Hello, World!\n");
    _printf("This is a %c test\n", 'c');
    _printf("This is a %% test\n");
    return 0;
}