#include "Bank.h"
#include <stdio.h>


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
	// Verificare daca numele/prenumele introdus contine doar caractere alfabetice si "-"
	for (int i = 0; i <= nume.length(); i++)
	{
		system("CLS");
		if ((nume[i] >= 65 && nume[i] <= 90) || (nume[i] >= 97 && nume[i] <= 122) || (nume[i] == 95))
		{
				if ((prenume[i] >= 65 && prenume[i] <= 90) || (prenume[i] >= 97 && prenume[i] <= 122) || (prenume[i] == 95))
				{
					std::cout << "S-a creat contul!" << std::endl;
					break;
				}
				else
				{
					std::cout << " Prenumele introdus nu este corect" << std::endl;
					break;
				}
			
		}
		else {
			std::cout << "Numele introdus nu este corect" << std::endl;
			break;
		}
	}
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
	std::cout << "Numarul de conturi din banca este: " << m_ConturiBancare.size() << std::endl << std::endl;     // size = ne da dimensiunea ce se afla in contul nostru bancar  / cate elemente se afla acolo 
	for (int i =0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << ": " << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << std::endl << std::endl;
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
		// Tema 
		std::cout << "Ce modificari doriti sa realizati?\n";
		std::cout << "1 -> Modificati numele\n";
		std::cout << "2 -> Modificati prenumele\n";
		std::cout << "3 -> Stergeti contul\n";
		std::cout << "4 -> Reveniti la meniul principal\n";
		std::string numeNou;
		std::string schimbare;
		char optiuneModif;
		std::cin >> optiuneModif;
		switch (optiuneModif)
		{
		case '1':
			std::cout << "Introduceti numele vechi:\n";
			std::cin >> nume;
			std::cout << "Introduceti noul nume:\n";
			std::cin >> numeNou;
		  
			break;
		case '2':
			break;
		case '3':
			// pentru a sterge contul 
			m_ConturiBancare.erase(it);
			break;
		default:
			break;
		}
		  
		
	} 
	
}



