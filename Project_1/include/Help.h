#ifndef __Help_h__
#define __Help_h__

#include "Main.h"

extern const char h[], h1[], h2[], h3[], hre[], hr1[], hr2[], hr3[];

typedef struct
{
	char ht1[5];
	char ht2[9];
	char ht3[8];
}Help;


extern Help help, *help_ptr;
extern char *ptr2, check[20], help_compare[20], help_print[500];
extern uint8_t j, k;

#endif
