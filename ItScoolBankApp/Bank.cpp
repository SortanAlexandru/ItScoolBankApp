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
	system("CLS");
	std::cout << " Numarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;       // size = ne da dimensiunea ce se afla in contul nostru bancar  / cate elemente se afla acolo 
	for (int i =0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume() << std::endl;
	}
	std::cout << " 1 -> Pentru crearea unui nou cont\n";
	std::cout << " 2 -> Pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		system("CLS");
		adaugareCont();
		break;
	default:
		system("CLS");
		break;
	}
}

void Bank::modificareCont()
{
	system("CLS");
	//intrebam operatorul care cont doreste sa il modifice
	std::cout << "Introduceti numele si prenumele contului\n";
	std::cout << "Introduceti numele de familie\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele\n";
	std::string prenume;
	std::cin >> prenume;
	// cream un pointer temporar 
	ContBancar* temp = nullptr;   // pointerul poate fi egalat cu 0, null, nullptr. Sunt ok toate cele 3 optiuni.
	// cautam contul 
	int foundIndex = 0;
	/*for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
		{
			temp = m_ConturiBancare[i];
			foundIndex = i;
			break;
		}
	}*/
	std::vector<ContBancar*>::iterator it;
	for  (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			break;
		}
	}
	// in cazul in care nu avem un cont gasit 
	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1 -> Cautati un alt cont\n";
		std::cout << "2 -> Creati un cont\n";
		std::cout << "3 -> Reveniti la meniu principal\n";
		char optiune;
		std::cin >> optiune; 
		switch (optiune)
		{
		case '1':
			modificareCont();
			break;
		case '2':
			adaugareCont();
			break;
		default:
			break;
		}
	 }
	else
	{
		std::cout << " Ce modificari doriti sa realizati?\n";
		std::cout << "1 -> Stergere cont\n";
		// pentru a sterge contul 
		m_ConturiBancare.erase(it);  
		// Tema 
		// 1 - modificati nume
		// 2 - modificati prenume
		// 3 - modificati .....
		// 4 - stergeti contul gasit 
	}
	
}
