#include "main.h"

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

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                ch = (char)va_arg(args, int);
                putchar(ch);
                count++;
                break;
            case 's':
                str = va_arg(args, char *);
                while (*str)
                {
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
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
