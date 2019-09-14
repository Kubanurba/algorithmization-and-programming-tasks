#include <iostream>
#include <conio.h>

using namespace std;

struct tree
{
	int key;
	tree *l, *r;
};

void Add(int key, tree *&T)
{
	if (!T)
	{
		T = new tree; T->key = key; T->l = T->r = 0;
	}
	else
		if (T->key > key)
			Add(key, T->l);
		else
			Add(key, T->r);
}

void Show(tree *T)
{
	if (T)
	{
		Show(T->l);
		cout << T->key << "   ";
		Show(T->r);
	}
}

void Del(tree *&T)
{
	if (T)
	{
		Del(T->l);
		Del(T->r);
		delete T;
		T = 0;
	}
}


void Process(int del, tree *&T)
{
	if (T != NULL)
	{
		if (T->key == del)
			Del(T);
		else if (T->key < del)
			Process(del, T->r);
		else
			Process(del, T->l);
	}
}

void Input(tree *&T, int data)
{
	int n;
	cout << "Input number of elements(no less than 15!):";
	cin >> n;
	if (n < 15)
	{
		cout << "Wrong input number of elements!";
		_getch();
		exit(0);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << "Input unique " << i <<" element: ";
		cin >> data;
		Add(data, T);
	}
	cout << endl;
}

int main()
{
	int data = 0;
	tree *T = 0;
	int del;

	Input(T, data);
	Show(T);

	cout << endl << endl;
	cout << "Input key of element you'd like to delete: ";
	cin >> del;
	cout << endl;
	
	Process(del, T);
	Show(T);
	Del(T);

	_getch();
	return 0;
}
