//
// Created by danio on 23.05.2023.
//

#ifndef PROJECTCPP_SZYFR_H
#define PROJECTCPP_SZYFR_H

#include <string>

class Szyfr {

public:
    static std::string testHasla;

    /**
     * Funkcja szyfrujaca podany tekst korzystajac z podanego hasla.
     *
     * @param tekst - Tekst do zaszyfrowania.
     * @param hasloSzyfrujace - Haslo za pomoca ktorego tekst jest szyfrowany.
     * @return Zwracany jest zaszyfrowany tekst.
     */
    static std::string szyfruj(std::string tekst, const std::string & hasloSzyfrujace);

    /**
     * Funkcja sluzaca do odszyfrowania tekstu za pomoca hasla szyfrujacego.
     *
     * @param tekst - Tekst do odszyfrowania.
     * @param hasloSzyfrujace - Haslo za pomoca ktorego odszyfrowane zostanie tekst.
     * @return Zwracany jest odszyfrowany tekst.
     */
    static std::string odszyfruj(std::string tekst, std::string hasloSzyfrujace);
};


#endif //PROJECTCPP_SZYFR_H
