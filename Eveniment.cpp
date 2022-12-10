#include <iostream>
#include <string>
#include "Eveniment.h"
using namespace std;

Eveniment::Eveniment()
{
	data = "01.01.2000"; 
	ora = "00:00";
	denumire = new char[11];
	strcpy_s(denumire, 11, "Necunoscut");
};

Eveniment::Eveniment(string data, string ora, const char* denumire)
{
	this->data = data;
	this->ora=ora;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->data = e.data;
	this->ora = e.ora;
	this->denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(this->denumire, strlen(e.denumire) + 1, e.denumire);
}

Eveniment::~Eveniment() {
	if (denumire != nullptr)delete[] denumire;
}

string Eveniment::getData() {
	return data;
}

void Eveniment::setData(string data) {
	if (data != "") { this->data = data; }
}

string Eveniment::getOra(){
	return ora; 
}

void Eveniment::setOra(string ora) {
	if (ora != "") { this->ora = ora; }
}

char* Eveniment::getDenumire() {
	return denumire; 
}

void Eveniment::setDenumire(const char* denumire) {
	if (denumire != nullptr) {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
}

istream& operator>>(istream& in, Eveniment& e) {
	cout << "Data: ";
	in >> e.data;
	cout << "Ora: ";
	in >>e.ora;
	cout << "Introdu denumirea: ";
	string buffer;
	in >> buffer;
	e.setDenumire(buffer.c_str());
	return in;
}

ostream& operator<<(ostream& out, const Eveniment e){
	cout << endl;
	out <<"Data: " + e.data << endl;
	out <<"Ora: " + e.ora << endl;
	out <<"Denumire: " +(string) e.denumire << endl;
	return out;
}