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

    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        count += _putchar(*s);
        s++;
    }

    return count;
}

/**
 * print_percent - Print a percent character
 * @args: Argument list
 * @flags: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_percent(va_list args, flags_t *flags)
{
    (void)args;
    (void)flags;
    return _putchar('%');
}

/**
 * get_print - Select the appropriate printing function based on the specifier
 * @specifier: The conversion specifier
 * Return: A pointer to the appropriate printing function
 */
int (*get_print(char specifier))(va_list, flags_t *)
{
    switch (specifier)
    {
    case 'c':
        return print_char;
    case 's':
        return print_str;
    case '%':
        return print_percent;
    default:
        return NULL;
    }
}

/**
 * _printf - Produce output according to a format
 * @format: Format string containing the characters and the specifiers
 * Return: Length of the formatted output string
 */
int _printf(const char *format, ...)
{
    int (*pfunc)(va_list, flags_t *);
    const char *p;
    va_list arguments;
    flags_t flags = {0, 0, 0};

    register int count = 0;

    va_start(arguments, format);
    if (!format)
        return (-1);
    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == '%')
            {
                count += _putchar('%');
                continue;
            }
            while (get_flag(*p, &flags))
                p++;
            pfunc = get_print(*p);
            count += (pfunc)
                         ? pfunc(arguments, &flags)
                         : _printf("%%%c", *p);
        }
        else
            count += _putchar(*p);
    }
    _putchar(-1);
    va_end(arguments);
    return count;
}

int main()
{
    _printf("Hello, World!\n");
    _printf("This is a %c test\n", 'c');
    _printf("This is a %% test\n");
    return 0;
}