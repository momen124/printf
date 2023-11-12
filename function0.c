#include "main.h"

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
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);

	return (count);
}

/**
 * parse_format - Parses the format string and prints corresponding values.
 * @format: The format string.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int parse_format(const char *format, va_list args)
{
	int count = 0;
	flags_t flags = {0, 0, 0}; /* Initialize flags to zero */
	int (*f)(va_list, flags_t *);
	char specifier;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1); /* Incomplete format specifier */

			while (get_flag(*format, &flags))
				format++;

			specifier = *format;
			f = get_print(specifier);

			if (f != NULL)
				count += f(args, &flags);
			else
				count += _putchar('%') + _putchar(specifier);
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	return (count);
}
