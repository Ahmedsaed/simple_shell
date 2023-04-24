#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 3

int main()
{
    int i, rv = 0;
	char *my_rv;
	char *lib_rv;
    char *tc[][1] = {
		{"test"},
		{" "},
	    {"AhmedAhmedAhmedzAhmed"},
		{"test"}
	};
	char tch[][1] = {
		{'t'},
		{'t'},
		{'z'},
		{' '}
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _strchr(tc[i][0], tch[i][1]);
		lib_rv = strchr(tc[i][0], tch[i][1]);

		if(my_rv == NULL && lib_rv == NULL)
			continue;

		if (strcmp(my_rv, lib_rv) == 0)
			continue;

        printf("Test Case %d: String(%s), Char(%c)\n", i, tc[i][0], tch[i][1]);
        printf("Library's Return Value: %s\n", my_rv);
        printf("My Return Value: %s\n", lib_rv);

		rv = 1;
	}

	return (rv);
}
