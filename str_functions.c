#include "shell.h"

/**
 * s_dup - duplicates a string
 * @str: string to duplicate
 *
 * Return: duplicated string, NULL if fails.
 */
char *s_dup(const char *str)
{
	int len = 0, i;
	char *c;

	if (!str)
		return (NULL);

	while (str[len])
	{
		len++;
	}

	c = malloc(sizeof(char) * (len + 1));

	if (!c)
		return (NULL);

	i = 0;

	while (i < len)
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

/**
 * s_comp - compares two strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: difference.
 */
int s_comp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * s_cat - concatenates two strings
 * @str1: destination string.
 * @str2: source string.
 *
 * Return: concatenated string.
 */
char *s_cat(char *str1, const char *str2)
{
	char *c = str1;

	while (*c != '\0')
	{
		c++;
	}

	while (*str2 != '\0')
	{
		*c = *str2;
		c++;
		str2++;
	}

	*c = '\0';

	return (str1);

}

/**
 * s_len - returns string length.
 * @str: string of input.
 *
 * Return: string length.
 */
int s_len(const char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}

	return (len);
}

/**
 * s_cpy - copies string.
 * @str1: destination string.
 * @str2: source string.
 *
 * Return: void.
 */
void s_cpy(char *str1, const char *str2)
{
	while ((*str1++ = *str2++))
		;
}
