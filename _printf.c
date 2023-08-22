#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: string to the format
 * Return: return 1 or 0
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0, chara_print = 0;
	va_list list_of_args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(list_of_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(list_of_args, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				chara_print = _putstr(va_arg(list_of_args, char*));
						i++;
						count += (chara_print - 1);
			}
			else
			{
				_putchar('%');
			}
		}
		else
		{
			_putchar(format[i]);
		}
		count++;
	}
	va_end(list_of_args);
	return (count);
}
