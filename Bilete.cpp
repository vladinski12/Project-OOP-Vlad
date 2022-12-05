#include "Bilete.h"

double Bilete::bileteTotale = 0;
double Bilete::bileteVandute = 0;
double Bilete::bileteDisponibile = 0;

Bilete::Bilete()
{
		bileteTotalePtEveniment = 0;
		bileteVandutePtEveniment = 0;
		bileteDisponibilePtEveniment = 0;
		tip = "";
}


Bilete::Bilete(double bileteTotalePtEveniment, double bileteVandutePtEveniment, double bileteDisponibilePtEveniment, string tip) : Bilete()
{
		this->bileteTotalePtEveniment = bileteTotalePtEveniment;
		this->bileteVandutePtEveniment = bileteVandutePtEveniment;
		this->bileteDisponibilePtEveniment = bileteDisponibilePtEveniment;
		this->tip = tip;
}

double Bilete::getBileteTotale() {
	return bileteTotale;
}


