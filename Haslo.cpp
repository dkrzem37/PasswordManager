//
// Created by danio on 20.05.2023.
//

#include <iostream>
#include <utility>
#include "Haslo.h"
#include "WyborZMenu.h"
std::vector<Haslo*> Haslo::vectorHasel;
std::list<std::string> Haslo::listaKategorii;

Haslo::Haslo(std::string nazwa, std::string haslo, std::string kategoria, std::string serwis, std::string login):
nazwa(std::move(nazwa)),haslo(std::move(haslo)), kategoria(std::move(kategoria)), serwis(std::move(serwis)), login(std::move(login)){}

Haslo::Haslo() = default;

void Haslo::wyszukajHaslo() {

}


std::list<Haslo> Haslo::posortujHasla() {
    return std::list<Haslo>();
}

void Haslo::dodajHaslo() {
    Haslo *noweHaslo = new Haslo();
    Haslo::vectorHasel.push_back(noweHaslo);
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
    auto getElement = listaKategorii.begin();
    std::advance(getElement, WyborZMenu::wyborOpcji(listaKategorii));
    noweHaslo->setKategoria(*getElement);

    std::cout<<"Podaj link (wpisz n aby pominac):"<<std::endl;
    std::cin.ignore();
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

void Haslo::dodajKategorie() {
    std::string userInput;
    std::cout<<"Podaj nazwe kategorii: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, userInput);
    bool istniejeKategoria = false;
    for (const std::string &el: Haslo::listaKategorii) {
        if (userInput == el) {
            istniejeKategoria = true;
        }
    }
    if (!istniejeKategoria) {
        Haslo::listaKategorii.push_back(userInput);
        std::cout<<"Utworzono nowa kategorie o nazwie "<< userInput <<"." << std::endl;
    }else{
        std::cout<<"Taka kategoria juz istnieje. "<<std::endl;
    }
}

void Haslo::usunKategorie() {
    std::cout<< "Wybierz kategorie do usuniecia:"<<std::endl;
    std::list<std::string>::iterator it;
    it = listaKategorii.begin();
    std::advance(it, WyborZMenu::wyborOpcji(listaKategorii));

    std::vector<Haslo*>::iterator iteracjaPoHaslach;
    for(iteracjaPoHaslach = vectorHasel.begin(); iteracjaPoHaslach != vectorHasel.end();){
        bool usuniety = false;
        if((*iteracjaPoHaslach)->getKategoria() == *it){
            iteracjaPoHaslach = vectorHasel.erase(iteracjaPoHaslach);
            usuniety = true;
        }
        if (!usuniety) {
            iteracjaPoHaslach++;
        }
    }


    std::cout<<"Usunieto kategorie o nazwie " <<  *it<<" oraz wszystkie hasla z tej kategorii."<<std::endl;
    listaKategorii.erase(it);

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
