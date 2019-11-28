#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stddef.h>

extern char **environ;

/* Functions in control_funcs.c */
void gl_error(char *buffer);
void child_error(void);
void bye_bye(char **av);
void envi_put(char *buffer, char **av);
void _frees(char **str);

/* Functions in env_funcs.c */
void handler(int sig);
char *_getenv(const char *name, char **environ);
int execpath(char **av);

/* Functions in pointer_funcs.c */
char *_strcatDirCmd(char *s1, char *s2);
void print_env(char **environ);
char **strsplit(char *buffer);

/* Functions in str_funcs.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif /*SHELL_H*/
