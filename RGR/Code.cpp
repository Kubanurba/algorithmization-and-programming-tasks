#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <iomanip>


using namespace std;

//to get the Taylor series of function:
double Taylor(double e, double x, int &s, double an, double series)
{
	if (e < abs(an))
	{
		an = an * ((-s) * (x - 1)) / (s + 1);   //recurrent multiplier
		series = series + an;
		s++;
		series = Taylor(e, x, s, an, series);
	}

	return series;
}

//to get the results(series(x), steps, y(x), absolute error):
void Results(double &Xbeg, double &Xdelta, double &Xend, double &e)
{
	double xnew = Xbeg;
	ofstream DataS("C:\\Users\\Nastya\\Desktop\\DataToSave.txt");  //you should input an adress
	DataS << Xbeg << "  " << Xdelta << "  " << Xend << "  " << e << '\n';
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	while (xnew <= Xend)
	{
		int s = 1;
		double series = xnew - 1;
		double an = xnew - 1;
		series = Taylor(e, xnew, s, an, series);
		cout << "| " << setw(8) << left << xnew << "  " << "| " << "Series (x) =  " << left << setw(12) << series << "   ";
		cout << "| " << "Steps =   " << setw(4) << left << s << "   ";
		double yx = log(xnew);
		double error = abs(series - yx);
		cout << "| " << "y(x) =  " << setw(12) << left << yx << "   ";
		cout << "| " << "Absolute error = " << setw(12) << left << error << "| " << endl;

		DataS << xnew << "   " << series << "  " << s << "  " << yx << "  " << error << '\n';
		xnew += Xdelta;
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	DataS.close();
}

//to input values with the keyboard:
void KeyboardInput(double &Xbeg, double &Xdelta, double &Xend, double &e)
{
	cout << "Input your initial data(0 < x <= 2). Example: Xbeg = 1.2; Xdelta = 0.2; Xend = 2; Epsilon(precision) = 0.01." << endl;
	cout << "Xbeg = ";
	cin >> Xbeg;
	cout << "Xdelta = ";
	cin >> Xdelta;
	cout << "Xend = ";
	cin >> Xend;
	cout << "Epsilon = ";
	cin >> e;
	if (((abs(Xbeg - Xend) > abs(Xdelta)) && (Xbeg < Xend) && (Xdelta > 0) && (Xbeg > 0) && (Xend <= 2) && (e < 1)) == 0)
	{
		cout << "Wrong input values!";
		exit(0);
	}

}

//to read initial values from your file:
void ReadFile(double &Xbeg, double &Xdelta, double &Xend, double &e)
{
	ifstream DataR("C:\\Users\\Nastya\\Desktop\\DataToRead.txt");
	DataR >> Xbeg >> Xdelta >> Xend >> e;
	DataR.close();
}


int main()
{
	double Xbeg(0), Xdelta(0), Xend(0), e(0);
	cout << "Choose the way to start:" << '\n' << "1)Input my own initial data." << '\n' << "2)Read initial data from file." << endl << "Input your choice: ";
	int ch;
	cin >> ch;

	switch (ch) //interaction with user 
	{
	case 1: KeyboardInput(Xbeg, Xdelta, Xend, e);
		break;
	case 2: ReadFile(Xbeg, Xdelta, Xend, e);
		break;
	default: cout << "Wrong input data!!! You should've inputed 1 or 2.";
	}

	Results(Xbeg, Xdelta, Xend, e);

	int save(0);
	cout << "Do you want to save your results?" << '\n' << "1)Yes" << '\n' << "2)No" << endl << "Input your choice: ";
	cin >> save;
	

	switch (save)
	{
	case 1:
		break;
	case 2: remove("DataToSave.txt");  //you should input an adress
		break;
	default:
		cout << "Wrong input data!!! You should've inputed 1 or 2.";
	}

	_getch();
	return 0;
}
