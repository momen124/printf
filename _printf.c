#include "main.h"

/**
 * _printf - a simple printf function to format and print data
 * @format: format string containing the directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format && format[i]; i++)
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                {
                    char *str = va_arg(args, char*);
                    if (str == NULL) str = "(null)";
                    for (int j = 0; str[j]; j++, count++)
                        putchar(str[j]);
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += putchar(format[i]);
        }
    }

    va_end(args);
    return count;
}
