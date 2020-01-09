#include <iostream>
#include <cctype>
#include "Stack.h"

int main()
{
	using namespace std;
	cout << "Podaj wielkosc stosu: ";
	int wielkosc_stosu;
	cin >> wielkosc_stosu;
	Stack st(wielkosc_stosu);				// tworzy pusty stos
	char ch;
	unsigned long po;
	cout << "Nacisnij D,aby wprowadzic deklaracje,\n"
		"P, aby przetworzyc deklaracje lub K, aby zakonczyc.\n";
	while (cin >> ch && toupper(ch) != 'K')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'D':
		case 'd':
			cout << "Podaj nr. nowej deklaracji: ";
			cin >> po;
			if (st.isfull())
				cout << "Stos pelen\n";
			else
				st.push(po);
			break;
		case 'p':
		case 'P':
			if (st.isempty())
				cout << "Stos pusty\n";
			else
			{
				st.pop(po);
				cout << "Deklaracja nr " << po << " zdjeta\n";
			}
			break;
		}


		cout << "Nacisnij D,aby wprowadzic deklaracje,\n"
			"P, aby przetworzyc deklaracje lub K, aby zakonczyc.\n";
	}
	Stack kopia_st;// (st);
	kopia_st = st;
	if (!st.isempty())
	{
		if (!kopia_st.isfull())
		{
			cout << "kopiA: ";
			kopia_st.Show();
			cout << "Podaj nr. nowej deklaracji: ";
			cin >> po;
			kopia_st.push(po);
		}
		else
			kopia_st.pop(po);
	}
	cout << "Zawartosc glownej kolejki:\n";
	st.Show();
	cout << "Zawartosc kopi kolejki:\n";
	kopia_st.Show();

	cout << "Fajrant!!\n";
	cin.get();
	cin.get();
	return 0;
}