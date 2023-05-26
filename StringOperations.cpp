//
// Created by danio on 26.05.2023.
//

#include "StringOperations.h"

std::string StringOperations::stworzStringZNSpacji(const int & liczSpacji) {
    std::string naszString;
    for(int i = 0; i< liczSpacji; i++){
        naszString.append(" ");
    }
    return naszString;
}
