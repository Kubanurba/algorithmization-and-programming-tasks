#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime> 

using namespace std;

void Input(int array[], const int n)
{
	srand(time(NULL));
	cout << "RAND ARRAY is :  ";
	for (int i = 0; i < 50; i++)
	{
		array[i] = rand() % 50;
	}
}

void Process(int array[], const int n)
{
	for (int i = 1; i < 50; i += 2)
	{
		int k = i;
		int min = array[i];
		for (int j = i + 2; j < 50; j += 2)
			if (array[j] < min)
			{
				k = j;
				min = array[j];
			}
		array[k] = array[i];
		array[i] = min;
	}

	cout << "NEW ARRAY is: ";
}

void Output(int array[], const int n)
{
	cout << endl << "ARRAY ---> ";
	for (int i = 0; i < 50; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	const int size = 50;
	int array[size] = {};
	Input(array, size);
	Output(array, size);
	Process(array, size);
	Output(array, size);

	_getch();
	return 0;
}
