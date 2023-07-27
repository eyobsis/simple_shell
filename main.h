#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
int _strlen(char *s);
char *get_command();
int check_for_bin(char *av2[100]);
void execute(char **av, int a, int count);
void execute_bin(char **av);
void env(void);
extern char **environ;
int change_directory(const char *path);
char *_getenv(char *var);
int interactive(unsigned int count);
int non_interactive(char *line);
int readline(int fd, char *buffer, int max_len);
void print_env(void);
int env_command(void);
int my_atoi(char *str);
void execute_builtins(char **av, int is_builtin);
void exit_command(int exit_status);
int set_env(char **tokens);
int unset_env(char **tokens);
#endif
