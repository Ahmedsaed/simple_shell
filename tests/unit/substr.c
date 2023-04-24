#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 3

int main()
{
	int i, rv = 0;
	char my_rv[10] = "";
	char *tc[] = {
		"Adhamet",
		"Ahmadet",
		"    Zorby"
	};
	char *sol[] = {
		"met",
		"Ahmad",
		"Zorby"
	};
	int iTc[][2] = {
		{5,7},
		{1,5},
		{5,9}
	};

	for (i = 0; i < NTC; i++)
	{
		_strcpy(my_rv, _substr(tc[i], iTc[i][0], iTc[i][1]));

		if (_strcmp(my_rv, sol[i]) == 0)
			continue;

		printf("Test Case %d: String(%s)\n", i, tc[i]);
		printf("My Return Value: %s\n", my_rv);

		rv = 1;
	}

	return (rv);
}
