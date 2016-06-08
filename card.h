#ifndef CARD_H 
#define CARD_H

class Card
{
private:
	//false - nie kradizona, true - kradziona
	bool kradziona;
	int pin;
	int saldo;

public:
	Card();
	Card(bool kr, int p, int zl);
	~Card();

	//porównuje pinz z pin2 zwraca true jeżeli się zgadzają
	bool sprawdz_pin(int pin2);
	//wysyła true jeseli karta jest skardziona 
	bool sprawdz_kradziona();
	//zwraca wartość salda(środki)
	int get_saldo();
	//zmienia wartość salda(środki)
	void set_saldo(int saldo);
	//zwraca nr pin
	int get_pin();

};

#endif
