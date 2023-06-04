//
// Created by danio on 26.05.2023.
//

#ifndef PROJECTCPP_STRINGOPERATIONS_H
#define PROJECTCPP_STRINGOPERATIONS_H
#include <string>

class StringOperations {
public:
    /**
     * Funkcja tworzaca string stworzony wylacznie ze spacji o dlugosci podanej jako parametr.
     *
     * @param liczbaSpacji - dlugosc tworzonego stringa.
     * @return Zwracany jest string zlozony ze spacji.
     */
    static std::string stworzStringZNSpacji(const int& liczbaSpacji);

    /**
     * Funkcja sprawdzajaca czy w stringu znajduje sie mala litera.
     *
     * @param tekst - Tekst do sprawdzenia.
     * @return True jezeli w stringu wystepuje mala litera. False w przeciwnym wypadku.
     */
    static bool sprawdzCzyJestMalaLitera(const std::string& tekst);

    /**
     * Funkcja sprawdzajaca czy w stringu znajduje sie wielka litera.
     *
     * @param tekst - Tekst do sprawdzenia.
     * @return True jezeli w stringu wystepuje wielka litera. False w przeciwnym wypadku.
     */
    static bool sprawdzCzyJestWielkaLitera(const std::string& tekst);

    /**
     * Funkcja sprawdzajaca czy w stringu znajduje sie znak specjalny.
     *
     * @param tekst - Tekst do sprawdzenia.
     * @return True jezeli w stringu wystepuje znak specjalny. False w przeciwnym wypadku.
     */
    static bool sprawdzCzyJestZnakSpecjalny(const std::string& tekst);

    /**
     * Funkcja sprawdzajaca czy w stringu znajduje sie liczba.
     *
     * @param tekst - Tekst do sprawdzenia.
     * @return True jezeli w stringu wystepuje liczba. False w przeciwnym wypadku.
     */
    static bool sprawdzCzyJestLiczba(const std::string& tekst);
};


#endif //PROJECTCPP_STRINGOPERATIONS_H
