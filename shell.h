#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>


/*string functions*/
char *s_dup(const char *str);
int s_comp(const char *str1, const char *str2);
char *s_cat(char *str1, const char *str2);
int s_len(const char *str);
void s_cpy(char *str1, const char *str2);


char *read_cmd();
char **sep_cmd(char *cmd);
int exec_cmd(char **prompt, char **argv, char **env);

void free_a(char **a);
#endif /*SHELL_H*/
