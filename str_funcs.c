#include "shell.h"
/**
 * _strlen - function that gets the lenght of a string
 * @s: string
 * Return: The lenght of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * *_strcpy - copies the string
 * @dest: buffer pointed to char
 * @src: string pointed to src
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strdup - copy of the string given as a parameter
 * @str: string
 * Return: a copy of the string
 */

char *_strdup(char *str)
{
	char *a = NULL;

	if (str == '\0')
	{
		return (NULL);
	}
	a = malloc((_strlen(str) * sizeof(char)) + 1);
	if (a == '\0')
	{
		return (NULL);
	}
	_strcpy(a, str);
	return (a);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: (difference of length between the two strings)
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
