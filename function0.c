#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
            case 'c':
                /* Print a character */
                putchar(va_arg(args, int));
                count++;
                break;
            case 's':
                /* Print a string */
                {
                    const char *str = va_arg(args, const char *);
                    while (*str)
                    {
                        putchar(*str);
                        count++;
                        str++;
                    }
                }
                break;
            case '%':
                /* Print a percent sign */
                putchar('%');
                count++;
                break;
            default:
                /* Invalid specifier, ignore */
                break;
            }
        }
        else
        {
            /* Regular character, just print it */
            putchar(*format);
            count++;
        }

        format++; /* Move to the next character in the format string */
    }

    va_end(args);

    return count;
}

int main(void)
{
    /* Example usage */
    int characters_printed = _printf("This is a character: %c\n", 'A');
    printf("Number of characters printed: %d\n", characters_printed);

    characters_printed = _printf("This is a string: %s\n", "Hello, World!");
    printf("Number of characters printed: %d\n", characters_printed);

    characters_printed = _printf("This is a percent sign: %%\n");
    printf("Number of characters printed: %d\n", characters_printed);

    return (0);
}
