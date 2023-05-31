//
// Created by danio on 26.05.2023.
//

#ifndef PROJECTCPP_STRINGOPERATIONS_H
#define PROJECTCPP_STRINGOPERATIONS_H
#include <string>

class StringOperations {
public:
    static std::string stworzStringZNSpacji(const int&);
    static bool sprawdzCzyJestMalaLitera(const std::string&);
    static bool sprawdzCzyJestWielkaLitera(const std::string&);
    static bool sprawdzCzyJestZnakSpecjalny(const std::string&);
    static bool sprawdzCzyJestLiczba(const std::string&);
};


#endif //PROJECTCPP_STRINGOPERATIONS_H
