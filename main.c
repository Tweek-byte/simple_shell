#include "shell.h"

/**
 * main - prompt loop
 *
 * @argc: argument count.
 * @argv: argument vector.
 * @env: environment charachter.
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *cmd;
	char **prompt;
	int exit_status = 0;
	(void)argc;


	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		cmd = read_cmd();

		if (!cmd)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (exit_status);
		}

		prompt = sep_cmd(cmd);
		if (prompt == NULL)
		{
			continue;
		}

		exit_status = exec_cmd(prompt, argv, env);
	}
}
