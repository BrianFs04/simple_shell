#include "shell.h"

/**
 * main - executes the shell
 * Return: Always 0
 */
int main(void)
{
	char **av, *buffer, *bye = "exit", *envs = "env";
	pid_t child;
	size_t buffsize = 1024;
	int ret = 0, status;

	signal(SIGINT, handler);
	while (1)
	{
		buffer = malloc(buffsize * sizeof(char));
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		ret = getline(&buffer, &buffsize, stdin);
		av = strsplit(buffer);
		if  (ret < 0)
			gl_error(buffer);
		else if (ret > 1)
		{
			child = fork();
			if (child == -1)
				child_error();
			if (child == 0)
			{
				if (_strcmp(av[0], envs) == 0)
					envi_put(buffer, av);
				else if (_strcmp(av[0], bye) == 0)
					bye_bye(av);
				else
					execpath(av);
				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(&status);
				if (_strcmp(av[0], bye) == 0)
					bye_bye(av);
			}
		}
		else if (ret == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
