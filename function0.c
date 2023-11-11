#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            putchar(format[i]);
            count++;
        } else {
            i++; // skip the '%' character
            switch (format[i]) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    for (int j = 0; s[j] != '\0'; j++) {
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