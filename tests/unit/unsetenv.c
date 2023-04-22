#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 3

/**
 * Can't do any error-causing tests
 * as if setenv itself failed there
 * would not be an unsetenv to apply.
 *
 * So usually whenever setenv returns -1
 * everything else should stop.
 * So here we assume it returns 0 by giving
 * the right inputs.
 */

int main()
{
    int i, rv = 0;
	char *val;
	int my_rvSet, my_rvUnSet;
    char *tc[][1] = {
		{"env1_test"},
		{"env2_test"},
		{"PATH"}
	};

    for (i = 0; i < NTC; i++)
    {
		setenv(tc[i][0], "testCase", 1);
//		printf("%s\n", _getenv(tc[i][0]));
		_unsetenv(tc[i][0]);
		val = _getenv(tc[i][0]);

		if (val == NULL)
			continue;

        printf("Test Case %d: Name(%s)\n", i, tc[i][0]);
        printf("My Return Value: %s\n", getenv(tc[i][0]));

		rv = 1;
	}

	return (rv);
}
