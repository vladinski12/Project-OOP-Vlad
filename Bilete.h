#pragma once
#include <string>
using namespace std;

class Bilete {
private:
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
	static double getBileteTotale();
};
