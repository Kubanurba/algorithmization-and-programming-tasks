#include <iostream>
#include <conio.h>

using namespace std;

void Input(int h, int w, float **arr)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << "Enter the arr[" << i << "][" << j << "] element: ";
			cin >> arr[i][j];
		}
	}
}

void Output(int h, int w, float **arr)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << arr[i][j] << "   ";

		cout << endl;
	}
}

void Process(int h, int w, float **arr)
{
	float min = arr[0][0];
	int cn = 0;

	for (int i = 1; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
				cn = j;
			}
		}
	}

	cout << min << "   " << endl;

	// swap 
	float tmp;

	for (int i = 0; i < h; i++)
	{
		tmp = arr[i][w - 1];
		arr[i][w - 1] = arr[i][cn];
		arr[i][cn] = tmp;
	}
}

int main()
{
	int h, w;
	cout << "Input please the number of rows and columns:" << endl;
	cout << "Rows = ";
	cin >> h;
	cout << "Columns = ";
	cin >> w;

	// memory 

	float **arr = new float *[h];
	for (int i = 0; i < h; i++)
	{
		arr[i] = new float[w];
	}

	Input(h, w, arr); // to input array
	Output(h, w, arr); // to show array 

	Process(h, w, arr); // min + swap

	cout << "New array is : " << endl;
	Output(h, w, arr); //to show new array

	  // clear memory 
	for (int i = 0; i < h; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


	_getch();
	return 0;
}
