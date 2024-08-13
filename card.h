#ifndef CARD_H
#define CARD_H

#include <string>
#include <fstream>

class Card {
    private:
        std::string number;
        std::string date;
        std::string cvv;
        std::fstream my_file;

    public:
        Card();            // Construtor
        ~Card();           // Destrutor
        std::string file(); // Método para ler o arquivo
};

#endif
