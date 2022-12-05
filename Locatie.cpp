#include "Locatie.h"

Locatie::Locatie()
{
	nrRanduri=10;
	nrMAXlocuri = 100;
	double nrColoane = nrMAXlocuri / nrRanduri;
	locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
}

Locatie::Locatie(double nrRanduri, double nrMAXlocuri, int** locuri)
{
	this->nrRanduri = nrRanduri;
	this->nrMAXlocuri =nrMAXlocuri;
	double nrColoane = nrMAXlocuri / nrRanduri;
	this->locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) this->locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
}

Locatie::~Locatie() {
	if (locuri != nullptr) {
			for (int i = 0; i < nrRanduri; i++) {
				delete[] locuri[i];
			}
		delete[] locuri;
	}
}