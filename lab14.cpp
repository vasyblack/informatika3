
#include "stdafx.h";
#include <stdio.h>;
#include <math.h>;
#include <conio.h>;

void transposeTwoDimensionalArray(double** M, double* V, int Nmax, int Mmax);
int inputTwoDimensionalArray(double** M, int* x, int* y, int Nmax, int Mmax);
void outputTwoDimensionalArray(double** M, int x, int y);
void change(double* A, double* B);
void sortTheDiagonals(double** M, int x, int y);

void main()
{
	printf_s("Maximum size of a two-dimensional array\n");
	const int Nmax = 10;
	const int Mmax = 10;
	double matrix[Nmax][Mmax];
	double* Mat[Nmax];
	transposeTwoDimensionalArray(Mat, *matrix, Nmax, Mmax);
	int x, y = 0;
	int k = inputTwoDimensionalArray(Mat, &x, &y, Nmax, Mmax);
	printf_s("Initial two-dimensional array:\n");
	outputTwoDimensionalArray(Mat, x, y);
	sortTheDiagonals(Mat, x, y);
	printf_s("Processed two-dimensional array:\n");
	outputTwoDimensionalArray(Mat, x, y);
	getch();
}


void transposeTwoDimensionalArray(double** M, double* V, int x, int y)
{
	for (int i = 0; i < x; i++)
		M[i] = V + y * i;
}

int inputTwoDimensionalArray(double** M, int* x, int* y, int Nmax, int Mmax)
{
	printf_s("Enter the number of rows and columns:\n ");
	scanf_s("%i%i", x, y);
	while( *x <= 0 || *y <= 0 || *x > Nmax || *y > Mmax)
	{
		printf_s("One more time please, you idiot\n");
		printf_s("\n");
		printf_s("Enter the number of rows and columns:\n ");
		scanf_s("%i%i", x, y);
	}
	printf_s("\n");
	for (int i = 0; i < *x; i++)
	{
		printf_s("Please, enter value\n");
		for (int j = 0; j < *y; j++)
		{
			scanf_s("%lf", &M[i][j]);
		}
		printf_s("\n");
	}
	return 1;
}

void outputTwoDimensionalArray(double** M, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			printf_s("%5.0lf ", M[i][j]);
		printf_s("\n");
	}
}

void change(double* A, double* B)
{
	double temp = *A;
	*A = *B;
	*B = temp;
}

void sortTheDiagonals(double** M, int x, int y)
{
	int xy = x;
	if (xy > y)
		xy = y;
	for (int k = 0; k < y; k+=2)
		for (int j = 0; j < xy; j++)
			for (int i = 0; i < xy-1; i++)
				if (i + k < y - 1)
					if (M[i][i + k] < M[i + 1][i + k + 1])
						change(M[i] + i + k, M[i + 1] + i + k + 1);
	for (int k = 0; k < x; k += 2)
		for (int j = 0; j < y; j++)
			for (int i = 0; i < xy - 1; i++)
				if (i + k < x - 1)
					if (M[i + k][i] < M[i + 1 + k][i + 1])
						change(M[i + k] + i, M[i+1+k] + i + 1);

	for (int k = 1; k < y; k += 2)
		for (int j = 0; j < xy; j++)
			for (int i = 0; i < xy - 1;i++)
				if (i + k < y - 1)
					if (M[i][i + k ] > M[i + 1][i + k + 1])
						change(M[i] + i + k, M[i + 1] + i + k + 1);

	for (int k = 1; k < x; k += 2)
		for (int j = 0; j < xy; j++)
			for (int i = 0; i < xy - 1;i++)
				if (i + k < x - 1)
					if (M[i + k][i] > M[i + 1 + k][i + 1])
						change(M[i + k] + i, M[i + 1 + k] + i + 1);
}
