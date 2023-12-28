#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <clocale>
#include <random>

void rangebase(const std::vector<int>& vecto);
void iterator(const std::vector<int>& vecto);
void nomer(const std::vector<int>& vecto);
double Mean(const std::vector<int>& vecto);
double Median(std::vector<int> vec);

std::vector<int> Mode(const std::vector<int>& vecto) {
    std::map<int, int> counts;
    for (int value : vecto) {
        counts[value]++;
    }

    int naib = 0;
    for (const auto& pair : counts) {
        naib = std::max(naib, pair.second);
    }

    std::vector<int> mod;
    for (const auto& pair : counts) {
        if (pair.second == naib) {
            mod.push_back(pair.first);
        }
    }
    return mod;
}

int main() {
    int tip;
    int razmer;
    int ball;
    int i;
    int a;
    double mean;
    double median;
    std::vector<std::string> imena;
    std::vector<std::string> imenarand;
    std::vector<int> balls;
    
    setlocale(LC_CTYPE, "rus");
    
    std::cout << "Напишите циферку в соответствии со способом: 1 - дефолтные значения, 2 - случайные значения, 3 - входные значения " << std::endl;
    std::cin >> tip;

    if (tip == 1) {
        imena = { "Sofy", "Sofya", "Alena", "Nadya", "Sacha", "Amalia", "Julia", "Polina", "Egor", "Stepa", "Ignat", "Andrey" };
        balls = { 88, 90, 76, 86, 91, 100, 80, 87, 97, 94, 87, 96 };
    }
    else if (tip == 2) {
        std::cout << "Размер выборки: ";
        std::cin >> razmer; 
        for (int n = 0; n < razmer; ++n) {
            std::string imy;
            imenarand = { "Sofy", "Sofya", "Alena", "Nadya", "Sacha", "Amalia", "Julia", "Polina", "Egor", "Stepa", "Ignat", "Andrey" };
            imy = imenarand[rand()%11];
            ball = rand()%100;
            imena.push_back(imy);
            balls.push_back(ball);
        }
    }
    else if (tip == 3) {
        std::cout << "Кол-во учеников: ";
        std::cin >> razmer;
        for (i = 0; i < razmer; ++i) {
            std::string imy;
            std::cout << "Имя: ";
            std::cin >> imy;
            std::cout << "Баллы: ";
            std::cin >> ball;
            imena.push_back(imy);
            balls.push_back(ball);
        }
    }

    nomer(balls);

    mean = Mean(balls);
    median = Median(balls);
    std::cout << "Среднее значение оценок: " << mean << std::endl;
    std::cout << "Медиана:" << median << std::endl;
   
    std::vector<int> mode = Mode(balls);
    std::cout << "Мода: ";
    for (int otvet : mode) {
        std::cout << otvet << " " << std::endl;
    }

    std::cout << "Ученики с модными баллами: ";
    for (size_t i = 0; i < balls.size(); ++i) {
        if (std::find(mode.begin(), mode.end(), balls[i]) != mode.end()) {
            std::cout << imena[i] << " " << std::endl;
        }
    }
    return 0;
}


void rangebase(const std::vector<int>& vecto) {
    for (const auto& otvet : vecto) {
        std::cout << otvet << " "<< std::endl;
    }
}

void iterator(const std::vector<int>& vecto) {
    for (auto m = vecto.begin(); m != vecto.end(); ++m) {
        std::cout << *m << " " << std::endl;
    }
}

void nomer(const std::vector<int>& vecto) {
    for (size_t i = 0; i < vecto.size(); ++i) {
        std::cout << vecto[i] << " " << std::endl;
    }
}

double Mean(const std::vector<int>& vecto) {
    int summa = 0;
    for (int otvet : vecto) {
        summa = summa + otvet;
    }
    return static_cast<double>(summa) / vecto.size();
}

double Median(std::vector<int> vecto) {
    std::sort(vecto.begin(), vecto.end());
    size_t size = vecto.size();
    if (size%2 == 0) {
        return (vecto[(size/2) - 1] + vecto[size/2])/2.0;
    }
    else {
        return vecto[size/2];
    }
}


