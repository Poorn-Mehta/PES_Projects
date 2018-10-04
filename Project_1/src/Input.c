#include "Input.h"

const char ire[] = "\nCommand not recognized\n";
const char i1[] = "help";
const char i2[] = "exit";
const char i3[] = "memalloc";
const char i4[] = "memfree";
const char i5[] = "memwrite";
const char i6[] = "memread";
const char i7[] = "meminv";
const char i8[] = "patterngen";
const char i9[] = "patternverify";

Input input_search, *input_ptr;
char *input_ptr2, input_check[20], error_flag, hex_flag;
char input[250], input1[50], input2[50], input3[50], input4[50], input5[50];
uint8_t input_j, input_k, exit_flag, power;
uint32_t value, value1, value2, value3, value4;

void (*Input_Func_Pointer[9]) (void) = 
											{
												Help_Display,
												Exit_Func,
												Memalloc_Func,
												Memfree_Func,
												Memwrite_Func,
												Memread_Func,
												Meminv_Func,
												Patterngen_Func,
												Patternverify_Func
											};

void (*Input_Space_Func_Pointer[9]) (void) = 
													{
														Help_Lookup,
														Command_Error,
														Space_Memalloc_Func,
														Command_Error,
														Space_Memwrite_Func,
														Space_Memread_Func,
														Space_Meminv_Func,
														Space_Patterngen_Func,
														Space_Patternverify_Func
													};

void Command_Error(void)
{
	printf("%s",ire);
}

void Exit_Func(void)
{
	exit_flag = 1;
}

void Memalloc_Func(void)
{
	printf("\nEnter number of 32bit words for malloc: ");
	hex_flag = 0;
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		memalloc();
	}
	else
	{
		value1 = 0;
	}
	printf("\n%d Blocks have been allocated\n", value1);	
}

void Space_Memalloc_Func(void)
{
	if(space_flag == 1)
	{
		String_to_Decimal(input2);
		if(error_flag == 0)
		{
			value1 = value;
			memalloc();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
	printf("\n%d Blocks have been allocated\n", value);
}

void Memfree_Func(void)
{
	memfree();
}

void Memwrite_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		printf("\nEnter 32bit Data in Hex: ");
		hex_flag = 1;
		Valid_Integer_Input();
		if(error_flag == 0)
		{
			value2 = 0x00000000;
			value2 += value;
			memwrite();
		}
	}
}

void Space_Memwrite_Func(void)
{
	if(space_flag == 2)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			String_to_Hex(input3);
			if(error_flag == 0)
			{
				value2 = value;
				memwrite();
			}
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Memread_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		memread();
	}
}

void Space_Memread_Func(void)
{
	if(space_flag == 1)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			memread();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Meminv_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		meminv();
	}
}
void Space_Meminv_Func(void)
{
	if(space_flag == 1)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			meminv();
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void Patterngen_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative starting address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute starting address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	if(error_flag == 0)
	{
		value1 = value;
		printf("\nEnter the number of 32bit numbers that you wish to generate: ");
		hex_flag = 0;
		Valid_Integer_Input();
		if(error_flag == 0)
		{
			value2 = value;
			printf("\nEnter the Seed value of your choice: ");
			hex_flag = 0;
			Valid_Integer_Input();
			if(error_flag == 0)
			{
				value3 = value;
				printf("\nEnter the Maximum value of generated psuedo random number(s): ");
				hex_flag = 0;
				Valid_Integer_Input();
				if(error_flag == 0)
				{
					value4 = value;
					patterngen();
				}
			}
		}
	}
}

void Space_Patterngen_Func(void)
{
	if(space_flag == 4)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		if(error_flag == 0)
		{
			value1 = value;
			String_to_Decimal(input3);
			if(error_flag == 0)
			{
				value2 = value;
				String_to_Decimal(input4);
				if(error_flag == 0)
				{
					value3 = value;
					String_to_Decimal(input5);
					if(error_flag == 0)
					{
						value4 = value;
						patterngen();
					}
				}
			}
		}
	}
	else
	{
		value = 0;
		Command_Error();
	}
}
void Patternverify_Func(void)
{
	if(relative_address)
	{
		printf("\nEnter the relative starting address of the memory location: ");
		hex_flag = 0;
	}
	else
	{
		printf("\nEnter the absolute starting address of the memory location: ");
		hex_flag = 1;
	}
	Valid_Integer_Input();
	//if error = 0
	value1 = value;
	printf("\nEnter the number of 32bit numbers that you wish to verify: ");
	hex_flag = 0;
	Valid_Integer_Input();
	//if error = 0
	value2 = value;
	printf("\nEnter the original Seed value: ");
	hex_flag = 0;
	Valid_Integer_Input();
	//if error = 0
	value3 = value;
	printf("\nEnter the Maximum value of generated psuedo random number(s): ");
	hex_flag = 0;
	Valid_Integer_Input();
	//if error = 0
	value4 = value;
	//if error = 0, call patternverify
}
void Space_Patternverify_Func(void)
{
	if(space_flag == 4)
	{
		if(relative_address)
		{
			String_to_Decimal(input2);
		}
		else
		{
			String_to_Hex(input2);
		}
		//if error = 0
		value1 = value;
		String_to_Decimal(input3);
		//if error = 0
		value2 = value;
		String_to_Decimal(input4);
		//if error = 0
		value3 = value;
		String_to_Decimal(input5);
		//if error = 0
		value4 = value;
		//if error = 0. call patternverify
	}
	else
	{
		value = 0;
		Command_Error();
	}
}

void String_to_Decimal(char *stod_ptr)
{
	char *stod_i;
	stod_i = stod_ptr;
	for(; *stod_ptr != 0; stod_ptr ++)
	{
		if(isdigit(*stod_ptr) == 0)
		{
			printf("\nNon Integer Value Entered\n");
			error_flag = 1;
			value = 0;
			break;
		}
	}
	if(*stod_ptr == 0)
	{
		error_flag = 0;
		value = atoi(stod_i);
	}
}

void String_to_Hex(char *stox_ptr)
{
	char *stox_i;
	stox_i = stox_ptr;
	while(*stox_ptr != 0)
	{
		if(((*stox_ptr >= '0') && (*stox_ptr <= '9')) || ((*stox_ptr >= 'a') && (*stox_ptr <= 'f')) || ((*stox_ptr >= 'A') && (*stox_ptr <= 'F')))
		{
			stox_ptr += 1;
		}
		else
		{
			break;
		}
	}
	if(*stox_ptr == 0)
	{
		error_flag = 0;
		value = (uint32_t) strtol(stox_i, NULL, 16);
	}
	else
	{
		printf("\nNon Hex Value Entered\n");
		error_flag = 1;
		value = 0;
		Command_Error();
	}
}

void Valid_Integer_Input(void)
{
	char test[50];
	fgets(test, 50, stdin);
	input_j = 0;
	while(test[input_j] != '\n')
	{
		input_j += 1;
	}
	test[input_j] = 0;
	if(hex_flag == 0)
	{
		String_to_Decimal(test);
	}
	else
	{
		String_to_Hex(test);
	}
}

void Input_Init(void)
{
	input_ptr = &input_search;
	input_ptr2 = (char *)&input_ptr->it1;
	strcpy(input_search.it1, i1);
	strcpy(input_search.it2, i2);
	strcpy(input_search.it3, i3);
	strcpy(input_search.it4, i4);
	strcpy(input_search.it5, i5);
	strcpy(input_search.it6, i6);
	strcpy(input_search.it7, i7);
	strcpy(input_search.it8, i8);
	strcpy(input_search.it9, i9);
}

void Input_Cleanup(void)
{
	hex_flag = 0;
	error_flag = 0;
	value = 0;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	value4 = 0;
	input_j = 0;
	input_ptr2 = (char *)&input_ptr->it1;
	Array_Cleanup(input_check);
}

void Input_Lookup(void)
{
	Input_Cleanup();
	//In the input, entering space after command as a mistake is acceptable, but entering anything after that space is not
	if((space_flag != 0) && (input2[0] != 0))
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
			if(strcmp(input_check, input1) == 0)
			{
				(*Input_Space_Func_Pointer[input_k])();
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
			if(strcmp(input_check, input1) == 0)
			{
				(*Input_Func_Pointer[input_k])();
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
