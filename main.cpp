#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <windows.h>

// Mutex para controle de acesso ao console
std::mutex mtx;

void request(const std::string& number, const std::string& date, const std::string& cvv)
{

}

void processLine(const std::string& line)
{
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);

    if (pos1 != std::string::npos && pos2 != std::string::npos) 
    {
        std::string number = line.substr(0, pos1);
        std::string date = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string cvv = line.substr(pos2 + 1);
        std::string year = date.substr(3, 4);
        std::string exp_year = year.substr(2, 2);
        
        // Chama a função para enviar a requisição para gateway
        request(number, date, cvv);
        
        // Usando mutex para evitar conflitos de impressão
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "CC: " << number << " DATA: " << date.substr(0, 2) << "/" << exp_year << " CVV: " << cvv << std::endl;
    }
}

void runTests(const std::vector<std::string>& lines, int batchSize)
{
    std::vector<std::thread> threads;
    for (size_t i = 0; i < lines.size(); i += batchSize) 
    {
        for (size_t j = i; j < i + batchSize && j < lines.size(); ++j) 
        {
            threads.emplace_back(processLine, lines[j]);
        }
        
        // Espera as threads concluírem antes de iniciar o próximo lote
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }

        threads.clear(); // Limpa as threads para o próximo lote
    }
}

std::vector<std::string> loadFileLines() 
{
    std::ifstream db("db.txt");
    std::vector<std::string> lines;
    std::string line;

    if (!db.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo db.txt" << std::endl;
        return lines;
    }

    while (std::getline(db, line)) 
    {
        lines.push_back(line);
    }

    return lines;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    std::vector<std::string> fileLines = loadFileLines();

    int batchSize;
    std::cout << "Número de CC's para testar de uma vez: ";
    std::cin >> batchSize;

    runTests(fileLines, batchSize);

    return 0;
}
