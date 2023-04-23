#include "./../../main.h"
#include <string.h>
#include "../test.h"

#define NTC 3

int main()
{
    int i, rv = 0, my_rv, lib_rv;
	char *tc[] = {
		"4",
		"500",
		"139421"
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _atoi(tc[i]);
		lib_rv = atoi(tc[i]);

		if (my_rv == lib_rv)
			continue;

        printf("Test Case %d:\n %s", i, tc[i]);
        printf("Library's Return Value: %i\n", my_rv);
        printf("My Return Value: %i\n", lib_rv);

		rv = 1;
	}

    return (rv);
}
