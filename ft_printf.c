#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

void cnsn(int (*f)(va_list, int), char *b, char *t, int *i, int *j, char c)
{
	if (c == 'c')
	{
		b[*j] = (char)f( vl, int );
		*j++;
	}

	if (c == 'd')
	{
		_itoa(f( vl, int ), t, 10);
		strcpy(&b[*j], t);
		*j += strlen(t);
	}

	if (c == 'x')
	{
		_itoa(f( vl, int ), t, 16);
		strcpy(&b[*j], t);
		*j += strlen(t);
	}

	if (c == 'o')
	{
		_itoa(f( vl, int ), t, 8);
		strcpy(&b[*j], t);
		*j += strlen(t);
	}
}

/**
 * _printf - function
 * @format: the chaine
 * @...: the variadique paramettre
 *
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j=0;
	char buff[100]={0}, tmp[20];
	char *str_arg;

	va_start(vl, format);
	while (format && format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] != 's')
				cnsn(va_arg(vl, int), buff, tmp, &i, &j, format[i]);
			else
			{
				str_arg = va_arg( vl, char* );
				strcpy(&buff[j], str_arg);
				j += strlen(str_arg);
			}
			/*switch (format[i])
			{
				case 'c':
					{
						buff[j] = (char)va_arg( vl, int );
						j++;
						break;
					}
				case 'd':
					{
						_itoa(va_arg( vl, int ), tmp, 10);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
				case 'x':
					{
						_itoa(va_arg( vl, int ), tmp, 16);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
				case 'o':
					{
						_itoa(va_arg( vl, int ), tmp, 8);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
				case 's':
					{
						str_arg = va_arg( vl, char* );
						strcpy(&buff[j], str_arg);
						j += strlen(str_arg);
						break;
					}
			}*/
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout); 
	va_end(vl);
	return (j);
}

