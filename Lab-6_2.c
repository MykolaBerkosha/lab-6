#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
const int Low = -100, High = 100;

int max_i = -1;
int max_j = -1;
int maxar;

void init(int n, int m, int A[][m]){
	srand((unsigned)time(0)+rand()); // для генерації нових чисел кожного разу при запуску функції
	printf("\n");
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		A[i][j] = Low + rand() % (High - Low + 1);
	}
}

void print(int n, int m, int A[][m]){
	printf("\nМасив A:\n");
	for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++)
	{
		printf("A[%d][%d] = %d\t", i, j, A[i][j]);
	}printf("\n");
	}
}

void maxarr(int n, int m, int A[][m]){
	int max = A[0][0];
	int tmp_i, tmp_j;
	for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++)
	{
		if (A[i][j] > max)
		{
			max = A[i][j];
			tmp_i = i;
			tmp_j = j;
		}
	}
}
	maxar = max;
	max_i = tmp_i;
	max_j = tmp_j; 
}

long int dob(int n, int m, int A[][m]){
	long int dob = 1;
	_Bool x=0;
	_Bool y=0;

	int index_i_1 = -1;
	int index_j_1 = -1;

	int index_i_2 = -1;
	int index_j_2 = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] < 0)
			{
				index_i_1 = i;
				index_j_1 = j;
				break;
			}
		}
		if (index_i_1 != -1)
		{
			break;
		}
	}

for (int i = n-1; i >= 0; i--)
	{
		for (int j = m-1; j >= 0; j--)
		{
			if (A[i][j] < 0)
			{
				index_i_2 = i;
				index_j_2 = j;
				break;
			}
		}
		if (index_i_2 != -1)
		{
			break;
		}
	}
	if (n == 1 && m == 1)
	{
		printf("\r\n\n2) У масиві тільки один елемент");
		getchar();getchar();
		exit(1);
	} else if (index_i_1 == -1 && index_j_1 == -1 && index_i_2 == -1 && index_j_2 == -1)
	{
		printf("\r\n\n2) У масиві немає елементів менших нуля");
		getchar();getchar();
		exit(1);
	} else if (index_i_1 == index_i_2 && index_j_1 == index_j_2)
	{
		printf("\r\n\n2) У масиві тільки один елемент, менший за нуль");
		getchar();getchar();
		exit(1);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (y==1 || (i==index_i_1 && j==index_j_1))
			{
			dob *= A[i][j];
			y=1;
			}
			if (i==index_i_2 && j==index_j_2){x=1;break;}
		}if (x==1){break;}}
	dob = dob / (A[index_i_1][index_j_1] * A[index_i_2][index_j_2]);
	if (dob == 1)
	{
		printf("\n\n2) У масиві лише два елементи які менші за нуль, знаходяться поряд один з одним");
		getchar();getchar();
		exit(1);
	}
return dob;
}

int main(void)
{
	int n, m;

	printf("\nВведіть розмір матриці:\n");
	printf("n = ");
	scanf("%d", &n);

	printf("m = ");
	scanf("%d", &m);

	int A[n][m];
	init(n, m, A);
	print(n, m, A);
	maxarr(n, m, A);
	printf("\n\n1) Найбільший елемент у масиві: A[%d][%d] %d\n",max_i, max_j, maxar);
	
	printf("\n2) добуток елементів масиву, розташованих між першим й останнім \n   від’ємними елементами = %ld", dob(n, m, A));

getchar();getchar();
return 0;
}
