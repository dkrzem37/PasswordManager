//
// Created by danio on 26.05.2023.
//

#include "FileOperations.h"
#include <fstream>


std::vector<std::string> FileOperations::pobierzPlikDoVectora(const std::string& sciezkaPliku) {
    std::vector<std::string> plikVector;
    std::ifstream plik(sciezkaPliku);
    std::string tekst;
    if(plik.is_open()){
        for(int i = 0; i< 3; i++){
            std::getline(plik, tekst);
        }
        while(std::getline(plik, tekst)){
            plikVector.push_back(tekst);
        }
    }
    plik.close();
    return plikVector;
}

/*std::string FileOperations::pobierzDateZPliku(const std::string & sciezkaPliku) {
    std::ifstream plik(sciezkaPliku);
    std::string tekst;
    std::string data;
    if(plik.is_open()){
        for(int i = 0; i < 3; i++){
            std::getline(plik, tekst);
            data.append(std::to_string(tekst.length()));
            if(i == 0 || i == 1)
                data.append(std::to_string(tekst.length()) + ":");
        }
    }
    plik.close();
    return data;
}*/
