//
// Created by danio on 20.05.2023.
//

#include <iostream>
#include <utility>
#include "Haslo.h"
#include "WyborZMenu.h"
#include "StringOperations.h"
#include<ctime>

std::vector<Haslo*> Haslo::vectorHasel;
std::list<std::string> Haslo::listaKategorii;
std::list<std::string> Haslo::listaPol = {"Nazwa", "Haslo", "Kategoria", "Serwis", "Login"};
std::list<std::string> Haslo::wyborUtworzHaslo = {
        "Stworz losowe haslo.",
        "Wpisz swoje wlasne haslo."
};

Haslo::Haslo(std::string nazwa, std::string haslo, std::string kategoria, std::string serwis, std::string login):
nazwa(std::move(nazwa)),haslo(std::move(haslo)), kategoria(std::move(kategoria)), serwis(std::move(serwis)), login(std::move(login)){}

Haslo::Haslo() = default;

void Haslo::wyszukajHaslo() {
    std::cout << "Wyszukaj po: " << std::endl;
    int userInput;
    userInput = WyborZMenu::wyborOpcji(listaPol);

    std::cout << "Wyszukaj: " << std::endl;
    std::string userInputString;
    std::getline(std::cin, userInputString);

    switch(userInput){
        case 0:
            for(Haslo* h: Haslo::vectorHasel){
                if(h->getNazwa() == userInputString)
                    h->wyswietlHaslo();
            }
            break;
        case 1:
            for(Haslo* h: Haslo::vectorHasel){
                if(h->getHaslo() == userInputString)
                    h->wyswietlHaslo();
            }
            break;
        case 2:
            for(Haslo* h: Haslo::vectorHasel){
                if(h->getKategoria() == userInputString)
                    h->wyswietlHaslo();
            }
            break;
        case 3:
            for(Haslo* h: Haslo::vectorHasel){
                if(h->getSerwis() == userInputString)
                    h->wyswietlHaslo();
            }
            break;
        case 4:
            for(Haslo* h: Haslo::vectorHasel){
                if(h->getLogin() == userInputString)
                    h->wyswietlHaslo();
            }
            break;
    }
}


void Haslo::posortujHasla() {
    std::cout << "Posortuj po: " << std::endl;
    int userInput1;
    userInput1 = WyborZMenu::wyborOpcji(listaPol);
    switch (userInput1) {
        case 0:
            std::sort(vectorHasel.begin(), vectorHasel.end(), [](Haslo *haslo1, Haslo *haslo2) -> bool {
                return haslo1->getNazwa() < haslo2->getNazwa();
            });
            break;
        case 1:
            std::sort(vectorHasel.begin(), vectorHasel.end(), [](Haslo *haslo1, Haslo *haslo2) -> bool {
                return haslo1->getHaslo() < haslo2->getHaslo();
            });
            break;
        case 2:
            std::sort(vectorHasel.begin(), vectorHasel.end(), [](Haslo *haslo1, Haslo *haslo2) -> bool {
                return haslo1->getKategoria() < haslo2->getKategoria();
            });
            break;
        case 3:
            std::sort(vectorHasel.begin(), vectorHasel.end(), [](Haslo *haslo1, Haslo *haslo2) -> bool {
                return haslo1->getSerwis() < haslo2->getSerwis();
            });
            break;
        case 4:
            std::sort(vectorHasel.begin(), vectorHasel.end(), [](Haslo *haslo1, Haslo *haslo2) -> bool {
                return haslo1->getLogin() < haslo2->getLogin();
            });
            break;
    }
    Haslo::wyswietlWszystkieHasla();
}

void Haslo::wyswietlHaslo() {
    std::cout<<"{"<<std::endl;
    std::cout<<"Nazwa: " << this->getNazwa()<<std::endl;
    std::cout<<"Haslo: " << this->getHaslo()<<std::endl;
    std::cout<<"Kategoria: " << this->getKategoria()<<std::endl;
    std::cout<< "Serwis: " << this->getSerwis()<<std::endl;
    std::cout<< "Login: " <<this->getLogin()<<std::endl;
    std::cout<<"}"<<std::endl;
}

void Haslo::wyswietlWszystkieHasla() {
    if(vectorHasel.empty()) {
        std::cout<<"Brak hasel. \n" << std::endl;
    }else{
        for (Haslo *h: Haslo::vectorHasel) {
            h->wyswietlHaslo();
        }
    }
}


/*
Haslo *Haslo::funkcjaSortujaca(Haslo * haslo1, Haslo * haslo2, int wybor1, int wybor2) {
    const std::string* pole1Haslo1;
    switch(wybor1){
        case 0: pole1Haslo1 = &(haslo1->getNazwa());
            break;
        case 1: pole1Haslo1 = &(haslo1->getHaslo());
            break;
        case 2: pole1Haslo1 = &(haslo1->getKategoria());
            break;
        case 3: pole1Haslo1 = &(haslo1->getSerwis());
            break;
        case 4: pole1Haslo1 = &(haslo1->getLogin());
            break;
    }
    const std::string* pole1Haslo2;
    switch(wybor1){
        case 0: pole1Haslo2 = &(haslo2->getNazwa());
            break;
        case 1: pole1Haslo2 = &(haslo2->getHaslo());
            break;
        case 2: pole1Haslo2 = &(haslo2->getKategoria());
            break;
        case 3: pole1Haslo2 = &(haslo2->getSerwis());
            break;
        case 4: pole1Haslo2 = &(haslo2->getLogin());
            break;
    }
    const std::string* pole2Haslo1;
    switch(wybor2){
        case 0: pole2Haslo1 = &(haslo1->getNazwa());
            break;
        case 1: pole2Haslo1 = &(haslo1->getHaslo());
            break;
        case 2: pole2Haslo1 = &(haslo1->getKategoria());
            break;
        case 3: pole2Haslo1 = &(haslo1->getSerwis());
            break;
        case 4: pole2Haslo1 = &(haslo1->getLogin());
            break;
    }
    const std::string* pole2Haslo2;
    switch(wybor2){
        case 0: pole2Haslo2 = &(haslo2->getNazwa());
            break;
        case 1: pole2Haslo2 = &(haslo2->getHaslo());
            break;
        case 2: pole2Haslo2 = &(haslo2->getKategoria());
            break;
        case 3: pole2Haslo2 = &(haslo2->getSerwis());
            break;
        case 4: pole2Haslo2 = &(haslo2->getLogin());
            break;
    }

    return nullptr;
}
*/

void Haslo::dodajHaslo() {
    Haslo *noweHaslo = new Haslo();
    Haslo::vectorHasel.push_back(noweHaslo);
    std::string userInput;

    std::cout<<"Podaj nazwe hasla (np Haslo do konta Google.): "<<std::endl;
    std::getline(std::cin, userInput);
    noweHaslo->setNazwa(userInput);

    Haslo::zmienHaslo(noweHaslo);

    std::cout<<"Wybierz kategorie do ktorej chcialbys dodac:"<<std::endl;
    auto getElement = listaKategorii.begin();
    std::advance(getElement, WyborZMenu::wyborOpcji(listaKategorii));
    noweHaslo->setKategoria(*getElement);

    std::cout<<"Podaj link (wpisz n aby pominac):"<<std::endl;
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
        noweHaslo->setLogin("");
    }
    std::cout<<"Dodano nowe haslo. \n"<<std::endl;
}

bool Haslo::czyHasloIstnieje(std::string haslo) {
    for(Haslo* h: Haslo::vectorHasel){
        if(h->getHaslo() == haslo){
            return true;
        }
    }
    return false;
}

void Haslo::zmienHaslo(Haslo * haslo) {
    std::string userInput;
    int liczbaZnakow;
    bool czySaWielkieLitery;
    bool czyZawieraZnakiSpecjalne;
    std::string losoweHaslo;
    switch(WyborZMenu::wyborOpcji(Haslo::wyborUtworzHaslo)){
        case 0:
            std::cout<< "Wybierz dlugosc hasla (1 - 40): "<< std::endl;
            liczbaZnakow = WyborZMenu::wyborLiczby(1, 40);
            std::cout<< "Czy chcesz aby haslo zawieralo wielkie litery?"<< std::endl;
            czySaWielkieLitery = WyborZMenu::wyborOpcjiBoolean();
            std::cout<< "Czy chcesz aby haslo zawieralo znaki specjalne?"<< std::endl;
            czyZawieraZnakiSpecjalne = WyborZMenu::wyborOpcjiBoolean();
            do {
                do {
                    losoweHaslo = Haslo::generujLosoweHaslo(liczbaZnakow, czySaWielkieLitery, czyZawieraZnakiSpecjalne);
                }while(czyHasloIstnieje(losoweHaslo));
                std::cout << "Czy ustawic haslo " << losoweHaslo << " ? Sila hasla to: " << Haslo::sprawdzMocHasla(losoweHaslo) <<" /10." << std::endl;
            }while(!WyborZMenu::wyborOpcjiBoolean());
            haslo->setHaslo(losoweHaslo);
            break;
        case 1:
            do{
                std::cout<<"Podaj haslo ktore chcesz ustawic:"<<std::endl;
                std::getline(std::cin, userInput);
                if(czyHasloIstnieje(userInput)){
                    std::cout << "Takie haslo juz istnieje!" << std::endl;
                }
                std::cout << "Sila hasla to: " << Haslo::sprawdzMocHasla(userInput) << "/10. Czy chcesz ustawic to haslo?" << std::endl;
            }while(!WyborZMenu::wyborOpcjiBoolean());
            haslo->setHaslo(userInput);
            break;
    }
}

void Haslo::edytujHaslo() {
    if(vectorHasel.empty()) {
        std::cout<<"Brak hasel do edycji. \n" << std::endl;
        return;
    }
    std::cout<<"Wybierz haslo do edycji:"<<std::endl;
    int userInput;
    userInput = WyborZMenu::wyborOpcji(vectorHasel);
    (*(std::next(vectorHasel.begin(), userInput)))->wyswietlHaslo();

    std::cout<<"Wybierz pole do edycji:"<<std::endl;
    int userInput1;
    userInput1 = WyborZMenu::wyborOpcji(listaPol);
    std::string userInput2;
    auto getElement = listaKategorii.begin();
    switch (userInput1) {
        case 0:
            std::cout<<"Wprowadz nowa nazwe: "<<std::endl;
            std::getline(std::cin, userInput2);
            (*(std::next(vectorHasel.begin(), userInput)))->setNazwa(userInput2);
            break;
        case 1:
            Haslo::zmienHaslo(*(std::next(vectorHasel.begin(), userInput)));
            break;
        case 2:
            std::cout<<"Wybierz kategorie na jaka chcesz zmienic."<<std::endl;
            std::advance(getElement, WyborZMenu::wyborOpcji(listaKategorii));
            (*(std::next(vectorHasel.begin(), userInput)))->setKategoria(*getElement);
            break;
        case 3:
            std::cout<<"Wprowadz nowy serwis: "<<std::endl;
            std::getline(std::cin, userInput2);
            (*(std::next(vectorHasel.begin(), userInput)))->setSerwis(userInput2);
            break;
        case 4:
            std::cout<<"Wprowadz nowy login: "<<std::endl;
            std::getline(std::cin, userInput2);
            (*(std::next(vectorHasel.begin(), userInput)))->setLogin(userInput2);
            break;
    }
    std::cout<< "Haslo uaktualnione. " << std::endl;
}

void Haslo::usunHaslo() {
    if(vectorHasel.empty()) {
        std::cout<<"Brak hasel do usuniecia. \n" << std::endl;
        return;
    }
    std::cout<<"Wybierz haslo do usuniecia:"<<std::endl;
    int userInput;
    userInput = WyborZMenu::wyborOpcji(vectorHasel);
    vectorHasel.erase(std::next(vectorHasel.begin(), userInput));
    std::cout<<"Usunieto haslo."<<std::endl;
}

void Haslo::dodajKategorie() {
    std::string userInput;
    std::cout<<"Podaj nazwe kategorii: "<<std::endl;
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
    if(listaKategorii.empty()) {
        std::cout<<"Lista kategorii jest pusta. \n" << std::endl;
        return;
    }

    std::cout<< "Wybierz kategorie do usuniecia (USUNIETE ZOSTANA WSZYSTKIE HASLA Z TEJ KATEGORII!!!):"<<std::endl;
    std::list<std::string>::iterator it;
    it = listaKategorii.begin();
    std::advance(it, WyborZMenu::wyborOpcji(listaKategorii));


    std::vector<Haslo*>::iterator iteracjaPoHaslach;

    for(iteracjaPoHaslach = vectorHasel.begin(); iteracjaPoHaslach != vectorHasel.end();){
        if((*iteracjaPoHaslach)->getKategoria() == *it){
            (*(iteracjaPoHaslach))->wyswietlHaslo();
        }
        iteracjaPoHaslach++;
    }
    std::cout<<"Powyzsze hasla zostana usuniete. Czy chcesz kontynuowac? "<<std::endl;
    if(WyborZMenu::wyborOpcjiBoolean()) {
        for (iteracjaPoHaslach = vectorHasel.begin(); iteracjaPoHaslach != vectorHasel.end();) {
            bool usuniety = false;
            if ((*iteracjaPoHaslach)->getKategoria() == *it) {
                iteracjaPoHaslach = vectorHasel.erase(iteracjaPoHaslach);
                usuniety = true;
            }
            if (!usuniety) {
                iteracjaPoHaslach++;
            }
        }
        std::cout << "Usunieto kategorie o nazwie " << *it << " oraz wszystkie hasla z tej kategorii." << std::endl;
        listaKategorii.erase(it);
    }else{
        std::cout<<"Przerwano operacje. "<<std::endl;
    }

}

std::string Haslo::generujLosoweHaslo(int dlugosc, bool czySaWielkieLitery, bool czyZawieraZnakiSpecjalne) {
    std::string losoweHaslo = StringOperations::stworzStringZNSpacji(dlugosc);
    int randomNum1 = - 101;
    if(czySaWielkieLitery) {
        randomNum1 = 1 + (std::rand() % dlugosc);
        losoweHaslo[randomNum1] = (std::rand() % 25) + 65;
    }
    int randomNum2 = -100;
    if(czyZawieraZnakiSpecjalne){
        do{
            randomNum2 = 1 + (std::rand() % dlugosc);
        }while(randomNum2 == randomNum1);
        losoweHaslo[randomNum2] = 33 + (std::rand() % 14);
    }
    for(int i = 0; i< losoweHaslo.length(); i++){
        if(i != randomNum2 && i != randomNum1){

            losoweHaslo[i] = 97 + (std::rand() % 25);
            if(czySaWielkieLitery){
                if(std::rand() % 4 < 1)
                    losoweHaslo[i] = 65 + (std::rand() % 25);
            }
            if(czyZawieraZnakiSpecjalne){
                if(std::rand() % 4 < 1)
                    losoweHaslo[i] = 33 + (std::rand() % 14);
            }
            if(std::rand() % 4 < 1)
                losoweHaslo[i] = 48 + (std::rand() % 9);
        }
    }
    return losoweHaslo;
}

int Haslo::sprawdzMocHasla(const std::string& haslo) {
    int mocPoczatkowa = 10;

    if (!StringOperations::sprawdzCzyJestLiczba(haslo))
        mocPoczatkowa -= 2;
    if (!StringOperations::sprawdzCzyJestMalaLitera(haslo))
        mocPoczatkowa -= 2;
    if (!StringOperations::sprawdzCzyJestWielkaLitera(haslo))
        mocPoczatkowa -= 2;
    if (!StringOperations::sprawdzCzyJestZnakSpecjalny(haslo))
        mocPoczatkowa -= 2;
    if(haslo.length() < 5)
        mocPoczatkowa -= 4;

    return mocPoczatkowa;
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
