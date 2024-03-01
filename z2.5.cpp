//Описать функцию, которая формирует список символов L, включив в него
//по одному разу элементы, которые входят хотя бы в один из списков L1 и L2.



#include<iostream>

using namespace std;

void Get_in_Sort(char *L1, char *L2, int *Am, char *L, int n1, int n2, int& am);

int main()
{
	int n1 = 0, am = 0;
	cout << "Enter a size of L1: ";
	cin >> n1;
	int n2 = 0;
	cout << "Enter a size of L2: ";
	cin >> n2;
	char *L1 = new char[n1];
	int *Am = new int[n1 + n2];
	char* Ln = new char[n1 + n2];
	char* L2 = new char[n2];

	Get_in_Sort(L1, L2, Am, Ln, n1, n2, am);
	char* L = new char[am + 1];
	int aM = 0;
	L[aM] = Ln[aM];
	for (int i = 1; i < n1 + n2; i++)
		if (L[aM] != Ln[i])
		{
			aM++;
			L[aM] = Ln[i];
		}
	
	for (int i = 0; i <= aM; i++)
		cout << L[i] << " ";

	return 0;
}

void Get_in_Sort(char* L1, char* L2, int* Am, char* Ln, int n1, int n2, int& am)
{
	cout << "Enter L1:" << endl;
	for (int i = 0; i < n1; i++)
	{
		cin >> L1[i];
		Am[i] = i + 1;
	}
	cout << "Enter L2:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> L2[i];
		if (i == n2 - 1)
			Am[i + n1] = 0;
		else
			Am[i + n1] = i + 1 + n1;
	}
	
	//=============================

	for (int i = 0; i < n1; i++)
	{
		if(i == 0)
		Ln[i] = L1[i];
		else
		{
			int j = 0;
			while (L1[i] < Ln[i - j - 1] && j != i)
			{
				Ln[i - j] = Ln[i - j - 1];
				j++;
			}
				Ln[i - j] = L1[i];
		}
	}

	for (int i = n1; i < n1 + n2; i++ )
	{
		int j = 0;
		while (L2[i - n1] < Ln[i - j - 1] && j != i)
		{
			Ln[i - j] = Ln[i - j - 1];
			j++;
		}
			Ln[i - j] = L2[i - n1];
	}

	for (int i = 0; i < n1 + n2 - 1; i++)
		if (Ln[i] != Ln[i + 1])
			am++;
}

