#ifndef __Input_h__
#define __Input_h__

#include "Main.h"
#include "Help.h"

#define Number_of_Input_Functions	4

extern const char ire[], i1[], i2[], i3[], i4[];

typedef struct
{
	char it1[5];
	char it2[5];
	char it3[9];
	char it4[8];
}Input;

extern Input input_search, *input_ptr;
extern char *input_ptr2, input_check[20];
extern uint8_t input_j, input_k;

void Input_Init(void);
void String_to_Decimal(void);
void Input_Lookup(void);

#endif
