#include "shell.h"

/**
 * read_cmd - returns command from prompt
 *
 * Return: returns command string.
 */
char *read_cmd()
{
	char *cmd = NULL;
	size_t length = 0;
	ssize_t nread = getline(&cmd, &length, stdin);

	if (nread == -1)
	{
		free(cmd);
		cmd = NULL;
		return (NULL);
	}

	return (cmd);
}

/**
 * sep_cmd - tokenizes string command from cmd (read_cmd).
 * @cmd: string returned from read_cmd.
 *
 * Return: tokenized string
 */
char **sep_cmd(char *cmd)
{
	char **prompt = NULL;
	char *token, *temp = NULL;
	int i = 0, tokens = 0;

	temp = s_dup(cmd);

	token = strtok(temp, " \n\t");
	if (!token)
	{
		free(cmd);
		cmd = NULL;
		free(temp);
		temp = NULL;
		return (NULL);
	}
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, " \n\t");
	}
	free(temp);
	temp = NULL;
	prompt = malloc(sizeof(char *) * (tokens + 1));
	if (prompt == NULL)
	{
		free(cmd);
		cmd = NULL;
		return (NULL);
	}
	token = strtok(cmd, " \n\t");
	while (token != NULL && i < tokens)
	{
		prompt[i++] = s_dup(token);
		token = strtok(NULL, " \n\t");
	}
	free(cmd);
	cmd = NULL;
	prompt[i] = NULL;
	return (prompt);
}

/**
 * exec_cmd - executes cmd with execve.
 * @prompt: command to execute.
 * @argv: argument vector.
 * @env: environment char (local).
 *
 * Return: exit status
 */
int exec_cmd(char **prompt, char **argv, char **env)
{
	pid_t sub_pid;
	int exit_status;

	sub_pid = fork();

	if (sub_pid == 0)
	{
		if (execve(prompt[0], prompt, env) == -1)
		{
			perror(argv[0]);
			free_a(prompt);
			exit(0);
		}
	}

	else
	{
		waitpid(sub_pid, &exit_status, 0);
		free_a(prompt);
	}

	return (WEXITSTATUS(exit_status));
}


/**
 * free_a - frees a 2D array of strings.
 * @a: pointer to array to free
 *
 * Return: void
 */
void free_a(char **a)
{
	int i = 0;

	if (a == NULL)
	{
		return;
	}

	while (a[i])
	{
		free(a[i++]);
	}

	free(a);
}
