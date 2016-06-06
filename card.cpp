#include "Card.h"


Card::Card(bool kr, int p, int zl){
	kradziona = kr;
	pin = p;
	saldo = zl;
}
Card::Card(){}
Card::~Card(){}


bool Card::sprawdz_pin(int pin2){
		
	if (pin == pin2){
		return true;
	}
		
	return false;			
}
	
bool Card::sprawdz_kradziona(){
	return kradziona;
}

int Card::get_saldo(){
	return saldo;
}

void Card::set_saldo(int s){
	saldo = s;
}

