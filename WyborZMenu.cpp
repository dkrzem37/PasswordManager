// Created by danio on 24.05.2023.

//

#include "WyborZMenu.h"
#include <iostream>
#include <limits>

WyborZMenu::WyborZMenu() = default;

std::list<std::string> WyborZMenu::wyborBooleanMenu{
        "Tak.",
        "Nie"
};

bool WyborZMenu::wyborOpcjiBoolean() {
    switch(wyborOpcji(WyborZMenu::wyborBooleanMenu)){
        case 0:
            return true;
        case 1:
            return false;
        default:
            return false;
    }
}

int WyborZMenu::wyborOpcji(const std::vector<Haslo*> & listaWyborow) {
    int counter = 0;
    std::string userInput;
    int userInputInt;

    for(Haslo* const& opcja : listaWyborow){
        std::cout<< "/////"<<counter<<"/////"<<std::endl;
        std::cout<<opcja->getNazwa()<<std::endl;
        std::cout<<opcja->getHaslo()<<std::endl;
        std::cout<<opcja->getKategoria()<<std::endl;
        std::cout<<opcja->getSerwis()<<std::endl;
        std::cout<<opcja->getLogin()<<std::endl;
        counter++;
    }
    do{
        std::getline(std::cin, userInput);
        try {
            userInputInt = std::stoi(userInput);
        }catch(std::invalid_argument&){
            std::cout<<"Wprowadz numer jednej z opcji."<<std::endl;
            userInputInt = -1;
            continue;
        }
        if(userInputInt < 0 || userInputInt >= listaWyborow.size() ) {
            std::cout<<"Wybierz jedna z opcji."<<std::endl;
        }
    }while(userInputInt < 0 || userInputInt >= listaWyborow.size());
    return userInputInt;
}

int WyborZMenu::wyborLiczby(int min, int max) {
    int userInputInt;
    std::string userInput;
    do{

        std::getline(std::cin, userInput);
        try {
            userInputInt = std::stoi(userInput);
        }catch(std::invalid_argument&){
            std::cout<<"Wprowadz numer."<<std::endl;
            userInputInt = -1;
            continue;
        }
        if(userInputInt <= min || userInputInt >= max ) {
            std::cout<<"Wybierz numer miedzy "<<min << " a " << max <<"."<<std::endl;
        }
    }while(userInputInt <= min || userInputInt >= max);
    return userInputInt;
}

int WyborZMenu::wyborOpcji(const std::list<std::string> & listaWyborow) {
    std::string userInput;
    int userInputInt;

    do{
        int counter = 0;

        for(const std::string& opcja : listaWyborow){
            std::cout<<counter<<". "<<opcja<<std::endl;
            counter++;
        }
        std::getline(std::cin, userInput);
        try {
            userInputInt = std::stoi(userInput);
        }catch(std::invalid_argument&){
            std::cout<<"Wprowadz numer jednej z opcji."<<std::endl;
            userInputInt = -1;
            continue;
        }
        if(userInputInt < 0 || userInputInt >= listaWyborow.size() ) {
            std::cout<<"Wybierz jedna z opcji."<<std::endl;
        }
    }while(userInputInt < 0 || userInputInt >= listaWyborow.size());
    return userInputInt;
}
