#include "Bankomat.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int gotowka;
Card karta,zla,test;


Bankomat::Bankomat(int g){
	gotowka = g;
	zla = Card(true, 0, 0);
	test = Card(false, 1234, 14560);  // test programu
	
}
Bankomat::~Bankomat(){}

bool Bankomat::wczytaj_karte(int numer){

	//wczytywanie z pliku (?)

	if (numer = 1){ karta = test; }  //test programu, docelowo odczyt z pliku

	int x = 0;  //zmienna potrzebna do sprawdzania pinu x3
	int op;		//zmienna potrzebna do wyboru operacji

	if (czy_skradziona()){
		karta = zla;
		cout << "Karta skradziona!" << endl;
		return false;
	}
	while (x < 3){
		if (!podaj_pin()){
				cout << "Nieprawidlowy kod pin!" << endl;
				x += 1;
		}
		else break;
	}
	if (x >= 3){
		karta = zla;
		cout << "Karta zablokowana..." << endl;
		system("pause");
		return false;
	}

	while (1){
		cout << "1. Sprawdz saldo" << endl;
		cout << "2. Wyplac srodki" << endl;
		cout << "3. Zakoncz" << endl;
		cin >> op;

		if (op == 1){
			op = 0;
			cout << "Dostepne srodki: " << sprawdz_saldo() << endl;
			system("pause");
		}
		if (op == 2){
			op = 0;
			wyplac();
		}
		if (op == 3){
			op = 0;
			return 0;
		}
	}

	//zapis do pliku (?)

	return true;
}
		
	

bool Bankomat::czy_skradziona(){
	return karta.sprawdz_kradziona();
}

bool Bankomat::podaj_pin(){
	int pin2;
	cout << "Podaj kod pin: " << endl;
	cin >> pin2;
	return karta.sprawdz_pin(pin2);
}

int Bankomat::sprawdz_saldo(){
	return karta.get_saldo();
}

void Bankomat::wyplac(){
		
	int kwota;  //kwota którą chcemy wypłacić

	while (1){
		cout << "Podaj kwote: " << endl;
		cin >> kwota;
		int saldo = karta.get_saldo();
		if (kwota <= saldo){
			if (kwota <= gotowka){
				saldo = saldo - kwota;
				gotowka = gotowka - kwota;
				karta.set_saldo(saldo);
				cout << "Wyplacono.." << endl;
				break;
			}
			else {
				cout << "Bankomat bez kasy..." << endl;
				break;
			}
		}
		else{
			cout << "Brak dostepnych srodkow" << endl;
			cout << "Dostepne srodki: " << sprawdz_saldo() << endl;
		}
	}
}
