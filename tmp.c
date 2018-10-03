#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
/*
#define Max		100000

float random, seed;
int print;

void generator(void)
{
	random = ((0.4353491074*seed) + 0.8173946121);
	while(random>1)
	{
		random /= 10;
	}
	random *= Max;
	print = (int)random;
	printf("\n%d",print);
	seed = random;
}*/

int main(void)
{
	long int *tmp;
	tmp = (long int *) malloc(32);
	printf("%x", tmp);
/*	char str[100];
	printf("Enter string: ");
	fgets(str, 100, stdin);
	printf("%s",str);
	char arr[200], tmp[100], i, j;
	printf("Enter Seed: ");
	scanf("%s", tmp);
	j = 0;
	i = 0;
	while(tmp[j] != 0)
	{
		arr[i] = tmp[j];
		i += 1;
		j += 1;
	}
	arr[i] = 0;
	i += 1;
	printf("Enter Seed: ");
	scanf("%s", tmp);
	j = 0;
	while(tmp[j] != 0)
	{
		arr[i] = tmp[j];
		i += 1;
		j += 1;
	}
	arr[i] = 0;
	i += 1;
	arr[i] = '\n';
	i = 0;
	while(arr[i] != '\n')
	{
		
		printf("\n%x", arr[i]);
		i += 1;
	}
	int read;
	scanf("%x", &read);
	printf("\n%x", read);
	read ^= 0xFFFFFFFF;
	printf("\n%x",read);
	scanf("%f", &seed);
	while(seed > 1)
	{
		seed /= 10;
	}
	uint8_t tmp = 0;
	while(tmp < 15)
	{
		generator();
		tmp += 1;
	}*/
}
