#include <iostream>
#include <conio.h>

using namespace std;

void Input(int &n, int array[])
	{
		
		for (int i = 0; i < n; i++)
		{
			cout << "Input a[" << i << "] = ";
			cin >> array[i];
		}
	}


void Process(int n, int *array)
	{
		int max = array[0];
		for (int i = 0; i < n; i++)
		{
			if (array[i] > max)
			{
				max = array[i];
				for (int j = 0; j <= i; j++)
				{
					if (array[j] < 0)
						array[j] = 0;
				}
			}
		}
	}


void Output(int *array, int n)
{
	cout << "New array -->  ";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}


int main()
{
	int n;
	cout << "Array size = ";
	cin >> n;
	int *array = new int[n];

	Input(n, array);
	Process(n, array);
	Output(array, n);

	delete[]array;
	_getch();
	return 0;
}


