#include "./../../main.h"
#include <string.h>

#define NC 3

int main()
{
    int i, argc, rv = 0;
    char *s;
    char *cmd[][2] = {
	    {"cmd s as tetetet\n", "cmd s as tetetet"},
	    {"cmd     s tt  w\n", "cmd s tt w"},
	    {"ls -l /tmp\n", "ls -l /tmp"},
    };
    char *argv[MAX_ARGS + 1];

    for (i = 0; i < NC; i++)
    {
        argc = parse_cmd(cmd[i][0], argv);

	s = malloc(sizeof(char) * strlen(cmd[i][1]) * 2);
	s[0] = '\0';

        for (int j = 0; argv[j] != NULL; j++)
	{
		s = strcat(s, argv[j]);
		if (j < argc - 1)
			s = strcat(s, " ");
	}

	if (strcmp(cmd[i][1], s) == 0)
		continue;

        printf("Test Case %d:\n", i);
        printf("Actual command: %s", cmd[i][0]);
        printf("Parsed command: %s\n", s);

	rv = 1;
    }

	for (int j = 0; j < argc; j++)
		free(argv[j]);
	free(s);	

    return (rv);
}
