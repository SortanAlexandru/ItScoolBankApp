#include "Bank.h"

std::string Bank::createIBAN()
{ 
	// trebuie extins ca sa fie un iban unic
	std::string IBAN = "123";
	return IBAN;
}

Bank::Bank()
{
}

Bank::~Bank()
{
	m_ConturiBancare.clear();    // daca banca noastra este distrusa, si conturile vor fi distruse

}

void Bank::adaugareCont()
{
	system("CLS");
	std::cout << " Introduceti numele utilizatorului: " << std::endl;
	std::string nume;
	std::cin >> nume;
	std::cout << " Introduceti prenumele utilizatorului: " << std::endl;
	std::string prenume;
	std::cin >> prenume;
	std::string IBAN = createIBAN();
	ContBancar* cont = new ContBancar(nume, prenume, IBAN);
	m_ConturiBancare.push_back(cont);
	std::cout << " 1-> Pentru crearea unui cont\n";
	std::cout << " 2-> Pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		adaugareCont();
		break;
	default:
		break;
	}
}

void Bank::vizualizareConturi()
{
	std::cout << " Nuarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;       // size = ne da dimensiunea ce se afla in contul nostru bancar  / cate elemente se afla acolo 
	for (int i =0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i +1<< " " << m_ConturiBancare[i]->getNume();
	}


}
