#include "Help.h"

const char h[] = "help";
const char h1[] = "exit";
const char h2[] = "memalloc";
const char h3[] = "memfree";
const char hre[] = "Command not recognized";
const char hr1[] = "Type exit to close the program";
const char hr2[] = "Type memalloc and then enter the\nnumber of memory locations that you want\n to use and have access to.\nAlternatively, type memalloc.<number>\nfor example memalloc.32 to allocate\n32 memory locations";
const char hr3[] = "Type memfree to release the \n previously allocated memeory locations";


Help help, *help_ptr;
char *ptr2, check[20], help_compare[20], help_print[500];
uint8_t j, k;


void Help_Init(void)
{
	help_ptr = &help;
	ptr2 = &help_ptr->ht1;
	strcpy(help.ht1, h1);
	strcpy(help.ht2, h2);
	strcpy(help.ht3, h3);
}


void Help_Lookup(void)
{
	j = 0;
	while(input[i] != 0)
	{
		help_compare[j] = input[i];
		j += 1;
		i += 1;
	}
	for(k = 0; k < 3; k ++)
	{
		for(j = 0;; j++)
		{
			check[j] = *ptr2;
			ptr2 += 1;
			if(check[j] == 0)
			{
				break;
			}
		}
		if(strcmp(check, help_compare) == 0)
		{
			switch(k)
			{
				case 0:
				{
					strcpy(help_print, hr1);
					break;		
				}
				case 1:
				{
					strcpy(help_print, hr2);
					break;		
				}
				case 2:
				{
					strcpy(help_print, hr3);
					break;		
				}
				default:
				{
					strcpy(help_print, hre);
					break;
				}
			}
			printf("%s",help_print);
			break;
		}	
	}
}




