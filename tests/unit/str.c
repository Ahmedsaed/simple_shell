#include "./../../main.h"
#include <string.h>

int main()
{
	printf("-----------------------------------------------------------------------------------\n");
	
	size_t len = strlen("AbcdEfG_1290.*&x");
	printf("Strlen: %ld\n", len); // 16 characters.
	printf("_Strlen: %ld\n", _strlen("AbcdEfG_1290.*&x"));

	char s1[8];
	printf("Strncpy: %s\n", strncpy(s1, "Ahmed Saed", 8));
	printf("_Strncpy %s\n", _strncpy(s1, "Ahmed Saed", 8));

	char s2[9] = "Adham Es";
	printf("Stdup: %s\n", strdup(s2));
	printf("_Stdup: %s\n", strdup(s2));

	char s3[8] = "Ahmed Sa", s4[9] = "/Adham Es";
	printf("Strcat: %s\n", strcat(s3, s4));
	char s5[8] = "Ahmed Sa", s6[9] = "/Adham Es";
	printf("%s\n", s5);
	printf("_Strcat: %s\n", _strcat(s5, s6));


	printf("-----------------------------------------------------------------------------------\n");
}
