#pragma once
#include <string>
using namespace std;

class Bilete {
private:
	double id;
	double bileteTotalePtEveniment;
	double bileteVandutePtEveniment;
	double bileteDisponibilePtEveniment;
	static double bileteTotale;
	static double bileteVandute;
	static double bileteDisponibile;
	string tip;
	
public:
	Bilete();
	Bilete(double bileteTotalePtEveniment, double bileteVandutePtEveniment, double bileteDisponibilePtEveniment,string tip);

	double getBileteTotalePtEveniment();

	void setBileteTotalePtEveniment(double bileteTotale);

	double getBileteVandutePtEveniment();

	void setBileteVandutePtEveniment(double bileteVandute);

	double getBileteDisponibilePtEveniment();

	void setBileteDisponibilePtEveniment(double bileteDisponibile);

	static bool checkBilete();

	friend ostream& operator<<(ostream& out,const Bilete b);
};
