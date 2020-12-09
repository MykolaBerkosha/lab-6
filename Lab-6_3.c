#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
const int Low = -100, High = 100;

int n;

void init(int A[n]){
	srand((unsigned)time(0)+rand()); // для генерації нових чисел кожного разу при запуску функції
	printf("\n");
	for(int i = 0; i < n; i++)
		A[i] = Low + rand() % (High - Low + 1);
}

void print(int A[n]){
	printf("\nМасив A:\n");
	for (int i = 0; i < n; i++){
		printf("A[%d] = %d\t", i, A[i]);
	}printf("\n");
}

double ser(int A[n]){
	double summ = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]%2 != 0)
		{
			summ += A[i];
			k++;
		}
	}
	if (k == 0){return 0;}
	return summ/k;
}

int main(void)
{
	printf("\nВведіть розмір масиву:\n");
	printf("n = ");
	scanf("%d", &n);

	int A[n];
	init(A);
	print(A);
	printf("\nСереднє арифметичне непарних елементів одновимірного масиву: %.2lf\n", ser(A));

getchar();getchar();
return 0;
}
