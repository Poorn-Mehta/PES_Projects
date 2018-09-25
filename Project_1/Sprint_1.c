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
	printf("\nType help to get information about using it");
	while(1)
	{
		printf("\nEnter Command: ");
		scanf("%[^\n]s",str1);
			if((strcmp(str1, help) == 0) || (strcmp(str1, exit) == 0) || (strcmp(str1, "help exit") == 0))
			{
				if(strcmp(str1, help) == 0)
				{
					printf("Enter the name of command after help\n");
					printf("For example - type: help exit\n");
				}
				else if(strcmp(str1, exit) == 0)
				{
					printf("Exiting\n");
					break;
				}
				else
				{
					printf("\n Help on Exit Command");
					printf("\n Just type in 'exit' to close");
				}
			}
			else
			{
				printf("Invalid Command");
			}
	}
}
