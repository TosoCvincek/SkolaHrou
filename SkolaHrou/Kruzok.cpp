#include "Kruzok.h"
#include "Ziak.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void Kruzok::pridajZiaka(Ziak * pridavany)
{
	trieda.push_back(pridavany);
}

Kruzok::Kruzok()
{
}

void Kruzok::nacitaj(const char * menoSuboru)
{
	string meno;
	string priezvisko;
	char pohlavie;
	int znamky[5];
	ifstream citac;
	citac.open(menoSuboru);
	string riadok;
	while (getline(citac, riadok)) {
		istringstream linestream(riadok);
		string word;
		linestream >> word;
		meno = word;
		linestream >> word;
		priezvisko = word;
		linestream >> word;
		string sPohlavie = word;
		char *pohlavieChar = new char[sPohlavie.length() + 1];
		strcpy(pohlavieChar, sPohlavie.c_str());
		pohlavie = pohlavieChar[0];
		delete[] pohlavieChar;
		for (unsigned int i = 0; i < 5; i++)
		{
			linestream >> word;
			string znamka = word;
			char *charZnamka = new char[znamka.length() + 1];
			strcpy(charZnamka, znamka.c_str());
			char ZnamkaFinal = charZnamka[0];
			znamky[i] = int(ZnamkaFinal);
			delete[] charZnamka;
		}
		Ziak* z = new Ziak();
		z->NahodZiaka(meno, priezvisko, pohlavie, znamky);
		pridajZiaka(z);
		
	}
	if (citac.is_open()) citac.close();
}

vector<Ziak*> Kruzok::upracPodlaPriemeru()
{
	vector<Ziak*> pomocny;
	vector<Ziak*> upratany;
	for (unsigned int i = 0; i < trieda.size(); i++)
	{
		pomocny.push_back(trieda[i]);
	}
	double najlepsi = 5;
	for (unsigned int i = 0; i < trieda.size(); i++)
	{
		for (unsigned int i = 0; i < pomocny.size(); i++)
		{
			if (pomocny[i]->getPriemer() < najlepsi) {
				najlepsi = pomocny[i]->getPriemer();
			}
		}
		for (unsigned int i = 0; i < pomocny.size(); i++)
		{
			if (pomocny[i]->getPriemer() == najlepsi) {
				upratany.push_back(pomocny[i]);
				pomocny.erase(pomocny.begin() + i);
			}
		}
		najlepsi = 5;
	}
	return upratany;
}


void Kruzok::zapisVysledkyDoSuboru(const char * menoSuboru)
{
	vector<Ziak*>list = upracPodlaPriemeru();
	fstream zapisovac(menoSuboru);
	for (unsigned int i = 0; i < list.size(); i++)
	{
		double priemer = list[i]->getPriemer();
		string meno = list[i]->getMeno();
		string priezvisko = list[i]->getPriezvisko();
		zapisovac << priemer << ": " << meno << " " << priezvisko << endl;
	}
	if (zapisovac.is_open()) zapisovac.close();
	vypisZeBestNaKonzolu(list);
}

void Kruzok::vypisZeBestNaKonzolu(vector<Ziak*> upratany)
{
	int uz = 0;
	for (unsigned int i = 0; i < upratany.size(); i++)
	{
		if (uz == 0) {
			if (upratany[i]->getPohlavie() == 'm') {
				double priemer = upratany[i]->getPriemer();
				string meno = upratany[i]->getMeno();
				string priezvisko = upratany[i]->getPriezvisko();
				cout << priemer << ": " << meno << " " << priezvisko << endl;
				uz++;
			}
		}
		else if (uz == 1) {
			if (upratany[i]->getPohlavie() == 'z') {
				double priemer = upratany[i]->getPriemer();
				string meno = upratany[i]->getMeno();
				string priezvisko = upratany[i]->getPriezvisko();
				cout << priemer << ": " << meno << " " << priezvisko << endl;
				uz++;
			}
		}
	}
}

Kruzok::~Kruzok()
{
	for (auto &p : trieda)
	{
		delete p;
	}
}
