#include <iostream>
#include "Haslo.h"
#include "Szyfr.h"
#include "WyborZMenu.h"
#include <limits>
#include <string>
#include <fstream>
#include <filesystem>
#include "FileOperations.h"
#include "StringOperations.h"
#include<ctime>


int main() {
    int userInput = 0;
    std::string sciezkaPliku;
    std::string hasloDoPliku;
    std::string dataProbyDostepu;
    int godzinaProbyDostepu;
    int minutaProbyDostepu;
    int sekundaProbyDostepu;

    srand(time(NULL));

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
        "Wyswietl date proby dostepu do pliku.",
        "Zapisz zmiany i zamknij program."
    };
    std::list<std::string> menuWyboruPliku{
            "Wybierz plik do otwarcia.",
            "Wprowadz pelna sciezke pliku."
    };
    std::list<std::string> menuWyboruPlikowZProgramu{
            "PlikZHaslami.txt",
            "PlikZHaslami1.txt"
    };
    switch(WyborZMenu::wyborOpcji(menuWyboruPliku)) {
        case 0:
            switch(WyborZMenu::wyborOpcji(menuWyboruPlikowZProgramu)) {
                case 0:
                    sciezkaPliku = "PlikZHaslami.txt";
                    break;
                case 1:
                    sciezkaPliku = "PlikZHaslami1.txt";
                    break;
            }
            break;
        case 1:
            std::cout<<"Wprowadz sciezke pliku ponizej: "<< std::endl;
            std::cin>>sciezkaPliku;
            break;
    }

    std::cout<<"Podaj haslo do pliku: "<<std::endl;
    //HASLO: hweg2h38!&wdf.DA3Hhh^5

    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    do{
        std::cin>>hasloDoPliku;

        std::vector vectorZPliku = FileOperations::pobierzPlikDoVectora(sciezkaPliku);
        std::ofstream plikZHaslamiZapis;
        plikZHaslamiZapis.open(sciezkaPliku, std::ofstream::out | std::ofstream::trunc);
        if(plikZHaslamiZapis.is_open()){
            plikZHaslamiZapis<< StringOperations::stworzStringZNSpacji(ltm->tm_hour) << "\n";
            plikZHaslamiZapis<< StringOperations::stworzStringZNSpacji(ltm->tm_min) << "\n";
            plikZHaslamiZapis<< StringOperations::stworzStringZNSpacji(ltm->tm_sec) << "\n";
            for(const std::string& s : vectorZPliku){
                plikZHaslamiZapis << s << "\n";
            }
        }
        if(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC" ){
            std::cout<<"Zle haslo."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(Szyfr::odszyfruj(Szyfr::testHasla , hasloDoPliku)!="ad/(/WLc]gg>26:g,DC");
    std::cin.ignore();

    std::ifstream plikZHaslami(sciezkaPliku);
    if(plikZHaslami.is_open()){
        std::string tekst;
        int counter = 0;
        Haslo *haslo;

        for (int i = 0; i < 3; i++) {
            std::getline(plikZHaslami, tekst);

            /*if (i == 0 || i == 1) {
                dataProbyDostepu.append(std::to_string(tekst.length()));
                dataProbyDostepu.append(":");
            } else {
                dataProbyDostepu.append(std::to_string(tekst.length()));
            }*/
            switch (i) {
                case 0:
                    dataProbyDostepu.append(std::to_string(tekst.length()));
                    dataProbyDostepu.append(":");
                    godzinaProbyDostepu = tekst.length();
                    break;
                case 1:
                    dataProbyDostepu.append(std::to_string(tekst.length()));
                    dataProbyDostepu.append(":");
                    minutaProbyDostepu = tekst.length();
                    break;
                case 2:
                    dataProbyDostepu.append(std::to_string(tekst.length()));
                    sekundaProbyDostepu = tekst.length();
                    break;
            }
        }
        while(std::getline(plikZHaslami, tekst)){
            if(tekst == "{" || tekst == "}") {
                counter = 0;
                continue;
            }
            if(tekst == "/<") {
                std::getline(plikZHaslami, tekst);
                while(tekst != ">/"){

                    Haslo::listaKategorii.push_back(Szyfr::odszyfruj(tekst, hasloDoPliku));
                    std::getline(plikZHaslami, tekst);
                }
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
        std::cout<<"Niepoprawny plik."<<std::endl;
        std::exit(1);
    }
    plikZHaslami.close();
    while(true) {
        switch (WyborZMenu::wyborOpcji(menuGlowne)) {
            case 0: Haslo::wyszukajHaslo();
                break;
            case 1: Haslo::posortujHasla();
                break;
            case 2: Haslo::dodajHaslo();
                break;
            case 3: Haslo::edytujHaslo();
                break;
            case 4: Haslo::usunHaslo();
                break;
            case 5: Haslo::dodajKategorie();
                break;
            case 6: Haslo::usunKategorie();
                break;
            case 7: Haslo::wyswietlWszystkieHasla();
                break;
            case 8:
                if(Haslo::listaKategorii.empty()){
                    std::cout<<"Lista kategorii pusta. \n"<<std::endl;
                }else {
                    for (const std::string &kategoria: Haslo::listaKategorii) {
                        std::cout << kategoria << std::endl;
                    }
                }
                break;
            case 9:
                std::cout<<dataProbyDostepu<<std::endl;
                break;
            case 10:
                std::ofstream plikZHaslamiZapis;
                plikZHaslamiZapis.open(sciezkaPliku, std::ofstream::out | std::ofstream::trunc);
                if (plikZHaslamiZapis.is_open()) {
                    //Zapisywanie daty dostepu
                    plikZHaslamiZapis << StringOperations::stworzStringZNSpacji(godzinaProbyDostepu)<< "\n";
                    plikZHaslamiZapis << StringOperations::stworzStringZNSpacji(minutaProbyDostepu)<< "\n";
                    plikZHaslamiZapis << StringOperations::stworzStringZNSpacji(sekundaProbyDostepu)<< "\n";
                    //Zapisywanie hasel do pliku
                    for (Haslo *h: Haslo::vectorHasel) {
                        plikZHaslamiZapis << "{" << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getNazwa(), hasloDoPliku) << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getHaslo(), hasloDoPliku) << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getKategoria(), hasloDoPliku) << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getSerwis(), hasloDoPliku) << "\n";
                        plikZHaslamiZapis << Szyfr::szyfruj(h->getLogin(), hasloDoPliku) << "\n";
                        plikZHaslamiZapis << "}" << "\n";
                    }
                    //Zapisywanie kategorii
                    plikZHaslamiZapis << "/<" << "\n";
                    for(const std::string& kategoria : Haslo::listaKategorii){
                        plikZHaslamiZapis << Szyfr::szyfruj(kategoria, hasloDoPliku) << "\n";
                    }
                    plikZHaslamiZapis << ">/";
                }
                plikZHaslamiZapis.close();
                std::exit(0);
                break;
        }
    }
}
