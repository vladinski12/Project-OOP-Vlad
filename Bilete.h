#pragma once
#include <string>
#include "Eveniment.h"
using namespace std;

class Bilete {
	
private:
	static double bileteTotale;
	static double bileteVandute;
	static double bileteDisponibile;
	const long id;
	string tip;
	string loc;
	
public:
	
	Bilete();													//constructor implicit
	
	Bilete(string tip, string loc);								//constructor cu parametri

	string getTip();											//getter tip

	void setTip(string tip);									//setter tip

	string getLoc();											//getter loc

	void setLoc(string loc);									//setter loc

	static bool checkBilete();									//metoda statica

	friend istream& operator>>(istream& in, Bilete& b);			//supraincarcare operator >>

	friend ostream& operator<<(ostream& out,const Bilete b);	//supraincarcare operator <<

	Bilete operator+(Bilete b);									//supraincarcare operator +
	
	Bilete operator-(Bilete b);									//supraincarcare operator -

	void buyTicket(Eveniment e);							    //metoda de cumparare a unui bilet

	void showTicket();											//metoda de afisare a unui bilet
};
