#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int _printf(const char *format, ...) {
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

int main() {
    _printf("Hello, World!\n");
    _printf("This is a %c test\n", 'c');
    _printf("This is a %% test\n");
    return 0;
}
