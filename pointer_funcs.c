#include "shell.h"

/**
 * _strcatDirCmd - concatenates a command with a path
 *
 * @s1: the path
 * @s2: the command
 * Return: pointer to the new str
 */

char *_strcatDirCmd(char *s1, char *s2)
{
	char *newstr;
	int len1, len2, i, j;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	newstr = malloc(len1 + len2 + 2);

	for (i = 0; s1[i] != '\0'; i++)
	{
		newstr[i] = s1[i];
	}
	newstr[i] = '/';
	i++;

	for (j = 0; s2[j] != '\0'; j++)
	{
		newstr[i] = s2[j];
		i++;
	}

	newstr[i] = '\0';
	return (newstr);
	free(newstr);
}

/**
 * print_env - prints the environment for testing purposes
 *
 */

void print_env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * strsplit - splits a string into an array of substrings
 *
 * @buffer: the string passed
 *
 * Return: a double pointer to the new array
 */
char **strsplit(char *buffer)
{
	int i, len;
	char **res;
	char *tmp;
	char *dupl = _strdup(buffer);

	len = _strlen(dupl);
	res = malloc((len + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	tmp = strtok(dupl, " \n\t");
	i = 0;

	while (tmp != NULL)
	{
		res[i] = malloc(_strlen(tmp) + 1);
		if (res[i] == NULL)
		{
			_frees(res);
			return (NULL);
		}
		_strcpy(res[i], tmp);
		tmp = strtok(NULL, " \n\t");
		++i;
	}
	res[i] = NULL;
	return (res);
}
