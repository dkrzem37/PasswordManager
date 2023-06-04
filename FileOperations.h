//
// Created by danio on 26.05.2023.
//

#ifndef PROJECTCPP_FILEOPERATIONS_H
#define PROJECTCPP_FILEOPERATIONS_H
#include <vector>
#include <string>

class FileOperations {
public:
    /**
     * Ta funkcja pobiera sciezke do pliku, pobiera wszystkie linie oprocz pierwszych trzech, a nastepnie zwraca vector stringow
     * ktore sa liniami tego pliku.
     *@param sciezkaPliku - Sciezka pliku z ktorego maja zostac pobrane dane.
     * @return Vector zawierajacy linie z pliku w formie stringow.
     */
    static std::vector<std::string> pobierzPlikDoVectora(const std::string& sciezkaPliku);
    //static std::string pobierzDateZPliku(const std::string&);
};


#endif //PROJECTCPP_FILEOPERATIONS_H
