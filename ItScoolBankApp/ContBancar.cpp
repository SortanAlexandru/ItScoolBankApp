#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string IBAN)
{
	this->nume = nume;    // e un pointer (aratator)  ce arata spre propria clasa
	this->prenume = prenume;
	this->IBAN = IBAN;
	
	sold = 0;
	eTipCont = TIP_CONT::CONT_RON;
}

ContBancar::~ContBancar()
{

}
