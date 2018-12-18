#define _CRTDBG_MAP_ALLOC
#include "Kruzok.h"
#include <vector>
#include <iostream>
#include <crtdbg.h>

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Kruzok *k = new Kruzok();
	k->nacitaj("input.txt");
	k->zapisVysledkyDoSuboru("output.txt");
	delete k;
	return 0;
	}