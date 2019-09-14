
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int D;
	int M;
	int d = 0;

	cout << "Input your day: ";
	cin >> D;
	cout << "Input your month: ";
	cin >> M;

	switch (M)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (D > 31)
		{
			cout << "Your input day is incorrect!";
			_getch();
			return 0;
		}
	case 4: case 6: case 9: case 11:
		if (D > 30)
		{
			cout << "Your input day is incorrect!";
			_getch();
			return 0;
		}
	case 2:
		if (D > 28)
		{
			cout << "  ";
			_getch();
			return 0;
		}
	}


	switch (M) //������� ����� ���������� ��� � ����
	{
	case 12: d = d + 30;
	case 11: d = d + 31;
	case 10: d = d + 30;
	case 9: d = d + 31;
	case 8: d = d + 31;
	case 7: d = d + 30;
	case 6: d = d + 31;
	case 5: d = d + 30;
	case 4: d = d + 31;
	case 3: d = d + 28;
	case 2: d = d + 31;
	case 1: d = d + D;

	default:
		break;
		cout << "Your input month is incorrect!";

	}

	switch (d % 7)
	{
	case 1: cout << "Monday" << endl;
		break;
	case 2: cout << "Tuesday" << endl;
		break;
	case 3: cout << "Wednesday" << endl;
		break;
	case 4: cout << "Thursday" << endl;
		break;
	case 5: cout << "Friday" << endl;
		break;
	case 6: cout << "Saturday" << endl;
		break;
	case 0: cout << "Sunday" << endl;
		break;
	}

	_getch();
}
