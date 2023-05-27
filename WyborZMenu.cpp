// Created by danio on 24.05.2023.

//

#include "WyborZMenu.h"
#include <iostream>
#include <limits>

WyborZMenu::WyborZMenu() = default;

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

int WyborZMenu::wyborOpcji(const std::list<std::string> & listaWyborow) {
    std::string userInput;
    int userInputInt;
    //std::cin.ignore();

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

/*int WyborZMenu::wyborOpcji(const std::list<std::string> & listaWyborow) {
    int counter = 0;
    int userInput;
    do{
        for(const std::string &opcja : listaWyborow){
            std::cout<<counter<<". "<<opcja<<std::endl;
            counter++;
        }
        std::cin>>userInput;
        if(userInput < 0 || userInput >= listaWyborow.size() ) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Wybierz jedna z opcji."<<std::endl;
        }
    }while(userInput < 0 || userInput >= listaWyborow.size());
    return userInput;
}*/
