#include <stdlib.h>
#include <time.h>
#include "functionsLab1.h"
#include <cmath>
#include <iostream>

int GetRandomNumber(int min, int max)
{
	srand(time(NULL) + rand());
	int num = min + rand() % (max - min + 1);
	return num;
}



void FlattenArray(float arr[], int size)
{
	for (int i = 1; i <= size - 2; i++)
	{
		arr[i] = std::round(((arr[i - 1] + arr[i] + arr[i + 1]) * 100) / 3) / 100;
	}


}


void FlattenArrayOld(float numbersBoof[], float numbersOld[], int size)
{
	for (int i = 1; i <= size - 2; i++)
	{
		numbersOld[i] = std::round(((numbersBoof[i - 1] + numbersBoof[i] + numbersBoof[i + 1]) * 100) / 3) / 100;
	}
}
