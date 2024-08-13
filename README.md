# Checker

**Checker** é um projeto desenvolvido para fins educativos e éticos. O código demonstra como processar e manipular dados de cartões de crédito a partir de um arquivo. Este projeto não inclui funcionalidade para interagir com gateways de pagamento e não deve ser usado para fins fraudulentos.

**Nota Importante**: Este código não inclui funcionalidades para interagir com gateways de pagamento e não deve ser usado para transações financeiras. O projeto é estritamente para fins educativos e éticos.


## Descrição do Código

O projeto consiste em dois arquivos principais:

1. **main.cpp**: Este arquivo contém o ponto de entrada do programa. Ele configura o ambiente para suportar caracteres UTF-8 e instancia a classe `Card` para processar o arquivo de dados.

2. **card.h** e **card.cpp**: Estes arquivos definem a classe `Card`. A classe `Card` é responsável por ler e processar dados de um arquivo chamado `db.txt`, que contém informações de cartões de crédito no formato `número|data|cvv`.

   - **Construtor**: O construtor da classe `Card` abre o arquivo `db.txt`, lê cada linha e divide os dados em três partes: número do cartão, data de validade e CVV. Os dados são então exibidos no console.

   - **Destrutor**: O destrutor fecha o arquivo se ele estiver aberto.

## Uso

Para compilar e executar o projeto, siga os passos abaixo:
Método 1

1. Certifique-se de que o arquivo `db.txt` está no mesmo diretório do executável e contém dados no formato `número|data|cvv`.

2. Compile o código com um compilador C++ compatível. Por exemplo:

   ```bash
   g++ -o checker main.cpp card.cpp




Método 2
## Usando CMake
Certifique-se de ter o CMake instalado. Você pode verificar a versão do CMake com o comando: cmake --version

Crie um diretório de construção e navegue até ele:
1. mkdir build
2. cd build


Gere os arquivos de construção com CMake e compile o código:
1. cmake ..
2. cmake --build .