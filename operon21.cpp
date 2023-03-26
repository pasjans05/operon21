// operon21.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("klucze.txt");

bool czyPierwsza(unsigned long long int n)
{
	if (n == 1) return false;
	for (unsigned long long int i = 2; i <= (n / 2); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

void minImax()
{
	unsigned long long int n, e, d;
	unsigned long long int min = 18446744073709551615;
	unsigned long long int max = 0;
	for (int i = 0; i < 50; i++)
	{
		plik >> n >> e >> d;
		int dlgsc = 0;
		unsigned long long int nn = n;
		while (nn > 0)
		{
			dlgsc++;
			nn /= 10;
		}
		if (dlgsc % 2 == 1) dlgsc = (dlgsc / 2) + 1;
		else dlgsc /= 2;
		cout << n << "\t" << dlgsc << endl;
		for (int j = 2; j < pow(10, dlgsc); j++)
		{
			if (czyPierwsza(j))
			{
				if (n % j == 0/* && czyPierwsza(n / j)*/)
				{
					if (j < min) min = j;
					if (j > max) max = j;
				}
			}
		}
	}
	plik.close();
	cout << min << "\t" << max << endl;
}

int main()
{
	minImax();
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
