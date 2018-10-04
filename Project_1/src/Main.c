#include "Main.h"
#include "Help.h"
#include "Input.h"

char input[250], input1[50], input2[50], input3[50], input4[50], input5[50];
uint8_t main_i, main_j, exit_flag, space_flag, relative_address;

char m_print[50];
uint8_t print = 0;

clock_t t;

void clkbegin(void)
{ 
    t = clock(); 
}

void clkend(void)
{
	t = clock() - t; 
    double time_taken = (((double)t)/CLOCKS_PER_SEC) * 1000; // in milli seconds 
	printf("\nThe process took %f milli seconds to execute: ", time_taken); 
}

void Detailed_Output(void)
{
	while(1)
	{
		printf("Do you want to use Detailed information?\n");
		printf("\n Type Y or y to accept, type N or n to reject: ");
		fgets(m_print, 50, stdin);
		if((m_print[0] == 'Y') || (m_print[0] == 'y'))
		{
			print = 1;
			break;
		}
		else if((m_print[0] == 'N') || (m_print[0] == 'n'))
		{
			print = 0;
			break;
		}
		else
		{
			printf("\nInvalid Input, Try again\n");
		}
	}
}

void Array_Cleanup(char *clean_ptr)
{
	while(*clean_ptr != 0)
	{
		*clean_ptr = 0;
		clean_ptr += 1;
	}
}

int main(void)	
{
	relative_address = 1;
	Array_Cleanup(input);
	Array_Cleanup(input1);
	Array_Cleanup(input2);
	Array_Cleanup(input3);
	Array_Cleanup(input4);
	Array_Cleanup(input5);
	Help_Init();
	Input_Init();
//	mac_init();
	char address_type[50];
	while(1)
	{
		printf("Do you want to use Relative/Easy Addressing?\n");
		printf("\n Type Y or y to accept, type N or n to reject\nand use absolute/direct addressing: ");
		fgets(address_type, 50, stdin);
		if((address_type[0] == 'Y') || (address_type[0] == 'y'))
		{
			relative_address = 1;
			break;
		}
		else if((address_type[0] == 'N') || (address_type[0] == 'n'))
		{
			relative_address = 0;
			break;
		}
		else
		{
			printf("\nInvalid Input, Try again\n");
		}
	}
	printf("\nRelative Addressing Value set to: %d\n", relative_address);
	while(1)
	{
		exit_flag = 0;
		space_flag = 0;
		printf("\nEnter Command: ");
		fgets(input, 250, stdin);
		main_i = 0;
		while(input[main_i] != '\n')
		{
			main_i += 1;
		}
		input[main_i] = 0;
		main_i = 0;
		while((input[main_i] != 0) && (input[main_i] != ' '))
		{
			input1[main_i] = input[main_i];
			main_i += 1;
		}
		main_j = 0;
		while(input[main_i] != 0)
		{
			if(input[main_i] == ' ')
			{
				space_flag += 1;
				main_i += 1;
				while((input[main_i] != ' ') && (input[main_i] != 0))
				{
					input2[main_j] = input[main_i];
					main_i += 1;
					main_j += 1;
				}
				if(input[main_i] == ' ')
				{
					space_flag += 1;
					main_j = 0;
					main_i += 1;
					while((input[main_i] != ' ') && (input[main_i] != 0))
					{
						input3[main_j] = input[main_i];
						main_i += 1;
						main_j += 1;
					}
					if(input[main_i] == ' ')
					{
						space_flag += 1;
						main_j = 0;
						main_i += 1;
						while((input[main_i] != ' ') && (input[main_i] != 0))
						{
							input4[main_j] = input[main_i];
							main_i += 1;
							main_j += 1;
						}
						if(input[main_i] == ' ')
						{
							space_flag += 1;
							main_j = 0;
							main_i += 1;
							while((input[main_i] != ' ') && (input[main_i] != 0))
							{
								input5[main_j] = input[main_i];
								main_i += 1;
								main_j += 1;
							}	
						}			
					}
				}
			}
			main_i += 1;
		}
		main_i = 0;
		main_j = 0;
		if(input[main_i] != 0)
		{
			Input_Lookup();
			if(exit_flag)
			{
				return 0;
			}	
		}
		Array_Cleanup(input);
		Array_Cleanup(input1);
		Array_Cleanup(input2);
		Array_Cleanup(input3);
		Array_Cleanup(input4);
		Array_Cleanup(input5);
//		printf("\n%s\n%s\n%s\n%s",input2,input3,input4,input5);
	/*	break;
		if(input2[main_i] == ' ')
		{
			space_flag = 1; 
			main_j = 1;
			Input_Lookup();
			if(exit_flag)
			{
				return 0;
			}
		}
		else
		{
			while(input[main_i] != 0)
			{
				compare[main_i] = input[main_i];
				main_i += 1;
			}
			Input_Lookup();
			if(exit_flag)
			{
				return 0;
			}
		}
		Array_Cleanup(input);
		Array_Cleanup(input2);
		Array_Cleanup(compare);*/
	}
}
