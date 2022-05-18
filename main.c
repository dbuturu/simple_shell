#include "main.h"
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	ssize_t stat;
	int status;
	char *prompt;
	size_t len = 0;
	char *line = NULL;
	char **args;
	pid_t pid;

	prompt = "($)";

	while (stat)
	{
		if (isatty(0))
		{
			if (pid != 0)
			{
				wait();
			}
			write(1, prompt, 3);
			stat = getline(&line, &len, stdin);
		}
		if (feof(stdin))
			return (0);
		args = get_av(line);

		if (args[0] == NULL)
			continue;
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		pid = fork();
		status = execute(args, pid);
		fflush(stdout);
	}
	return ((int)stat);
}

int execute(char **args, pid_t pid)
{
	char *envs[] = {NULL};

	if (args[0] == NULL)
		return (1);

	if (strcmp(args[0], "exit") == 0)
		return (0);

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "simple shell: expected argument to \"cd\"\n");
		} else
		{
			if (chdir(args[1]) != 0)
				perror("simple shell");
		}

		return (1);
	}

	if (pid == 0)
	{

		if (execve(args[0], args, envs) == -1)
			perror("basic shell");

		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("basic shell");
	}

	return (1);
}

