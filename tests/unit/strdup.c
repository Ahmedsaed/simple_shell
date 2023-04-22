#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 5

int main()
{
    int i, rv = 0;
	char *my_rv;
	char *lib_rv;
    char *tc[][1] = {
		{" "},
	    {"Mohamed"},
		{"1320342490139319124091309481390581309581309583109481309MOHAMED481"},
		{"- ~ * / @ - ."},
		{""}
	};

    for (i = 0; i < NTC; i++)
    {
		my_rv = _strdup(tc[i][0]);
		lib_rv = strdup(tc[i][0]);

		if (strcmp(my_rv, lib_rv) == 0)
			continue;

        printf("Test Case %d: String(%s)\n", i, tc[i][0]);
        printf("Library's Return Value: %s\n", my_rv);
        printf("My Return Value: %s\n", lib_rv);

		rv = 1;
	}

    return (rv);
}
