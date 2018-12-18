#pragma once
#include "Ziak.h"
#include <string>
#include <vector>

using namespace std;

class Kruzok
{
private:
	vector<Ziak*> trieda;
	/*Ziak* trieda = nullptr;
	unsigned int pocet = 0;*/
	void pridajZiaka(Ziak *pridavany);
public:
	Kruzok();
	void nacitaj(const char* menoSuboru);
	vector<Ziak*> upracPodlaPriemeru();
	void zapisVysledkyDoSuboru(const char* menoSuboru);
	void vypisZeBestNaKonzolu(vector<Ziak*> upratany);
	~Kruzok();
};

