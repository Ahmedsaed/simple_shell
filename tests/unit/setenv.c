#include "./../../main.h"
#include <string.h>

#define NTC 2

/**
 * The original setenv doesn't accept NULLs,
 * which causes segmentation faults,
 * that's why NULL test-cases where avoided,
 * but NULL test-cases are indeed dealt with
 * in our own function.
 *
 * Also, test case number 3 is avoided
 * (as NTC is = 2)
 * because it sucessfully returns EINVAL
 * (Error: Invalid Argument.)
 * Which appears when you "make",
 * which ruins the look of the output.
 *
 * At anytime you wish to test case number 3,
 * set NTC to 3.
 * At anytime you wish to test case number 4&5,
 * set NTC to 5 & comment lib_rv.
 */

int main()
{
    int i, my_rv, lib_rv, rv = 0;
    char *tc[][2] = {
		{"env1_test", "test/test"},
		{"PATH", " ... "},
		{"", ""},
		{NULL, "env2_test"},
		{"env3_test", NULL}
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _setenv(tc[i][0], tc[i][1], 0);
		lib_rv = setenv(tc[i][0], tc[i][1], 0);

		if (my_rv == lib_rv)
			continue;

        printf("Test Case %d: Name(%s), Value(%s)\n", i, tc[i][0], tc[i][1]);
        printf("Library's Return Value: %i\n", lib_rv);
        printf("My Return Value: %i\n", my_rv);

		rv = 1;
	}

	return (rv);
}
