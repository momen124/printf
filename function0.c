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
            format++; 
            switch (*format)
            {
            case 'c':
               
                putchar(va_arg(args, int));
                count++;
                break;
            case 's':
               
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
                
                putchar('%');
                count++;
                break;
            default:
                
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

int main(void)
{
    
    int characters_printed = _printf("This is a character: %c\n", 'A');
    printf("Number of characters printed: %d\n", characters_printed);

    characters_printed = _printf("This is a string: %s\n", "Hello, World!");
    printf("Number of characters printed: %d\n", characters_printed);

    characters_printed = _printf("This is a percent sign: %%\n");
    printf("Number of characters printed: %d\n", characters_printed);

    return (0);
}
