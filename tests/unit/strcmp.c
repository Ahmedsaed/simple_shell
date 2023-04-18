#include "./../../main.h"
#include <string.h>

#define NTC 3

int main()
{
    int i, my_rv, lib_rv, rv = 0;
    char *tc[][2] = {
	    {"Test1234", "Test1234"},
	    {"Test12345", "Test1234"},
	    {"Test123", "Test1234"}
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _strcmp(tc[i][0], tc[i][1]);
		lib_rv = strcmp(tc[i][0], tc[i][1]);

		if (my_rv == lib_rv)
			continue;

        printf("Test Case %d: First String(%s), Second String(%s)\n", i, tc[i][0], tc[i][1]);
        printf("Library's Return Value: %d\n", my_rv);
        printf("My Return Value: %d\n", lib_rv);

		rv = 1;
	}

    return (rv);
}

