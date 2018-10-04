#include "Help.h"

const char h[] = "help";
const char hd[] = "\n\nDirections to use help command:\nPut a whitespace after help and then type the command\nTo get information on using that command\nFor example - type: help exit\n\nList of valid Commands:\n";
const char h1[] = "exit";
const char h2[] = "memalloc";
const char h3[] = "memfree";
const char h4[] = "memwrite";
const char h5[] = "memread";
const char h6[] = "meminv";
const char h7[] = "patterngen";
const char h8[] = "patternverify";
const char hre[] = "\nCommand not recognized\n";
const char hr1[] = "\nexit: \nType exit to close the program\n";
const char hr2[] = "\nMemory Allocation:\n\nType memalloc and then enter the\nnumber of memory locations that you want\nto use and have access to.\n\nAlternatively, type memalloc <number> without <> for value\n";
const char hr3[] = "\nMemory Free:\nType memfree to release the \npreviously allocated memory locations\n";
const char hr4[] = "\nMemory Write:\nType memwrite and then enter the address and data\nto write 32bit data at memory location of your choice.\n\nAlternatively, type memwrite <address> <data> without <> for values\n";
const char hr5[] = "\nMemory Read:\nType memread to read 32bit data in hex\nat memory location of your choice.\n\nAlternatively, type memread <address> without <> for value\n";
const char hr6[] = "\nMemory Inverse:\nType meminv to invert all bits of a\n32bit memory block at location of your choice\n";
const char hr7[] = "\nPsuedo Random Pattern Generation:\nType patterngen and then enter maximum value,\nseed, number of 32bits words that you wish to generate,\nand starting memory location to store the pattern\nto generate multiple psuedo random numbers.\n\nAlternatively, type patterngen <starting memory address> <length of pattern> <seed> <maxvalue>\nwithout <> for values\n";
const char hr8[] = "\nPsuedo Random Pattern Verification:\nType patternverify and then enter maximum value,\nseed, number of 32bits words that you wish to verify,\nand starting memory location pointing to the stored pattern\nto verify multiple psuedo random numbers.\n\nAlternatively, type patternverify <starting memory address> <length of pattern> <seed> <maxvalue>\nwithout <> for values\n";


Help help, *help_ptr;
char *help_ptr2, help_check[20], help_print[500];
uint8_t help_j, help_k;

void (*Help_Func_Ptr[8]) (void) = 
								{
									Help_Response1,
									Help_Response2,
									Help_Response3,
									Help_Response4,
									Help_Response5,
									Help_Response6,
									Help_Response7,
									Help_Response8
								};

void Help_Response1(void)
{
	printf("%s",hr1);
}

void Help_Response2(void)
{
	printf("%s",hr2);
}

void Help_Response3(void)
{
	printf("%s",hr3);
}

void Help_Response4(void)
{
	printf("%s",hr4);
}

void Help_Response5(void)
{
	printf("%s",hr5);
}
void Help_Response6(void)
{
	printf("%s",hr6);
}

void Help_Response7(void)
{
	printf("%s",hr7);
}

void Help_Response8(void)
{
	printf("%s",hr8);
}

void Help_Init(void)
{
	help_ptr = &help;
	help_ptr2 = (char *)&help_ptr->ht1;
	strcpy(help.ht1, h1);
	strcpy(help.ht2, h2);
	strcpy(help.ht3, h3);
	strcpy(help.ht4, h4);
	strcpy(help.ht5, h5);
	strcpy(help.ht6, h6);
	strcpy(help.ht7, h7);
	strcpy(help.ht8, h8);
}

void Help_Display(void)
{
	printf("%s",hd);
	printf("\n\t%s",h);
	printf("\n\t%s",h1);
	printf("\n\t%s",h2);
	printf("\n\t%s",h3);
	printf("\n\t%s",h4);
	printf("\n\t%s",h5);
	printf("\n\t%s",h6);
	printf("\n\t%s",h7);
	printf("\n\t%s",h8);
	printf("\n");
}

void Help_Lookup(void)
{
	help_ptr2 = (char *)&help_ptr->ht1;
	Array_Cleanup(help_check);
	for(help_k = 0; help_k < Number_of_Help_Functions; help_k ++)//Number_of_Help_Functions
	{
		for(help_j = 0;; help_j++)
		{
			help_check[help_j] = *help_ptr2;
			help_ptr2 += 1;
			if(help_check[help_j] == 0)
			{
				break;
			}
		}
		if(strcmp(help_check, input2) == 0)
		{
			(*Help_Func_Ptr[help_k])();
			break;
		}
		else
		{
			if(help_k == (Number_of_Help_Functions - 1))	
			{
				printf("%s",hre);
			}
		}
		Array_Cleanup(help_check);
	}
}



