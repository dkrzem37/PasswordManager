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
    std::cout << std::filesystem::current_path() << std::endl;
    std::list<std::string> menuGlowne{
        "1. Wyszukaj haslo.",
        "2. Posortuj hasla.",
        "3. Dodaj haslo.",
        "4. Edytuj haslo.",
        "5. Usun haslo.",
        "6. Dodaj kategorie.",
        "7. Usun kategorie." ,
        "8. Zapisz zmiany i zamknij program."};
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

    /*std::cout<<"Podaj haslo do pliku: "<<std::endl;
    //HASLO: hweg2h38!&wdf.DA3Hhh^5
    do{
        std::cin>>hasloDoPliku;
        std::cout<<hasloDoPliku<<std::endl;
        if(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC" ){
            std::cout<<"Zle haslo."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC");*/

    std::ifstream plikZHaslami(sciezkaPliku);
    if(plikZHaslami.is_open()){
        std::string tekst;
        int counter = 0;
        Haslo *haslo;
        //todo: odszyfruj i pobierz hasla z pliku pomijajac godzine
        while(std::getline(plikZHaslami, tekst)){
            if(tekst == "{" || tekst == "}") {
                std::cout<<"klamra"<<std::endl;
                counter = 0;
                continue;
            }
            switch (counter) {
                case 0:
                    haslo = new Haslo();
                    Haslo::listaHasel.push_back(haslo);
                    haslo->setNazwa(tekst);
                    std::cout<<tekst<<std::endl;
                    std::cout<<haslo->getNazwa()<<std::endl;
                    break;
                case 1:
                    haslo->setHaslo(tekst);
                    break;
                case 2:
                    haslo->setKategoria(tekst);
                    break;
                case 3:
                    haslo->setSerwis(tekst);
                    break;
                case 4:
                    haslo->setLogin(tekst);
                    break;
            }
            counter++;
        }
    }else{
        std::cout<<"nie otwarto pliku"<<std::endl;
        std::exit(1);
    }
    plikZHaslami.close();
    switch (WyborZMenu::wyborOpcji(menuGlowne)) {
        case 1:
            std::cout<<"PAROWKI";
            break;
        case 2:
            break;
        case 3:
            Haslo::dodajHaslo();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
    }
    for( Haslo* h : Haslo::listaHasel){
        std::cout<<"{"<<std::endl;
        std::cout<<h->getNazwa()<<std::endl;
        std::cout<<h->getHaslo()<<std::endl;
        std::cout<<h->getKategoria()<<std::endl;
        std::cout<<h->getSerwis()<<std::endl;
        std::cout<<h->getLogin()<<std::endl;
        std::cout<<"}"<<std::endl;
    }
    return 0;
}
