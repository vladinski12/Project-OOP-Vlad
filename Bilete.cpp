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

double Bilete::getBileteTotalePtEveniment() {
	return bileteTotalePtEveniment;
}

void Bilete::setBileteTotalePtEveniment(double bileteTotale) {
	if (bileteTotale >= 0) { this->bileteTotalePtEveniment = bileteTotale; }
}

double Bilete::getBileteVandutePtEveniment() {
	return bileteVandutePtEveniment;
}

void Bilete::setBileteVandutePtEveniment(double bileteVandute) {
	if (bileteVandute >= 0) { this->bileteVandutePtEveniment = bileteVandute; }
}

double Bilete::getBileteDisponibilePtEveniment() {
	return bileteDisponibilePtEveniment;
}

void Bilete::setBileteDisponibilePtEveniment(double bileteDisponibile) {
	if (bileteDisponibile >= 0) { this->bileteDisponibilePtEveniment = bileteDisponibile; }
}








