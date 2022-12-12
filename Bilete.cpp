#include <iostream>
#include "Bilete.h"
using namespace std;

double Bilete::bileteTotale = 0;
double Bilete::bileteVandute = 0;
double Bilete::bileteDisponibile = 0;

Bilete::Bilete() :id(++Bilete::bileteTotale)
{
		tip = "-";
		loc = "-";
}


Bilete::Bilete( string tip,string loc) : Bilete()
{
		this->tip = tip;
}

string Bilete::getTip() {
	return tip;
}

void Bilete::setTip(string tip) {
	if (tip != "") { this->tip = tip; }
}

string Bilete::getLoc() {
	return loc;
}

void Bilete::setLoc(string tip) {
	if (loc != "") { this->loc = loc; }
}

bool Bilete::checkBilete() {
	if (bileteTotale == bileteVandute + bileteDisponibile)
		return true;
	else
		return false;
}

istream& operator>>(istream& in, Bilete& b) {
	cout << "Introduceti tipul de bilet: ";
	in >> b.tip;
	cout << "Introduceti locul: ";
	in >> b.loc;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out,const Bilete b) {
	cout << endl;
	out << "ID: " + to_string(b.id) << endl;
	out <<"Tipul biletului: " + b.tip << endl;
	out << "Loc: " + b.loc<<endl;
	return out;
}

Bilete Bilete::operator+(Bilete b) {
	this->loc = b.getLoc() + this->loc;
	return *this;
}

Bilete Bilete::operator-(Bilete b) {
	this->loc = to_string(stoi(b.getLoc()) - stoi(this->loc));
	return *this;
}

void Bilete::buyTicket() {
	Bilete::bileteVandute++;
	Bilete::bileteDisponibile--;
}




