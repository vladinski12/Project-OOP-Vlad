#include "Adresa.h"

Adresa::Adresa() 
{
	strada = "";
	numar = "";
	oras = "";
}															

Adresa::Adresa(string strada, string numar, string oras):Adresa(){
	this->strada = strada;
	this->numar = numar;
	this->oras = oras;
}

Adresa::Adresa(const Adresa& a) {
	this->strada = a.strada;
	this->numar = a.numar;
	this->oras = a.oras;
}

string Adresa::getStrada() {
	return strada;
}

void Adresa::setStrada(string strada) {
	if (strada != "") {
		this->strada = strada;
	}
}

string Adresa::getNumar() {
	return numar;
}

void Adresa::setNumar(string numar) {
	if (numar != "") {
		this->numar = numar;
	} 
}

string Adresa::getOras() {
	return oras;
}

void Adresa::setOras(string oras) {
	if (oras != "") {
		this->oras = oras;
	}
}


bool Adresa::checkLoc() {
	if (stoi(numar) > 0)
		return true;
	else
		return false;
}


bool Adresa::Rezervare(long locuriRez) {
	Locatie::setNrMAXlocuri(locuriRez);
}
