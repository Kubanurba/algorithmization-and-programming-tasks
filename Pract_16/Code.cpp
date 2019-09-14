#include<iostream>
#include<conio.h>
#include<ctime>

using namespace std;

struct queue
{
	int data;
	queue *next;
};

void Push(queue *&head, queue *&tail, int data)
{
	queue *el = new queue;
	el->data = data;
	el->next = NULL;
	if (head == NULL)
		head = tail = el;
	else
	{
		tail->next = el;
		tail = el;
	}
}

void Create(queue *&head, queue *&tail)
{
	for (int i = 0; i < 11; i++)
	{
		int d = rand() % 101 + (-50);
		Push(head, tail, d);
	}
}

void Pop(queue *&head, queue *&tail)
{
	queue *tmp = head;
	head = head->next;
	if (head == NULL)
		tail = NULL;

	delete tmp;
}

void Process(queue *&head, queue *&tail)
{
	queue *ntail = 0, *nhead = 0;
	while (head)
	{
		if (head->data % 2 != 0)
			Push(nhead, ntail, head->data);
		Pop(head, tail);
	}
	head = nhead, tail = ntail;
}

void Output(queue *head)
{
	queue *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}

void Delete(queue *&head, queue *&tail)
{
	while (head != NULL)
	{
		queue *tmp = head;
		head = head->next;
		delete tmp;
	}
	head = tail = 0;
}

int main()
{
	srand(time(NULL));

	queue *head = 0, *tail = 0;

	Create(head, tail); // ������� �������
	Output(head); // ����� ����������
	Process(head, tail); // ��������� �������
	Output(head); // ������� �������� ������� ����� ��������� 
	Delete(head, tail); // ������� �������� ����� �������  

	_getch();
}
