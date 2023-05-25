//
// Created by danio on 23.05.2023.
//

#include <iostream>
#include "Szyfr.h"

std::string Szyfr::testHasla = "asFAGWegdsvTJJJtEXC";

void Szyfr::szyfruj(std::string* tekst, const std::string & hasloSzyfrujace) {
    for(int i = 0; i< tekst->length(); i++){
        int moveBy = hasloSzyfrujace[i % hasloSzyfrujace.length()]% 26 ;
        (*tekst)[i] += moveBy;
    }
}
std::string Szyfr::szyfruj(std::string tekst, const std::string & hasloSzyfrujace) {
    for(int i = 0; i< tekst.length(); i++){
        int moveBy = hasloSzyfrujace[i % hasloSzyfrujace.length()]% 26 ;
        (tekst)[i] += moveBy;
    }
    return tekst;
}
std::string Szyfr::odszyfruj(std::string tekst, std::string hasloSzyfrujace) {
    for(int i = 0; i< tekst.length(); i++){
        int moveBy = hasloSzyfrujace[i % hasloSzyfrujace.length()]% 26 ;
        (tekst)[i] -= moveBy;
    }
    return tekst;
}

void Szyfr::odszyfruj(std::string* tekst, const std::string & hasloSzyfrujace) {
    for(int i = 0; i< tekst->length(); i++) {
        int moveBy = hasloSzyfrujace[i % hasloSzyfrujace.length()] % 26;
        (*tekst)[i] -= moveBy;
    }
}
