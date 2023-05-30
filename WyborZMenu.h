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

    static int wyborOpcji(const std::list<std::string>&);
    static int wyborOpcji(const std::vector<Haslo*>&);
    static int wyborLiczby(int, int);
    static bool wyborOpcjiBoolean();

};


#endif //PROJECTCPP_WYBORZMENU_H
