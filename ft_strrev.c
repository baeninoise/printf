#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _strrev - function
 *@str: the chaine
 *
 * Return: Always 0
 */
char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

