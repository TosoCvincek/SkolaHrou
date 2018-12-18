#pragma once
#include <string>

using namespace std;
class Ziak
{
private: 
	string meno;
	string priezvisko;
	char pohlavie;
	int znamky [5];
	double priemer = 0;
	void setPriemer();
public:
	Ziak();
	void NahodZiaka(string pMeno, string pPriezvisko, char pPohlavie, int pZnamky [5]) {
		meno = pMeno;
		priezvisko = pPriezvisko;
		pohlavie = pPohlavie;
		for (unsigned int i = 0; i < 6; i++)
		{
			znamky[i] = pZnamky[i];
		}
		setPriemer();
	};
	string getMeno() { return meno; };
	string getPriezvisko() { return priezvisko; };
	char getPohlavie() { return pohlavie; };
	int* getZnamky() { return znamky; };
	double getPriemer() { return priemer; };
	~Ziak();
};

