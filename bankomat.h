#ifndef BANKOMAT_H
#define BANKOMAT_H
#include "Card.h"
#include <iostream>
using namespace std;

class Bankomat
{
private:
	int gotowka;
	Card karta,zla,test;

public:
	Bankomat(int g);
	~Bankomat();

	//Przypisuje zmiennej karta dane związane z numerem karty zwraca true jeżeli operacja się powiodła
	//dane uzyskuje z serwera(plik.txt)
	bool wczytaj_karte(int card_num);
	//sprawdza	czy karta jest kradziona (operacja karta.sprawdz_kradziona())
	bool czy_skradziona();
	//prosi uzytkownika o podanie pinu 3x jezeli jest poprawne zwraca true, jezeli false połyka karte
	//zamienia pola w karta na pola z karta zla
	bool podaj_pin();
	//sprawdza saldo na karcie (karta.get_saldo()) nastepnie wyświetla wartosc
	int sprawdz_saldo();
	//wypłaca pieniądze z karty w krokach:
	//1. prosi o wprowadzenie kwoty
	//2. sprawdza dostępnosc salda (karta.get_saldo) (jesli nie ma podaje saldo i prosi o podanie innej kwoty)
	//2* sprawdza dostępnosc gotowki w bankomacie
	//3. odejmuje kwote wypłacaną od salda
	//3* odejmuje kwote wypłacaną od gotowki
	//4. ustawia nowe saldo na karcie (karta.set_saldo)
	//5. zapisuje dane karty do pliku
	void wyplac();
	bool odczyt(int card_num);  // bool - zeby sprawdził czy dana karta istnieje
	void zapis(int card_num);


};

#endif
