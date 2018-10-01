#ifndef __Help_h__
#define __Help_h__

#include "Main.h"

const char h[] = "help";
const char h1[] = "exit";
const char h2[] = "memalloc";
const char h3[] = "memfree";
const char hre[] = "Command not recognized";
const char hr1[] = "Type exit to close the program";
const char hr2[] = "Type memalloc and then enter the\nnumber of memory locations that you want\n to use and have access to.\nAlternatively, type memalloc.<number>\nfor example memalloc.32 to allocate\n32 memory locations";
const char hr3[] = "Type memfree to release the \n previously allocated memeory locations";

typedef struct
{
	char ht1[5];
	char ht2[9];
	char ht3[8];
}Help;


Help help, *help_ptr;
char *ptr2, check[20], help_compare[20], help_print[500];
uint8_t j, k;

#endif
