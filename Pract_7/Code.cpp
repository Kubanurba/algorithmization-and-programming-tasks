#include <iostream>
#include <bitset>

using namespace std;


int number_of_1pairs(unsigned int x)
{
	int pair = 0;

	for (; x > 0; x = x >> 1)
	{
		if (x & (x >> 1) & 1)
			pair++;
		
	}
	return pair;
}



int main()
{
	unsigned int x;
	cout << "Enter your number x: ";
	cin >> x;

	cout << "Binary value is : " << bitset <32>(x) << "\nNumber of 1 pairs is : "  << number_of_1pairs(x) << endl;

}

