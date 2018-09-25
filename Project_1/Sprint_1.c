/*
 * Trial.c
 *
 *  Created on: Sep 24, 2018
 *      Author: root
 */


#include <stdio.h>
#include <string.h>
#include "Sprint_1.h"

int main(void)
{
	char str1[10];
	printf("Welcome");
	while(1)
	{
		printf("\nEnter Command: ");
		scanf("%s",str1);
			if((strcmp(str1, help) == 0) || (strcmp(str1, exit) == 0))
			{
				if(strcmp(str1, help) == 0)
				{
					printf("You have typed help");
				}
				else
				{
					printf("Exiting\n");
					break;
				}
			}
			else
			{
				printf("Invalid Command");
			}
	}
}
