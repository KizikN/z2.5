#include<iostream>

using namespace std;

struct Mas
{
	char* L;
	int* Am;
};

void Get_in_Sort(Mas*& L1, Mas*& L2, Mas*& Ln, int n1, int n2);

int main()
{
	int l1 = 0, l2 = 0;
	cout << "Enter a size of L1: ";
	cin >> l1;
	cout << "Enter a size of L2: ";
	cin >> l2;
	Mas* L1 = new Mas;
	L1->L = new char[l1];
	L1->Am = new int[l1];
	Mas* Ln = new Mas;
	Ln->L = new char[l1 + l2];
	Ln->Am = new int[l1 + l2];
	Mas* L2 = new Mas;
	L2->L = new char[l2];
	L2->Am = new int[l2];

	Get_in_Sort(L1, L2, Ln, l1, l2);

	int AM = 0;
	int aM = 0;
	for (int i = 0; i < l1 + l2 - 1; i++)
	{

		if (Ln->L[aM] != Ln->L[Ln->Am[i]])
		{
			Ln->Am[aM] = Ln->Am[i];
			aM = Ln->Am[i];
			AM++;
		}
		else
			Ln->Am[i] = -1;
	}
	Ln->Am[aM] = 0;
	AM++;

	aM = 0;
	Mas* L = new Mas;
	L->Am = new int[AM];
	L->L = new char[AM];

	for(int j = 0; j < AM; j++)
	{
		L->L[j] = Ln->L[Ln->Am[aM]];
		aM = Ln->Am[aM];
		L->Am[j] = aM;
	}

	cout << endl;

	for (int i = 0; i < AM; i++)
		cout << L->L[i] << " ";

	return 0;
}

void Get_in_Sort(Mas*& L1, Mas*& L2, Mas*& Ln, int n1, int n2)
{
	cout << "Enter L1:" << endl;
	for (int i = 0; i < n1; i++)
	{
		cin >> L1->L[i];
		L1->Am[i] = i + 1;
	}
	cout << "Enter L2:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> L2->L[i];
		if (i == n2 - 1)
			L2->Am[i + n1] = 0;
		else
			L2->Am[i + n1] = i + 1 + n1;
	}

	//=============================

	for (int i = 0; i < n1; i++)
	{
		if (i == 0)
			Ln->L[i] = L1->L[i];
		else
		{
			int j = 0;
			while (L1->L[i] < Ln->L[i - j - 1] && j != i)
			{
				Ln->L[i - j] = Ln->L[i - j - 1];
				j++;
			}
			Ln->L[i - j] = L1->L[i];
		}
	}

	for (int i = n1; i < n1 + n2; i++)
	{
		int j = 0;
		while (L2->L[i - n1] < Ln->L[i - j - 1] && j != i)
		{
			Ln->L[i - j] = Ln->L[i - j - 1];
			j++;
		}
		Ln->L[i - j] = L2->L[i - n1];
	}

	for (int i = 0; i < n1 + n2; i++)
	{
		if (i == n2 + n1 - 1)
			Ln->Am[i] = 0;
		else
			Ln->Am[i] = i + 1;
	}
}