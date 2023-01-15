#include <iostream>
#include <fstream>
#include "Bilete.h"
#include "Bilete.h"
using namespace std;

double Bilete::bileteTotale = 1000;
double Bilete::bileteVandute = 0;
double Bilete::bileteDisponibile = 1000;

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
	if (Bilete::bileteTotale == Bilete::bileteVandute + Bilete::bileteDisponibile)
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

void Bilete::buyTicket(Eveniment e) {
	if (bileteDisponibile > 0) {
		bileteTotale++;
		bileteDisponibile--;
		bileteVandute++;
		ofstream f("bilete.bin", ios::out | ios::binary);
		if (f.is_open()) {
			string buffer(e.getDenumire());
			int length = buffer.length();
			f.write((char*)&length, sizeof(length));
			f.write(buffer.c_str(), length + 1);
			string dash = "-";
			length = dash.length();
			f.write((char*)&length, sizeof(length));
			f.write(dash.c_str(), length + 1);
			f.write((char*)&id, sizeof(id));
			f.write((char*)&id, sizeof(id));
			f.close();
		}
		else {
			cout << "Fisierul nu a putut fi deschis!";
		}
	}
}

void Bilete::showTicket() {
	cout << "Bilete totale: " << Bilete::bileteTotale << endl;
	cout << "Bilete vandute: " << Bilete::bileteVandute << endl;
}



