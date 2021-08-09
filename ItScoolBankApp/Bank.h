#pragma once  // directiva de preprocesare => ne ajuta sa nu avem duplicari de headere in solutia noastra
#include "ContBancar.h"
#include <vector>
#include <iostream>

class Bank
{
	std::vector <ContBancar*> m_ConturiBancare;
	std::string createIBAN();

public:
	Bank();
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();

};

