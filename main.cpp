#include "Bankomat.h"
#include "Card.h"
using namespace std;

int main(){

	int card_num;

	Bankomat B = Bankomat(12000);

	while (1){

		cout << "Podaj nr karty: " << endl;
		cin >> card_num;

		B.wczytaj_karte(card_num);
		cout << "Dziekujemy za skorzystanie z naszych usulg" << endl;

		system("pause");
	}
	
	return 0;
}
