//
// Created by danio on 23.05.2023.
//

#ifndef PROJECTCPP_SZYFR_H
#define PROJECTCPP_SZYFR_H

#include <string>

class Szyfr {

public:
    static std::string testHasla;
    static std::string odszyfruj(std::string, std::string);
    static void szyfruj(std::string*, const std::string& );
    static void odszyfruj(std::string*, const std::string& );
};


#endif //PROJECTCPP_SZYFR_H
