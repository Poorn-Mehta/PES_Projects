#include "Memread.h"

uint32_t *mem_ptr2, mem_i;

void memread(void)
{
	if(mem_ptr)
	{
		Detailed_Output();
		if(print)
		{
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
		if(print == 0)
		{
			printf("\nThe hex data at the specified location %x is %x\n", mem_ptr2, *mem_ptr2);
		}
		printf("\nThanks for reading from an allocated memory location...\n");
	}
	else
	{
		printf("\nUnfortunately, you have not been allocated any memory so far and so no memory can be read...\n");
	}
}
