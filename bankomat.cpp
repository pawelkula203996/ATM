#include "Bankomat.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;


int gotowka;
Card karta,zla,test;


Bankomat::Bankomat(int g){
	gotowka = g;
	zla = Card(true, 0, 0);
	test = Card(false, 1234, 14560);  // test programu
	
}
Bankomat::~Bankomat(){}

bool Bankomat::wczytaj_karte(int card_num){

	int x = 0;  //zmienna potrzebna do sprawdzania pinu x3
	int op;		//zmienna potrzebna do wyboru operacji

	if (!odczyt(card_num)){               //wczytywanie z pliku

		cout << "Taka karta nie istnieje!" << endl;
		return false;
	}

	//if (card_num = 1)karta = test;  //test programu, docelowo odczyt z pliku

	
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
			zapis(card_num);    //zapis do pliku 
			return 0;
		}
	}

		
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

void Bankomat::zapis(int card_num){

	int i = 0;

	string linia[5];
	string kr = to_string(karta.sprawdz_kradziona());
	string p  = to_string(karta.get_pin());
	string zl = to_string(karta.get_saldo());

	fstream plik;
	plik.open("karty.txt", ios::in);  // | ios::app);


	string line = to_string(card_num) + "|" + kr + "/" + p + "/" + zl;

	while (getline(plik,linia[i])){

		string delimiter_0 = "|";
		
		int nr = atoi((linia[i].substr(0, linia[i].find(delimiter_0))).c_str());

		if (card_num == nr){

			linia[i] = line;
		}

		i++;
	}

	plik.close();
	plik.open("karty.txt", ios::out);

	for (int k = 0; k < i; k++){

		plik << linia[k] << endl;

	}

	plik.close();

}

bool Bankomat::odczyt(int card_num){

	bool kr = 0;
	int  p = 0;
	int zl = 0;

	string linia;
	bool found = false;
	fstream plik;

	plik.open("karty.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Plik nie istnieje!" << endl;
		exit(0);
	}

	while (getline(plik, linia))
	{
		string delimiter_0 = "|";
		string delimiter_1 = "/";
		int nr = atoi((linia.substr(0, linia.find(delimiter_0))).c_str());    //kr = atoi(linia.c_str()); break; (konwersja)


		linia.erase(0, linia.find(delimiter_0) + delimiter_0.length());

		if (nr == card_num)
		{
			found = true;
			kr = atoi(linia.substr(0, linia.find(delimiter_1)).c_str());
			linia.erase(0, linia.find(delimiter_1) + delimiter_1.length());
			p = atoi(linia.substr(0, linia.find(delimiter_1)).c_str());
			linia.erase(0, linia.find(delimiter_1) + delimiter_1.length());
			zl = atoi(linia.substr(0).c_str());
			linia.erase(0);
		
			break; // no bo jak znalazl juz nasza karte to nie musi szukac
		}

	}

	plik.close();

	if(found)karta = Card(kr, p, zl);
	
	return found;

}
