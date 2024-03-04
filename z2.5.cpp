//Описать функцию, которая формирует список символов L, включив в него
//по одному разу элементы, которые входят хотя бы в один из списков L1 и L2.



#include<iostream>

using namespace std;

int n1 = 0, n2 = 0;

struct Mas
{
	char* L = new char[n1 + n2];
	int* Am = new int[n1 + n2];
};

void Get_in_Sort(Mas*& L1, Mas*& L2, Mas*& Ln, int n1, int n2);

int main()
{
	
	cout << "Enter a size of L1: ";
	cin >> n1;
	cout << "Enter a size of L2: ";
	cin >> n2;
	Mas *L1 = new Mas;
	Mas* Ln = new Mas;
	Mas* L2 = new Mas;

	Get_in_Sort(L1, L2, Ln, n1, n2);
	delete L1;
	delete L2;

	/*После сортировки, я решил представить наш конечный массив не в виде нового Mas,
	а в виде изменённого Ln->Am (ссылки на первые встречи символов остаются, а ссылки на повторы изменяются на -1)*/

	int aM = 0;
	for (int i = 0; i < n1 + n2 - 1; i++)
	{

		if (Ln->L[aM] != Ln->L[Ln->Am[i]])
		{
			Ln->Am[aM] = Ln->Am[i];
			aM = Ln->Am[i];
		}
		else
			Ln->Am[i] = -1;
	}
	Ln->Am[aM] = Ln->Am[n1 + n2 - 1];
	aM = 0;
	cout << endl;
	while (Ln->Am[aM] != Ln->Am[n1 + n2 - 1])
	{
		cout << Ln->L[Ln->Am[aM]] << " ";
		aM = Ln->Am[aM];
	}
	cout << Ln->L[Ln->Am[aM]] << endl;

	return 0;
}

void Get_in_Sort(Mas*& L1, Mas*& L2, Mas*& Ln, int n1, int n2)
{
	cout << "Enter L1:" << endl;
	for (int i = 0; i < n1; i++)
	{
		cin >> L1->L[i];
		Ln->Am[i] = i + 1;
	}
	cout << "Enter L2:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> L2->L[i];
		if (i == n2 - 1)
			Ln->Am[i + n1] = 0;
		else
			Ln->Am[i + n1] = i + 1 + n1;
	}
	
	//=============================

	for (int i = 0; i < n1; i++)
	{
		if(i == 0)
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

	for (int i = n1; i < n1 + n2; i++ )
	{
		int j = 0;
		while (L2->L[i - n1] < Ln->L[i - j - 1] && j != i)
		{
			Ln->L[i - j] = Ln->L[i - j - 1];
			j++;
		}
			Ln->L[i - j] = L2->L[i - n1];
	}
}

