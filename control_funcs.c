#include "shell.h"

/**
 * _frees - function that frees a double pointer
 * @str: double pointer
 */
void _frees(char **str)
{
	size_t len = 0;

	if (str == NULL)
		return;

	while (str[len])
	{
		free(str[len]);
		++len;
	}

	if (str[len] == NULL)
		free(str[len]);

	free(str);
}

/**
 * envi_put - frees and prints the environ
 * @buffer: command
 * @av: command arguments
 */
void envi_put(char *buffer, char **av)
{
	free(buffer);
	_frees(av);
	print_env(environ);
	exit(EXIT_SUCCESS);
}
/**
 * bye_bye - exits
 * @av: command argument
 */
void bye_bye(char **av)
{
	_frees(av);
	exit(EXIT_SUCCESS);
}
/**
 * child_error - fork fail
 */
void child_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
/**
 * gl_error - imposible to create the getline
 * @buffer: command
 */
void gl_error(char *buffer)
{
	write(STDERR_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_FAILURE);
}
