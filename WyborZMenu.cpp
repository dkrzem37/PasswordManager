// Created by danio on 24.05.2023.

//

#include "WyborZMenu.h"
#include <iostream>
#include <limits>

WyborZMenu::WyborZMenu() = default;

int WyborZMenu::wyborOpcji(const std::list<std::string> & listaWyborow) {
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
}
