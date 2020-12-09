#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int Low = -100, High = 100;

int min_i = -1;
int min_j = -1;
double minar = 0;

void init(int n, int m, double A[][m]){
	srand((unsigned)time(0)+rand()); // для генерації нових чисел кожного разу при запуску функції
	printf("\n");
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		A[i][j] = (double)rand() / RAND_MAX * (High - Low) + Low;
	}
}

void print(char x, int n, int m, double A[][m]){
	for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++)
	{
		printf("%c[%d][%d] = %6.2lf\t", x, i, j, A[i][j]);
	}printf("\n");
	}
}

double minarr(int n, int m, double A[][m]){
	double min = A[0][0];
	int tmp_i = 0, tmp_j = 0;
	
	if (min_i == -1 && min_j == -1)
	{
		minar = A[0][0];
		min_i = 0;
		min_j = 0;
	}

	for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++)
	{
		if (A[i][j] < min)
		{
			min = A[i][j];
			tmp_i = i;
			tmp_j = j;
		}

		if (min < minar)
		{
			minar = min;
			min_i = tmp_i;
			min_j = tmp_j; 
		}
	}
}
return min;
}

int main(void)
{
	int n, m;

	printf("\nВведіть розмір матриці:\n");
	printf("n = ");
	scanf("%d", &n);

	printf("m = ");
	scanf("%d", &m);

	double A[n][m];
	double B[n][m];

	init(n, m, A);
	init(n, m, B);
	
	printf("\nМасив A:\n");
	print('A', n, m, A);

	printf("\nМасив B:\n");
	print('B', n, m, B);
	
	if (minarr(n, m, A) < minarr(n, m, B))
	{
		printf("\n\nНайменший елемент у масиві: A[%d][%d] %.2lf\n",min_i, min_j, minar);
	} else printf("\n\nНайменший елемент у масиві: B[%d][%d] %.2lf\n",min_i, min_j, minar);

getchar();getchar();
return 0;
}
