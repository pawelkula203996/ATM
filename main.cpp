#include "Bankomat.h"
#include "Card.h"
using namespace std;

int main(){


	Bankomat B = Bankomat(12000);
	B.wczytaj_karte(1);

	return 0;
}
