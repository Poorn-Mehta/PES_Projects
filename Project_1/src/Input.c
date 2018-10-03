#include "Input.h"

const char ire[] = "\nCommand not recognized\n";
const char i1[] = "help";
const char i2[] = "exit";
const char i3[] = "memalloc";
const char i4[] = "memfree";

Input input_search, *input_ptr;
char *input_ptr2, input_check[20];
char input[50], compare[50], input2[50];
uint8_t input_j, input_k, exit_flag, power;
uint32_t value;

void Input_Init(void)
{
	input_ptr = &input_search;
	input_ptr2 = (char *)&input_ptr->it1;
	strcpy(input_search.it1, i1);
	strcpy(input_search.it2, i2);
	strcpy(input_search.it3, i3);
	strcpy(input_search.it4, i4);
}

void String_to_Decimal(void)
{
	while(input2[main_j] != 0)
	{
		compare[main_i] = input2[main_j];
		main_i += 1;
		main_j += 1;
	}
	value = atoi(compare);
}

void Input_Lookup(void)
{
	input_ptr2 = (char *)&input_ptr->it1;
	input_j = 0;
	Array_Cleanup(input_check);
	if(space_flag)
	{
		for(input_k = 0; input_k < Number_of_Input_Functions; input_k ++)
		{
			for(input_j = 0;; input_j++)
			{
				input_check[input_j] = *input_ptr2;
				input_ptr2 += 1;
				if(input_check[input_j] == 0)
				{
					break;
				}
			}
			if(strcmp(input_check, input) == 0)
			{
				switch(input_k)
				{
					case 0:
					{
						while(input2[main_j] != 0)
						{
							compare[main_i] = input2[main_j];
							main_i += 1;
							main_j += 1;
						}
						Help_Lookup();	
						break;
					}
					case 1:
					{
						exit_flag = 1;
						break;		
					}
					case 2:
					{
						if(input2[main_j] == 0)
						{
							printf("\nEnter number of 32bit words for malloc: ");
							scanf("%d", &value);
							//call for memalloc value entering function
						}
						else
						{
							String_to_Decimal();
							//Call malloc
						}
						printf("\n%d Blocks have been allocated\n", value);
						break;
					}
					case 3:
					{
						if(input2[main_j] == 0)
						{
							//Call memfree
							printf("\nExecute Memfree\n");
						}
						else
						{
							printf("%s",ire);
						}
						break;
					}
					default:
					{
							break;
					}
				}
				break;
			}
			else
			{
				if(input_k == (Number_of_Input_Functions - 1))	
				{
					printf("%s",ire);
				}
			}
			input_j = 0;
			Array_Cleanup(input_check);
		}
	}
	else
	{
		for(input_k = 0; input_k < Number_of_Input_Functions; input_k ++)
		{
			for(input_j = 0;; input_j++)
			{
				input_check[input_j] = *input_ptr2;
				input_ptr2 += 1;
				if(input_check[input_j] == 0)
				{
					break;
				}
			}
			if(strcmp(input_check, compare) == 0)
			{
				switch(input_k)
				{
					case 0:
					{
						Help_Display();
						break;		
					}
					case 1:
					{
						exit_flag = 1;
						break;		
					}
					case 2:
					{
						printf("\nEnter number of 32bit words for malloc: ");
						scanf("%d", &value);
						//call for memalloc value entering function
						printf("\n%d Blocks have been allocated\n", value);
						break;		
					}
					case 3:
					{
						//call for memfree function
						printf("\nExecute memfree()\n");
						break;		
					}
					default:
					{
						break;
					}
				}
				break;
			}
			else
			{
				if(input_k == (Number_of_Input_Functions - 1))	
				{
					printf("%s",ire);
				}
			}
			Array_Cleanup(input_check);
		}
	}
}
