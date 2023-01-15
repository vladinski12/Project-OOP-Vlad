// Proiect POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Eveniment.h"
#include "Locatie.h"
#include "Bilete.h"
using namespace std;

int getInput()
{
    int alegere;
    cin >> alegere;
    return alegere;
}

void DisplayMeniu()
{
    cout << "Meniu\n";
    cout << "Introdu optiunea\n";
    cout << "1 - Evenimente disponibile\n";
    cout << "2 - Cumpara bilet\n";
    cout << "3-  Adauga Eveniment\n";
    cout << "4 - Iesire\n";
    cout << "Optiunea: ";
}

vector<Eveniment> evenimenteDisponibile() {
    ifstream f("fisier.txt", ios::in);
    int n = 0;
    f >> n;
    vector<Eveniment>e;
    for (int i = 0; i < n; i++) {
        Eveniment ei;
        string data, ora, buffer;
        f >> data;
        f >> ora;
        f >> buffer;
        ei.setOra(ora);
        ei.setData(data);
        ei.setDenumire(buffer.c_str());
        e.push_back(ei);
    }
    return e;
}

void AdaugaEveniment(vector<Eveniment> &e) {
    system("cls");
    Eveniment e1;
    cin >> e1;
    e.push_back(e1);
    return;
}

void DisplayEvenimente(vector<Eveniment>e ,int& alegere)
{
    system("cls");
    cout << "Optiuni\n";
    for (int i = 0; i < e.size(); i++) {
        cout << e[i].getDenumire() << endl;
    }
    cout << 1 << " - Iesire\n";
    if (e.size() != 0) {
        cout << "Optiunea: ";
        alegere = getInput();
        if (alegere == 1) {
            return;
        }
        else {
            alegere = 4;
            cout << endl << "Nu e o optiune valabila!!!" << endl;
        }
    }
    else {
        alegere = 4;
        cout << endl << "Nu sunt evenimente disponibile" << endl;
    }
}

void cumparaBilet() {
    vector<Eveniment>e = evenimenteDisponibile();
    for (int i = 0; i < e.size(); i++) {
        cout << e[i] << endl;
    }
}

void DisplayOptiuni(vector<Eveniment>e)
{
    system("cls");
    cout << "Optiuni\n";

    for (int i = 0; i < e.size(); i++) {
        cout << i+1 << " - " << e[i].getDenumire() << endl;
    }
    cout <<e.size()+1<< " - Iesire\n";
    cout << "Optiunea: ";
}

void Optiuni(vector<Eveniment>e,int& alegere)
{
    system("cls");
    DisplayOptiuni(e);
    alegere = getInput()-1;
    if (alegere == -1) { alegere = 3;};
    if (alegere+1 == e.size()+1) { return; }
    if (e.size() != 0)
    {
        if (alegere <= e.size()) {
            Bilete b;
            b.buyTicket(e[alegere]);
        }
        else {
            alegere = 4;
            cout << endl << "Nu e o optiune valabila!!!" << endl;
        }
    }
    else {
        alegere = 4;
        cout << endl << "Nu sunt evenimente disponibile" << endl;
    }
}

int main()
{

    vector<Eveniment>e = evenimenteDisponibile();
     
    int alegere = 0;

    do
    {
        system("cls");
        DisplayMeniu();
        alegere = getInput();
        switch (alegere) {
        case 1:
            DisplayEvenimente(e,alegere);
            break;
        case 2:
            Optiuni(e,alegere);
            break;
        case 3:
            AdaugaEveniment(e);
            break;
        case 4:
            cout <<endl<< "Inchidere aplicatie!"<<endl;
            break;
        default:
            cout<< endl << "Nu e o optiune valabila!!!" << endl;
            return EXIT_FAILURE;
        }
    } while (alegere != 4);

    ofstream f;
    f.open("fisier.txt", ios::out | ios::trunc);
    f << e.size() << endl;
    for (int i = 0; i < e.size(); i++) {
        string data, ora;
        data = e[i].getData();
        ora = e[i].getOra();
        string buffer(e[i].getDenumire());
        f << data << endl;
        f << ora<<endl;
        f << buffer << endl;
    }
    f.close();
    return EXIT_SUCCESS;
}
