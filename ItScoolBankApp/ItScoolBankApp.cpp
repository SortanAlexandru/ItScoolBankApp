#include <iostream>
#include "bank.h"



int main()
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
        std::cout << " 9-> Exit\n";
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
            std::cout << "La revedere!\n";
            isRunning = false;
            break;
        default:
            system("CLS");
            std::cout << " Optiunea nu este valida\n";
            break;
        }
    } while ( isRunning);


    

   








    

    // stergem banca
    delete itSchoolBank;

}


