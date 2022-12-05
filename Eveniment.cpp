#include "Eveniment.h"

Eveniment::Eveniment():data("01.01.2000"),ora("00:00")
{
	denumire = new char[10];
	strcpy_s(denumire, 10, "Necunoscut");
};

Eveniment::Eveniment(string data, string ora, char* denumire):data(data),ora(ora)
{
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(this->denumire, strlen(e.denumire) + 1, e.denumire);
}

Eveniment::~Eveniment() {
	if (denumire != nullptr)delete[] denumire;
}