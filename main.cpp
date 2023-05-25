#include <iostream>
#include "Haslo.h"
#include "Szyfr.h"
#include "WyborZMenu.h"
#include <limits>
#include <string>
#include <fstream>
#include <filesystem>


int main() {
    int userInput = 0;
    std::string sciezkaPliku;
    std::string hasloDoPliku;

    std::list<std::string> menuGlowne{
        "Wyszukaj haslo.",
        "Posortuj hasla.",
        "Dodaj haslo.",
        "Edytuj haslo.",
        "Usun haslo.",
        "Dodaj kategorie.",
        "Usun kategorie." ,
        "Wyswietl wszystkie hasla.",
        "Wyswietl wszystkie kategorie.",
        "Zapisz zmiany i zamknij program."
    };
do {
        std::cout << "1. Wybierz plik do otwarcia." << std::endl;
        std::cout << "2. Wprowadz pelna sciezke pliku." << std::endl;
        std::cin>>userInput;
        if(userInput != 1 && userInput != 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Wybierz jedna z opcji."<<std::endl;
        }
    }while(userInput != 1 && userInput != 2);

    if(userInput == 1){
        userInput = 0;
        do {
            std::cout<<"1. PlikZHaslami.txt"<<std::endl;
            std::cin>>userInput;
            if(userInput != 1) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Wybierz jedna z opcji."<<std::endl;
            }
        }while(userInput != 1);
        sciezkaPliku = "PlikZHaslami.txt";
    }else if(userInput == 2){
        std::cout<<"Wprowadz sciezke pliku ponizej: "<< std::endl;
        std::cin>>sciezkaPliku;
    }

    std::cout<<"Podaj haslo do pliku: "<<std::endl;
    //HASLO: hweg2h38!&wdf.DA3Hhh^5
    do{
        std::cin>>hasloDoPliku;
        if(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC" ){
            std::cout<<"Zle haslo."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC");

    std::ifstream plikZHaslami(sciezkaPliku);
    if(plikZHaslami.is_open()){
        std::string tekst;
        int counter = 0;
        Haslo *haslo;
        //todo: pobierz hasla z pliku pomijajac godzine
        while(std::getline(plikZHaslami, tekst)){
            if(tekst == "{" || tekst == "}") {
                counter = 0;
                continue;
            }
            switch (counter) {
                case 0:
                    haslo = new Haslo();
                    Haslo::vectorHasel.push_back(haslo);
                    haslo->setNazwa(Szyfr::odszyfruj(tekst, hasloDoPliku));
                    break;
                case 1:
                    haslo->setHaslo(Szyfr::odszyfruj(tekst, hasloDoPliku));
                    break;
                case 2: {
                    std::string kategoria = Szyfr::odszyfruj(tekst, hasloDoPliku);
                    haslo->setKategoria(kategoria);
                    bool istniejeKategoria = false;
                    for (const std::string &el: Haslo::listaKategorii) {
                        if (kategoria == el) {
                            istniejeKategoria = true;
                        }
                    }
                    if (!istniejeKategoria) {
                        Haslo::listaKategorii.push_back(kategoria);
                    }
                    break;
                }
                case 3:
                    haslo->setSerwis(Szyfr::odszyfruj(tekst, hasloDoPliku));
                    break;
                case 4:
                    haslo->setLogin(Szyfr::odszyfruj(tekst, hasloDoPliku));
                    break;
            }
            counter++;
        }
    }else{
        std::cout<<"nie otwarto pliku"<<std::endl;
        std::exit(1);
    }
    plikZHaslami.close();
    while(true) {
        switch (WyborZMenu::wyborOpcji(menuGlowne)) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                Haslo::dodajHaslo();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                Haslo::dodajKategorie();
                break;
            case 6:
                break;
            case 7:
                for (Haslo *h: Haslo::vectorHasel) {
                    std::cout << "{" << std::endl;
                    std::cout << h->getNazwa() << std::endl;
                    std::cout << h->getHaslo() << std::endl;
                    std::cout << h->getKategoria() << std::endl;
                    std::cout << h->getSerwis() << std::endl;
                    std::cout << h->getLogin() << std::endl;
                    std::cout << "}" << std::endl;
                }
                break;
            case 8:
                for(const std::string& kategoria : Haslo::listaKategorii){
                    std::cout<<kategoria<<std::endl;
                }
                break;
            case 9:
                std::ofstream plikZHaslamiZapis;
                plikZHaslamiZapis.open(sciezkaPliku, std::ofstream::out | std::ofstream::trunc);
                if (plikZHaslamiZapis.is_open()) {
                    for (Haslo *h: Haslo::vectorHasel) {
                        plikZHaslamiZapis << "{";
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getNazwa(), hasloDoPliku);
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getHaslo(), hasloDoPliku);
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getKategoria(), hasloDoPliku);
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getSerwis(), hasloDoPliku);
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getLogin(), hasloDoPliku);
                        plikZHaslamiZapis << "\n";
                        plikZHaslamiZapis << "}";
                        plikZHaslamiZapis << "\n";
                    }
                }
                plikZHaslamiZapis.close();
                std::exit(0);
                break;
        }
    }
}
