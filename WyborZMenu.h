//
// Created by danio on 24.05.2023.
//

#ifndef PROJECTCPP_WYBORZMENU_H
#define PROJECTCPP_WYBORZMENU_H
#include <string>
#include <list>
#include <vector>
#include "Haslo.h"


class WyborZMenu {
public:

    WyborZMenu();

    static std::list<std::string> wyborBooleanMenu;

    /**
     * Funkcja wyswietlajca Tak/Nie i wymuszajaca od uzytkownika podania odpowiedzi.
     *
     * @return True jezeli uzytkownik wpisal 0. False jezeli uzytkownik wpisal 1.
     */
    static bool wyborOpcjiBoolean();

    /**
     * Funkcja wyswietlajaca liste mozliwych wyborow dopoki uzytkownik nie wybierze jednej z nich poprzez podanie numeru opcji.
     *
     * @param listaWyborow - Lista z ktorej uzytkownik powinien wybrac jedna z opcji.
     * @return Zwraca numer wybranej przez uzytkownika opcji.
     */
    static int wyborOpcji(const std::vector<Haslo*>& listaWyborow);

    /**
     * Funkcja promptujaca uzytkownika o podanie numeru znajdujacego sie w pewnym zakresie.
     *
     *@param min - Minimalna dozwolona liczba.
     * @param max - Maksymalna dozwolona liczba.
     * @return Zwraca wybrana przez uzytkownika liczbe.
     */
    static int wyborLiczby(int min, int max);

    /**
     * Funkcja wyswietlajaca liste mozliwych wyborow dopoki uzytkownik nie wybierze jednej z nich poprzez podanie numeru opcji.
     *
     * @param listaWyborow - Lista z ktorej uzytkownik ma mozliwosc wyboru.
     * @return Zwraca numer wybranej przez uzytkownika opcji.
     */
    static int wyborOpcji(const std::list<std::string>& listaWyborow);
};


#endif //PROJECTCPP_WYBORZMENU_H
