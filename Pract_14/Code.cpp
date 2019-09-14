#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;

void SaveFirst(int *arr, FILE *F)
{

	F = fopen("C:\\Users\\Nastya\\Desktop\\data.dat", "wb");
	fwrite(arr, sizeof(int), sizeof(arr) / sizeof(int), F);
	fclose(F);

}

int Process(int *arr)
{
	int arr2[10] = {};

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "  ";
	}
	for (int i = 0, j = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			cout << arr[i] << "   ";
			arr2[j] = arr[i];
			j++;
		}
	}

	return *arr2;
}

void SaveSecond(FILE *F, int *arr2)
{
	F = fopen("C:\\Users\\Nastya\\Desktop\\data.dat", "a+b");
	fwrite(arr2, sizeof(int), sizeof(arr2) / sizeof(int), F);
	fclose(F);
}
int main()
{
	FILE * F = 0;
	int arr[10] = { 10, 3, 15, 24, 76, 444, 32, 1, 9, 10 };
	int arr2[10] = {};

	SaveFirst(arr, F);
	Process(arr);
	SaveSecond(F, arr2);

	_getch();
	return 0;
}
