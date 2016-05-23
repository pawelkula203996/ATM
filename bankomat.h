#ifndef BANKOMAT_H
#define BANKOMAT_H
#include "Card.h"

class Bankomat
{
private:
	//mozna usunac wedle zyczen
	int gotowka;
	Card karta1;

public:
	Bankomat();

	//Przypisuje zmiennej karta1 dane zwi¹zane z numerem karty zwraca true je¿eli operacja siê powiod³a
	//dane uzyskuje z serwera
	bool wczytaj_karte(int numer);
	//sprawdza	czy karta1 jest kradziona (operacja karta1.sprawdz_kradziona())
	bool czy_skradziona();
	//prosi uzytkownika o podanie pinu 3x jezeli jest poprawne zwraca true, jezeli false po³yka karte
	//(ustawia pola karta1 na null)
	bool podaj_pin();
	//sprawdza saldo na karcie (karta1.get_saldo()) nastepnie drukuje wartosc
	string sprawdz_saldo();
	//wyplaca pieniadze z karty w krokach:
	//1. prosi o wprowadzenie kwoty
	//2. sprawdza dostepnosc salda (karta1.get_saldo) (jesli nie ma podaje saldo i prosi o podanie innej kwoty)
	//2* sprawdza dostêpnosc gotowki w bankomacie
	//3. odejmuje kwote wyplacana od salda
	//3* odejmuje kwote wyplacana od gotowki
	//4. ustawia nowe saldo na karcie (karta.set_saldo)
	//5. zapisuje dane karty do pliku i ustawia pola karty na null(usowa karte)
	void wyplac();


};

#endif
