#include "Patterngen.h"

//add, len, seed, max

uint32_t *mem_ptr2, mem_i;
float random, seed;
uint32_t max, range, random_value, *pattern_original;
clock_t t;

void generator(void)
{
	random = ((0.4353491074*seed) + 0.8173946121);
	while(random > 1)
	{
		random /= 10;
	}
	random *= max;
	random_value = (uint32_t)random;
	printf("\n%x", random_value);
	*mem_ptr2 = random_value;
	seed = random;
}

void patterngen(void)
{
	if(mem_ptr)
	{
		range = value2;
		seed = (float) value3;
		max = value4;
		Detailed_Output();
		clkbegin();
		if(print)
		{
			printf("\nInformation BEFORE pattern generate operation\n\n");
			printf("\nThe allocated addresses are as below:\n");
			for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
			{
				printf("\nRelative address: %d \t\t Actual address: %x \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
			}
		}
		mem_ptr = mem_original;
		if(relative_address)
		{
			value1 = (value1 * 4) + (uint32_t)mem_ptr;
		}
		mem_ptr2 = (uint32_t *) value1;
		pattern_original = mem_ptr2;
		while(seed > 1)
		{
			seed /= 10;
		}
		printf("\nGenerated Psuedo Random Numbers: \n");
		uint8_t counter;
		for(counter = 0; counter < range; counter ++, mem_ptr2 ++)
		{
			generator();
		}
		mem_ptr2 = pattern_original;
		if(print)
		{
			printf("\nInformation AFTER pattern generate operation\n\n");
			printf("\nThe allocated addresses are as below:\n");
			for(mem_i = 0; mem_i < mem_max; mem_i ++, mem_ptr ++)
			{
				printf("\nRelative address: %d \t\t Actual address: %x \t\t Existing hex data at this location in Hex: %x\n", mem_i, mem_ptr, *mem_ptr);
			}
		}
		mem_ptr = mem_original;
		clkend();
		printf("\nThanks for generating a psuedo random number...\n");
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory write cannot be done...\n");
	}
}
