#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 6

int main()
{
    int i, my_rv, lib_rv, rv = 0;
    char *tc[][3] = {
	    {"Test1234", "Test1234"},
	    {"Test1234", "Test1235"},
	    {"Test1234", "Test123"},
		{"Test123", "Test1234"},
		{"Test1234", "Test12345"},
		{"Test12345", "Test1234"}
    };

    for (i = 0; i < NTC; i++)
    {
		my_rv = _strncmp(tc[i][0], tc[i][1], 15);
		lib_rv = strncmp(tc[i][0], tc[i][1], 15);

		if (my_rv == lib_rv)
			continue;

        printf("Test Case %d: First String(%s), Second String(%s), Till(%d)\n", i, tc[i][0], tc[i][1], 8);
        printf("Library's Return Value: %d\n", my_rv);
        printf("My Return Value: %d\n", lib_rv);

		rv = 1;
	}

    return (rv);
}

