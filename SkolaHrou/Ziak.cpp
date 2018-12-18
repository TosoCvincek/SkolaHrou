#include "Ziak.h"



void Ziak::setPriemer()
{
	for (unsigned int i = 0; i < 5; i++)
	{
		priemer = priemer + (znamky[i] - 64);
	}
	priemer = priemer / 5;
}

Ziak::Ziak()
{
}


Ziak::~Ziak()
{
}
