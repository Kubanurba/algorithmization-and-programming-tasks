#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float x, y, p, a;

	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	cout << "Input a: ";
	cin >> a;
	cout << "Input p: ";
	cin >> p;

	if (y < (a*x*x) - p)
		cout << "The point is outside the parabola." << '\n';
	else
	{
		if (y >= fabs(x))
			cout << "The point is above the line.";
		else
			cout << "The point is in the area.";
	}
	_getch();
}

