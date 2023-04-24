#include "./../../main.h"
#include "../test.h"
#include <string.h>

#define NTC 1


int main()
{
	int i, my_rv, rv = 0;
	char *before_setup;
	char *after_setup;

	before_setup = _getenv("PATH");
	my_rv = setup_env();
	after_setup = _getenv("PATH");

	if (_strcmp(before_setup, after_setup) == 0)
	{
		free_env();
		after_setup = _getenv("PATH");
		
		if (after_setup == NULL)
			return (rv);
	}

	printf("WARNING: Failed at environmental setup!\n");
	printf("(During comparison)\n");
	printf("Before setup Pointer: %p, After setup Pointer: %p\n", before_setup, after_setup);
	printf("Before setup Value: %s\nAfter setup Value: %s\n", before_setup, after_setup);	

	rv = 1;

	free_env();

	return (rv);
}
