#include "shell.h"

/**
 * handler - receives a signal from keyboard
 * @sig: the type of signal
 */
void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * _getenv -gets the value of an environment variable
 * @name: name of the variable
 * @environ: ponter to the environment
 * Return: pointer to the value.
 */

char *_getenv(const char *name, char **environ)
{
	int i;
	char *ep;

	i = 0;
	while (environ[i] != NULL)
	{
		ep = strtok(environ[i], "=");
		if (_strcmp(ep, (char *)name) == 0)
		{
			ep = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ep);
}

/**
 * execpath - executes a function adding the path to it if it's not present
 * @av: a pointer to the array of strings containing the arguments.
 * Return: On success 0
 */

int execpath(char **av)
{
	struct stat st;
	char *path;
	char *ruta;
	unsigned int i;

	path = _getenv("PATH", environ);
	path = strtok(path, "=:");
	i = 0;
	while (path != NULL)
	{
		ruta = _strcatDirCmd(path, av[0]);
		if (stat(ruta, &st) == 0)
		{
			av[0] = malloc(_strlen(ruta) + 1);
			_strcpy(av[0], ruta);
			break;
		}
		path = strtok(NULL, "=:");
		i++;
	}
	execve(av[0], av, NULL);
	write(2, "Error\n", 6);
	free(path);
	free(ruta);
	_frees(av);
	exit(EXIT_SUCCESS);
}
