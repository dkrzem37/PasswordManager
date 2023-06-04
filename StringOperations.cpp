//
// Created by danio on 26.05.2023.
//
#include <string>
#include "StringOperations.h"

std::string StringOperations::stworzStringZNSpacji(const int & liczSpacji) {
    std::string naszString;
    for(int i = 0; i< liczSpacji; i++){
        naszString.append(" ");
    }
    return naszString;
}

bool StringOperations::sprawdzCzyJestMalaLitera(const std::string& tekst) {
    bool jest = false;
    for(char h : tekst){
        if(islower(h))
            jest = true;
    }
    return jest;
}

bool StringOperations::sprawdzCzyJestWielkaLitera(const std::string& tekst) {
    bool jest = false;
    for(char h : tekst){
        if(isupper(h))
            jest = true;
    }
    return jest;
}

bool StringOperations::sprawdzCzyJestZnakSpecjalny(const std::string& tekst) {
    bool jest = false;
    for(char h : tekst) {
        if ((h>=33 && h<=47) || (h>=58 && h<=64) || (h>=91 && h<=96) || (h>=123 && h<=126)){
            jest = true;
        }
    }
    return jest;
}

bool StringOperations::sprawdzCzyJestLiczba(const std::string& tekst) {
    bool jest = false;
    for(char h : tekst) {
        if ((h>=48 && h<=57)){
            jest = true;
        }
    }
    return jest;
}
