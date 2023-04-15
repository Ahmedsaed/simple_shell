#include "./../../main.h"
#include <string.h>

#define NC 4

int main()
{
    int i, argc;
    char *cmd[] = {
        "cmd s as tetetet",
        "cmd     s tt  w",
        "ls -l /tmp",
        "ls -l /tmp  "
    };
    char *argv[MAX_ARGS + 1];

    for (i = 0; i < sizeof(cmd) / sizeof(cmd[0]); i++)
    {
        argc = parse_cmd(cmd[i], argv);

        printf("Test Case %d:\n", i);
        printf("Actual command: %s\n", cmd[i]);
        printf("Parsed command: ");
        for (int j = 0; j < argc; j++)
            printf("%s ", argv[j]);
        printf("\n");

        for (int j = 0; j < argc; j++)
            free(argv[j]);
    }

    return 0;
}
