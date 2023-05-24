// Created by danio on 24.05.2023.

//

#include "WyborZMenu.h"
#include <iostream>
#include <limits>

WyborZMenu::WyborZMenu() = default;

int WyborZMenu::wyborOpcji(const std::list<std::string> & listaWyborow) {
    int userInput;
    do{
        for(const std::string &opcja : listaWyborow){
            std::cout<<opcja<<std::endl;
        }
        std::cin>>userInput;
        if(userInput < 1 || userInput > 8) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Wybierz jedna z opcji."<<std::endl;
        }
    }while(userInput < 1 || userInput > listaWyborow.size());
    return userInput;
}
