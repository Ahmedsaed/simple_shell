#include "./../../main.h"

#define NC 4

int main()
{
	int i, n, j;
	char *cmd[NC];
	char **argv;
	
	cmd[0] = "cmd s as tetetet";
	cmd[1] = "cmd     s tt  w";
	cmd[2] = "ls -l /tmp";
	cmd[3] = "ls -l /tmp  ";

	for (i = 0; i < NC; i++)
	{
		n = parse_cmd(cmd[0], argv);
		
		printf("Test Case %d:\n", i);
		printf("Actual command: %s\n", cmd[i]);
		printf("Pasrsed command: ");
		for (j = 0; argv[j] != NULL; j++)
			printf("%s ", argv[j]);
		printf("\n");
	}

	free(argv);

	return (1);
}
