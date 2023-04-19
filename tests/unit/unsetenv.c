#include "./../../main.h"
#include <string.h>

#define NTC 1

/**
 * INCOMPLETE
 */

int main()
{
    int i, rv = 0;
	char *val;
	int my_rvSet, my_rvUnSet;
    char *tc[][1] = {
		{"env1_test"},
		{""},
		{"hamada="},
		{NULL}
	};

    for (i = 0; i < NTC; i++)
    {
		setenv(tc[i][0], "testCase", 0);
		getenv(tc[i][0]);
		_unsetenv(tc[i][0]);
		/*
		val = getenv(tc[i][0]);

		if (val == NULL)
			continue;
*/
        printf("Test Case %d: Name(%s)\n", i, tc[i][0]);
        printf("My Return Value: %s\n", getenv(tc[i][0]));

		rv = 1;
	}

	return (rv);
}
