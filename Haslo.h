//
// Created by danio on 20.05.2023.
//
#include <string>
#include <list>
#include <vector>

#ifndef PROJECTCPP_HASLO_H
#define PROJECTCPP_HASLO_H

class Haslo {
    std::string nazwa, haslo, kategoria, serwis, login;
    /**
     * Funkcja pozwalajaca na wyswietlenie wszystkich pol pojedynczego hasla.
     */
    void wyswietlHaslo();
public:
    static std::list<std::string> wyborUtworzHaslo;
    static std::vector<Haslo*> vectorHasel;
    static std::list<std::string> listaKategorii;
    static std::list<std::string> listaPol;


    Haslo();
    Haslo(std::string nazwa, std::string haslo, std::string kategoria, std::string serwis, std::string login);

    /**
     * Funkcja sluzaca do wyszukania hasla zawierajacego konkretne parametry.
     *
     * Uzytkownik ma mozliwosc wybrania po ktorym polu hasla {"Nazwa", "Haslo", "Kategoria", "Serwis", "Login"} wyszukiwac.
     * Funkcja zwraca wszystkie hasla ktorych pola sa rowne wprowadzonemu przez uzytkownika stringowi.
     */
    static void wyszukajHaslo();

    /**
     *Funkcja sortujaca hasla po jednym z pol {"Nazwa", "Haslo", "Kategoria", "Serwis", "Login"}.
     *
     * Hasla wyswietlane sa na ekranie w posortowanym porzadku.
     */
    static void posortujHasla();

    /**
     * Funkcja wyswietlajaca wszystkie hasla znajdujace sie w wektorze wskaznikow hasel. W przypadku gdy wektor jest pusty wyswietlany jest
     * komunikat "Brak hasel.".
     */
    static void wyswietlWszystkieHasla();

    /**
     * Funkcja tworzy nowe haslo.
     *
     * Uzytkownik proszony jest o podanie odpowiednich pol w celu stworzenia hasla. Haslo dodawane jest do wektora wskaznikow hasel.
     */
    static void dodajHaslo();

    /**
     * Funkcja sprawdzajaca czy podane haslo istnieje.
     *
     * Funkcja sprawdza wszystkie pola std::string haslo wszystkich hasel znajdujacych sie w wektorze hasel. Zwraca true jezeli
     * istnieje takie same haslo do tekstu podanego w parametrze. Zwraca false jezeli wszystie hasla sa inne od podanego.
     * @param haslo - Tekst do ktorego przyrownujemy wszystkie istniejace hasla.
     * @return True jezeli haslo juz istnieje. False jezeli haslo jest inne od istniejacych.
     */
    static bool czyHasloIstnieje(std::string haslo);

    /**
     * Funkcja zmieniajaca haslo.
     *
     * Uzytkownik ma mozliwosc zmiany hasla samemu lub wybrac losowe haslo.
     * Uzytkownik ma mozliwosc wyboru dlugosci i zlozonosci hasla losowego.
     * Po wyborze hasla informowany jest o sile hasla oraz o tym czy podane haslo juz istnieje.
     *
     * @param haslo - Haslo do zmienienia.
     */
    static void zmienHaslo(Haslo* haslo);

    /**
     *Funkcja pozwalajaca na edycje dowolnego pola hasla {"Nazwa", "Haslo", "Kategoria", "Serwis", "Login"}.
     * W przypadku braku hasel do edycji wyswietlany jest komunikat "Brak hasel do edycji.".
     */
    static void edytujHaslo();

    /**
     *Funkcja pozwalajaca wybrac haslo do usuniecia z wektora hasel.
     * W przypadku braku hasel do usuniecia wyswietlany jest komunikat "Brak hasel do usuniecia.".
     */
    static void usunHaslo();

    /**
     * Funkcja dodajaca kategorie do listy kategorii z ktorych uzytkownik moze korzystac.
     */
    static void dodajKategorie();

    /**
     * Funkcja usuwajaca jedna z kategorii z listy kategorii.
     * W przypadku braku kategorii wyswietlany jest komunikat "Lista kategorii jest pusta.".
     */
    static void usunKategorie();

    /**
     * Funkcja generujaca losowe haslo.
     *
     * @param dlugoscHasla - Zmienna informujaca o dlugosci hasla.
     * @param czySaWielkieLitery - Zmienna informujaca czy haslo ma zawierac wielkie litery.
     * @param czyZawieraZnakiSpecjalne - Zmienna informujaca czy haslo ma zawierac znaki specjalne.
     * @return Zwracane jest losowe haslo w postaci stringa.
     */
    static std::string generujLosoweHaslo(int dlugoscHasla, bool czySaWielkieLitery, bool czyZawieraZnakiSpecjalne);

    /**
     * Funkcja sprawdza sile hasla sprawdzajac czy w hasle jest liczba, mala litera, wielka litera, znak specjalny
     * oraz to czy haslo jest krotsze od 5 znakow.
     *
     * @return Funkcja zwraca liczbe od -2 do 10.
     */
    static int sprawdzMocHasla(const std::string& haslo);

    const std::string &getNazwa() const;

    void setNazwa(const std::string &nazwa);

    const std::string &getHaslo() const;

    void setHaslo(const std::string &haslo);

    const std::string &getKategoria() const;

    void setKategoria(const std::string &kategoria);

    const std::string &getSerwis() const;

    void setSerwis(const std::string &serwis);

    const std::string &getLogin() const;

    void setLogin(const std::string &login);
};


#endif //PROJECTCPP_HASLO_H
