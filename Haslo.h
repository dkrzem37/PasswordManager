//
// Created by danio on 20.05.2023.
//
#include <string>
#include <list>

#ifndef PROJECTCPP_HASLO_H
#define PROJECTCPP_HASLO_H

class Haslo {
    std::string nazwa, haslo, kategoria, serwis, login;
public:
    static std::list<Haslo*> listaHasel;
    Haslo();
    Haslo(std::string nazwa, std::string haslo, std::string kategoria, std::string serwis, std::string login);

    static void wyszukajHaslo();
    static std::list<Haslo> posortujHasla();
    static void dodajHaslo();
    static void edytujHaslo();
    static void usunHaslo();
    static void edytujKategorie();
    static void usunKategorie();

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