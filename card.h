#ifndef CARD_H 
#define CARD_H

class Card
{
private:
	//proponujê 0 - nie kradizona, 1 - kradziona
	int kradziona;
	int pin;
	int saldo;

public:
	Card(int kr, int pin, int zl);

	//porównuje pinz z pin2 zwraca true je¿eli siê zgadzaj¹
	bool sprawdz_pin(int pin2);
	//wysy³a true jeseli karta jest skardziona 
	bool sprawdz_kradziona();
	//zwraca wartosc srodki
	int get_saldo();
	//zmienia wartosc srodki
	void set_saldo(int saldo);

};

#endif
