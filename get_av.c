#include "main.h"
char **get_av(char *line) {
	int idx = 0;

	char delim[] = " \t\r\n";
	char **tokenList = malloc(MAXTOKENS * sizeof(char *));
	char *token;

	if (!tokenList) {
		perror("simple shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token != NULL) {
		tokenList[idx] = token;
		idx++;
		token = strtok(NULL, delim);
	}

	tokenList[idx] = NULL;
	return tokenList;
}

