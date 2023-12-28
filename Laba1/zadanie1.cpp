#include <iostream>
#include <string>
#include <algorithm>

//strlen(посчет кол-во символов в строке)
//С: size, С++: std::strlen

//strcpy(копирует символы из строки в другую строку)
//С: assign, С++: std::strcpy

//strcmp (сравнивает строки)
//С: compare, С++: std::strcmp

//strcat (дописывает символы из одной строки в конец другой)
//С: append, С++: std::strcat

//someString[index] (предоставляет доступ к строке по индексу)
//С: at[index], С++: std::someString[index]

//push_back (добавляет ячейку в конец вектора)
//С: Нет прямого эквивалента в С, С++: std::vector::push_back

//pop_back (добавляет ячейку в начало вектора)
//С: Нет прямого эквивалента в С, С++: std::vector::pop_back*/

int main() {

    std::string str;
    std::getline(std::cin, str);
    str.erase(std::remove_if(str.begin(), str.end(), [](char a) { 
            return std::isspace(a) || std::ispunct(a);
            }), str.end());

    std::sort(str.begin(), str.end());
    std::cout << str << std::endl;
    
    return 0;
}
