#include "main.h"

int _strtok(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s string delim subdelim\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, argv[2], &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = strtok_r(str2, argv[3], &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(EXIT_SUCCESS);
}

char **get_av(char *line) {
	int idx = 0;

	char delim[] = " \t\r\n";
	char **tokenList = malloc(MAXTOKENS * sizeof(char *));
	char *token;

	if (!tokenList) {
		perror("simple shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = _strtok(line, delim);
	while (token != NULL) {
		tokenList[idx] = token;
		idx++;
		token = _strtok(NULL, delim);
	}

	tokenList[idx] = NULL;
	return tokenList;
}

