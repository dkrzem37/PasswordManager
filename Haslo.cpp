//
// Created by danio on 20.05.2023.
//

#include <iostream>
#include "Haslo.h"
std::list<Haslo*> Haslo::listaHasel;

Haslo::Haslo(std::string nazwa, std::string haslo, std::string kategoria, std::string serwis, std::string login):
nazwa(nazwa),haslo(haslo), kategoria(kategoria), serwis(serwis), login(login){}

Haslo::Haslo() = default;

void Haslo::wyszukajHaslo() {

}


std::list<Haslo> Haslo::posortujHasla() {
    return std::list<Haslo>();
}

void Haslo::dodajHaslo() {
    Haslo *noweHaslo = new Haslo();
    Haslo::listaHasel.push_back(noweHaslo);
    std::string userInput;

    std::cout<<"Podaj nazwe hasla (np Haslo do konta Google.): "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, userInput);
    noweHaslo->setNazwa(userInput);

    std::cout<<"Podaj haslo ktore chcesz ustawic:"<<std::endl;
    //todo: sprawdz czy haslo jest zgodne z wymaganiami
    std::getline(std::cin, userInput);
    noweHaslo->setHaslo(userInput);

    std::cout<<"Wybierz kategorie do ktorej chcialbys dodac:"<<std::endl;
    std::getline(std::cin, userInput);
    noweHaslo->setKategoria(userInput);

    std::cout<<"Podaj link (wpisz n aby pominac):"<<std::endl;
    //todo: what if i choose not to, how do i write just a space? Do i need to?
    std::getline(std::cin, userInput);
    if(userInput != "n") {
        noweHaslo->setSerwis(userInput);
    }else{
        noweHaslo->setSerwis("");
    }

    std::cout<<"Podaj swoj login do serwisu (wpisz n aby pominac):"<<std::endl;
    std::getline(std::cin, userInput);
    if(userInput != "n") {
        noweHaslo->setLogin(userInput);
    }else {
        noweHaslo->setSerwis("");
    }
}

void Haslo::edytujHaslo() {

}

void Haslo::usunHaslo() {

}

void Haslo::edytujKategorie() {

}

void Haslo::usunKategorie() {

}

const std::string &Haslo::getNazwa() const {
    return nazwa;
}

void Haslo::setNazwa(const std::string &nazwa) {
    Haslo::nazwa = nazwa;
}

const std::string &Haslo::getHaslo() const {
    return haslo;
}

void Haslo::setHaslo(const std::string &haslo) {
    Haslo::haslo = haslo;
}

const std::string &Haslo::getKategoria() const {
    return kategoria;
}

void Haslo::setKategoria(const std::string &kategoria) {
    Haslo::kategoria = kategoria;
}

const std::string &Haslo::getSerwis() const {
    return serwis;
}

void Haslo::setSerwis(const std::string &serwis) {
    Haslo::serwis = serwis;
}

const std::string &Haslo::getLogin() const {
    return login;
}

void Haslo::setLogin(const std::string &login) {
    Haslo::login = login;
}
