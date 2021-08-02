#pragma once
#include <string>
enum class TIP_CONT
{
	CONT_RON = 1, 
	CONT_EURO, 
	CONT_USD
};

class ContBancar
{
private:
	std::string nume;
	std::string prenume;
	int sold;
	TIP_CONT eTipCont;  // e = ca sa ne dam seama ca e vorba despre o enumerare 
	std::string IBAN;
public:
	ContBancar(std::string nume, std::string prenume, std::string IBAN);
	~ContBancar();
};

