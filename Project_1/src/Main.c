#include "Main.h"
#include "Help.h"

char input[50], compare[50];
uint8_t i;

int main(void)
{
	Help_Init();
	printf("Enter Command: ");
	scanf("%s", input);
	i = 0;
	while((input[i] != '.') && (input[i] != 0))
	{
		compare[i] = input[i];
		i += 1;
	}
	if(input[i] == '.')
	{
		i += 1;
		if(strcmp(compare, h) == 0)
		{
			Help_Lookup();
		}
		else
		{
			printf("%s",compare);
			return 0;
		}
	}
	return 0;	
}
