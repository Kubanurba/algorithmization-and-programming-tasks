#include <iostream>

using namespace std;

int main()
{
	int m;
	cout << "Your number is : ";
	cin >> m;
	int i = 2;
	
	for (; i < m && m % i; i++);
	if (i == m)
		cout << "The number you`ve entered is prime.";
	else
	{
		cout << "The number you`ve entered is not prime."<<endl;
		cout << "Multipliers are : ";
		int i = 2;
		while (i < m)
		{
			if (m%i == 0)
			{
				cout << i << "*";
				m = m / i;
			}
			else
			{
				i++;
			}
		}
		cout << m << endl;
	}
	
	return 0;
}

