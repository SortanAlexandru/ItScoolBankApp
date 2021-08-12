#include <iostream>
#include "bank.h"



int main()
{
    // crearea unui ID si parole pt a ne putea loga pe "aplicatie"
    const std::string ID{ "admin" };
    std::string id;
    std::cout << "Introduceti ID-ul\n";
    std::cin >> id;
    const std::string PASS{ "admin" };
    std::string pass;
    std::cout << "Introduceti parola\n";
    std::cin >> pass;
    for (int i = 0; i < 3; i++)
    {
        int incercari = (2 - i);
        if (id == ID && PASS == pass)
        {
            // instantam o banca 
            Bank* itSchoolBank = new Bank();
            bool isRunning = true;
            do
            {
                system("CLS");
                std::cout << " *************Meniu Principal****************" << std::endl << std::endl;
                std::cout << "Alegeti optiunea dorita: " << std::endl;

                std::cout << " 1 -> Adaugare Cont\n";
                std::cout << " 2 -> Vizualizare Conturi\n";
                std::cout << " 3 -> Modificare Conturi\n";
                std::cout << " 9 -> Exit\n";
                std::cout << " Introduceti optiunea:  \n";
                char optiune;
                std::cin >> optiune;
                switch (optiune)
                {
                case '1':
                    system("CLS");   // Pentru clear screen
                    itSchoolBank->adaugareCont();
                    break;
                case '2':
                    system("CLS");
                    itSchoolBank->vizualizareConturi();
                    break;
                case '3':
                    system("CLS");
                    itSchoolBank->modificareCont();
                    break;
                case '9':
                    system("CLS");
                    isRunning = false;
                    std::cout << "La revedere!\n";
                    break;
                default:
                    system("CLS");
                    std::cout << " Optiunea nu este valida\n";
                    break;
                }
            } while (isRunning);

            // stergem banca
            delete itSchoolBank;
            // break;











        }
        else
        {
            system("CLS");
            std::cout << "Ati gresit ID sau parola!\n";

            if (incercari > 0)
            {
                std::cout << "Mai aveti " << incercari << " incercari\n";
                std::cout << "ID: ";
                std::cin >> id;
                std::cout << "Parola: ";
                std::cin >> pass;
            }
            else if (incercari == 0)
                std::cout << "Nu mai aveti incercari!\n";
        }
    }
}