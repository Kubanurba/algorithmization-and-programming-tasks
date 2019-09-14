#include <iostream>
#include <conio.h>

using namespace std;


float Sum(float d, int n, float an)
{
	if (n-1)
	{
		an = an + d;
		n--;
		an = Sum(d, n, an);
	}
	return an;
}

void Input(float &a1, float &d, int &n)
{
	cout << "a1 = ";
	cin >> a1;
	cout  << "d = ";
	cin >> d;
	cout  << "n =  ";
	cin >> n;
}

int main()
{
	float a1;
	float d;
	int n;
	Input(a1, d, n);
	float an = a1;
	an = Sum(d, n, a1);
	cout << "a" << n << " = " << an;

	_getch();
	return 0;
}
