#include "main.h"
/**
 * _printf1 - function that produces output according to a format
 * @format: string to the format
 * Return: return 1 or 0
 */
int _printf1(const char *format, ...)
{
	int count = 0;
	const char *ptr = format;
	va_list args;
	va_start(args, format);

	while (*ptr != '\0')
	{
		if(*ptr == 'd' || *ptr == 'i')
		{
			int num = va_arg(args, int);
			printf("%d", num);
			count++;
		}
		else if (*ptr == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar(*ptr);
			count++;
		}
	}
	ptr++;
	va_end(args);
	return count;
}
