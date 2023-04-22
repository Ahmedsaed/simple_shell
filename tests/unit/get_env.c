#include "./../../main.h"
#include <string.h>
#include "../test.h"

#define NTC 3

int main()
{
    int i, rv = 0;
	char *lib_rv;
	char *my_rv;
	char *tc[] = {
		"PATH",
		"HOME",
		"ls"
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _getenv(tc[i]);
		lib_rv = getenv(tc[i]);

		if (my_rv == NULL && lib_rv == NULL)
			continue;

		if (_strcmp(my_rv, lib_rv) == 0)
			continue;

        printf("Test Case %d:\n", i);
        printf("Library's Return Value: %s\n", my_rv);
        printf("My Return Value: %s\n", lib_rv);

		rv = 1;
	}

    return (rv);
}
