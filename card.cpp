#include <iostream>
#include <fstream>
#include "card.h"

std::string Card::file() {
    if (!my_file.is_open()) {
        my_file.open("db.txt");
        if(!my_file) {
            std::cerr << "Erro ao abrir arquivo!" << std::endl;
            return "";
        }
    }

    std::string line;
    if (std::getline(my_file, line)) {
        return line;
    }

    return "";
}

Card::Card() {
    std::string line;
    while (!(line = file()).empty()) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            number = line.substr(0, pos1);
            date = line.substr(pos1 + 1, pos2 - pos1 - 1);
            cvv = line.substr(pos2 + 1);
            std::string year = date.substr(3, 4);
            std::string exp_year = year.substr(2, 2);
            std::cout << "CC: " << number << " DATA: " << date.substr(0, 2) << "/" << exp_year << " CVV: " << cvv << std::endl;
        }
    }
}

Card::~Card() {
    if (my_file.is_open()) {
        my_file.close();
    }
}