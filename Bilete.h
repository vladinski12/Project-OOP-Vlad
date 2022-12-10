#pragma once
#include <string>
using namespace std;

class Bilete {
	
private:
	
	long id;
	static double bileteTotale;
	static double bileteVandute;
	static double bileteDisponibile;
	string tip;
	string loc;
	
public:
	
	Bilete();
	
	Bilete(string tip,string loc);

	string getTip();

	void setTip(string tip);

	string getLoc();

	void setLoc(string loc);

	static bool checkBilete();

	friend istream& operator>>(istream& in, Bilete& b);

	friend ostream& operator<<(ostream& out,const Bilete b);
};
