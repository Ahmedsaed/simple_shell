#include "./../../main.h"
#include <string.h>

#define NTC 3

int main()
{
    int i, rv = 0;
	char my_rv[41] = "";
	char lib_rv[41] = "";
    char *tc[][1] = {
		{"test"},
		{" "},
	    {"AhmedAhmedAhmedAhmed"}
	};

    for (i = 0; i < NTC; i++)
    {
		_strcat(my_rv, tc[i][0]);
		strcat(lib_rv, tc[i][0]);

		if (strcmp(my_rv, lib_rv) == 0)
			continue;

        printf("Test Case %d: String(%s)\n", i, tc[i][0]);
        printf("Library's Return Value: %s\n", my_rv);
        printf("My Return Value: %s\n", lib_rv);

		rv = 1;
	}

	return (rv);
}


