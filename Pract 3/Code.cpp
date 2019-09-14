#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float a(-1.35), b(1.45), c(5.15), d(-2.22);

	float y = (2 * tan(b) / log(fabs(2 * a)) - sqrt((sqrt(fabs(d) / c))));

	cout << "a=" << a << '\n' << "b=" << b << '\n' << "c=" << c << '\n' << "d=" << d << '\n' << "y=" << y << '\n';

	system("pause");
	return 0;
}
