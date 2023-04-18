#include "./../../main.h"

int main()
{
	printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");


	printf("environment variables:\n");
	_env();

	printf("\nsearching for specific environment variable:\n");
	char *s = _getenv("PATH");
	if(s != NULL)
		printf("%s\n", s);
	else printf("Doesn't exist.\n");

	
	printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
}
