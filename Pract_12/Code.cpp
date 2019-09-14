#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>


using namespace std;

void Pr(char s[], char S1[])
{
	char *w;
	_strrev(s);
	w = strtok(s, " ");

	while (w)
	{
		_strrev(w);
		strcat(S1, w);
		strcat(S1, " ");
		w = strtok(NULL, " ");
	}
}


int main()
{
	char s[] = "Korovka lubit kushat` travku";
	char S1[] = "";
	cout << "Before manipulation :   \n" << s << endl;
	cout << "After : " << endl;

	Pr(s, S1);
	cout << S1;

	_getch();
}
