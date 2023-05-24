//
// Created by danio on 24.05.2023.
//

#ifndef PROJECTCPP_WYBORZMENU_H
#define PROJECTCPP_WYBORZMENU_H
#include <string>
#include <list>

class WyborZMenu {
public:

    WyborZMenu();

    static int wyborOpcji(const std::list<std::string>&);

};


#endif //PROJECTCPP_WYBORZMENU_H
