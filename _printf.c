#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: string to the format
 * Return: return 1 or 0
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0, chara_print = 0;
	va_list list_of_args;

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);

				_putchar(c);
				chara_print++;
			}
			else if (*format == 's')
			{
				count = _putstr(va_arg(list_of_args, char*));
						chara_print++;
						count++;
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (chara_print);
}
