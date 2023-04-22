#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 2

/**
 * NTC is set to 2
 * so that the 3rd,4th and 5th test cases
 * that print out errors as they should
 * don't print them out to make the
 * application of "make" in the terminal cleaner.
 */

int main()
{
	int i, my_rv, lib_rv, rv = 0;
	char *my, *lib;
	char *tc[][2] = {
		{"env1_test", "test/test"},
		{"PATH", " ... "},
		{"", "test"},
		{NULL, "test"},
		{"test", NULL}
	};

	setup_env();

	for (i = 0; i < NTC; i++)
	{
		my_rv = _setenv(tc[i][0], tc[i][1]);
		if (my_rv == -1)
			continue;

		my = _getenv(tc[i][0]);

		if ( my_rv == 0 && strcmp(my, tc[i][1]) == 0 )
			continue;

		printf("Test Case %d: %s/%s\n", i, tc[i][0], tc[i][1]);
		printf("My Return Value(%i): %s\n", my_rv, my);

		rv = 1;
	}

	free_env();

	return (rv);
}
