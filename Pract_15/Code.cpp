#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;


struct customer
{
	const char *s_name;
	const char *f_name;
	const char *l_name;
	const char *adr;
	int discount;
};

void Output(customer *persons, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "�.�.�.: " << persons[i].s_name << " " << persons[i].f_name << " " << persons[i].l_name << endl;
		cout << "�����: " << "�." << persons[i].adr << endl;
		cout << "������: " << persons[i].discount << "%" << endl;
	}
}

void Process(customer *persons, int &n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++)
		{

			if (i != j && (strcmp(persons[i].s_name, persons[j].s_name) == 0) && (strcmp(persons[i].adr, persons[j].adr) == 0) &&
				(strcmp(persons[i].f_name, persons[j].f_name) == 0) && (strcmp(persons[i].l_name, persons[j].l_name) == 0))
			{
				for (int k = j; k < n - 1; k++)
					persons[k] = persons[k + 1];
				n--; j--;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	customer persons[] = { { "�������", "��������", "�����������", "������", 15 },
	{ "�������", "�������", "���������", "������", 8 },
	{ "������", "������", "����������", "����", 3 },
	{ "�����", "�������", "����������", "�������", 16 },
	{ "�����", "�������", "����������", "�������", 17 } };
	int n = sizeof(persons) / sizeof(customer);

	Output(persons, n);
	Process(persons, n);
	cout << endl << "After : " << endl << endl;
	Output(persons, n);

	_getch();
	return 0;
}
