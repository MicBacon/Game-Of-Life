#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "gameOfLife.h"

using namespace std;

int main()
{
	ifstream dane;
	ofstream wyjscie;
	char komorka;
	int pokolenie = 100;
	int sasiedzi;

	dane.open("gra.txt");
	wyjscie.open("wyjscie_1.txt");
	int n = 12;
	int m = 20;
	int tab[12][20];
	int next[12][20];

	for (int i=0; i < n; i++) {
		for (int j=0; j < m; j++) {
			dane >> komorka;
			if (komorka == '.') {
				tab[i][j] = 0;
			}
			else {
				tab[i][j] = 1;
			}

		}
	}

	cout << 1 << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tab[i][j] == 1) {
				cout << 'X' << " ";
			}
			else
				cout << '.' << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	int p = 1;
	
	while (p!=(pokolenie)) {
		//obliczanie liczby s¹siadów
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sasiedzi = 0;
				for (int dx = -1; dx <= 1; dx++) {
					for (int dy = -1; dy <= 1; dy++) {
						if(tab[(n + i + dx) % n][(m + j + dy) % m] == 1){
							sasiedzi++;
						}
					}
				}

				if (tab[i][j] == 1) {
					sasiedzi--;
				}
				
		//zapisywanie komórek do nowej tablicy
				if (tab[i][j] == 1 &&
					sasiedzi == 2 || sasiedzi == 3) {
					next[i][j] = 1;
				}
				else if (tab[i][j] == 0 && sasiedzi == 3) {
					next[i][j] = 1;
				}
				else {
					next[i][j] = 0;
				}
			}
		}

		Sleep(1000);
		system("cls");
		cout << p+1 << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tab[i][j] = next[i][j];
				if (next[i][j] == 1) {
					cout << 'X' << " ";
				}
				else
					cout << '.' << " ";
			}
			cout << endl;
		}
		cout << endl;
		p++;
	}
	

	return 0;
}

