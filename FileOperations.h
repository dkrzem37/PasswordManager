//
// Created by danio on 26.05.2023.
//

#ifndef PROJECTCPP_FILEOPERATIONS_H
#define PROJECTCPP_FILEOPERATIONS_H
#include <vector>
#include <string>

class FileOperations {
public:
    static std::vector<std::string> pobierzPlikDoVectora(const std::string&);
    static std::string pobierzDateZPliku(const std::string&);
};


#endif //PROJECTCPP_FILEOPERATIONS_H
