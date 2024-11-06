
# Checker

O **Checker** é um projeto desenvolvido em C++ que realiza o processamento paralelo de cartões de crédito, simulando a validação de dados como número do cartão, data de validade e CVV. O programa lê um arquivo contendo essas informações e, por meio de threads, processa múltiplos cartões simultaneamente, enviando requisições de validação para um gateway (que pode ser configurado conforme a necessidade). O objetivo é otimizar o processo de verificação de cartões ao utilizar múltiplas threads para realizar as verificações em lote.

## Funcionalidades

- Leitura de um arquivo de texto contendo informações de cartões de crédito.
- Processamento paralelo usando threads para melhorar a performance.
- Exibição das informações de cartão no formato `CC: <número> DATA: <mês/ano> CVV: <cvv>`.

## Como usar

1. **Clonar o repositório**

   Clone este repositório para o seu ambiente local:

   ```bash
   git clone https://github.com/Vinisantosz/Checker.git
   ```

2. **Compilar o projeto**

   O projeto utiliza C++ e pode ser compilado usando um compilador como o `g++`. Certifique-se de que as dependências estejam instaladas.

   Para compilar o projeto:

   ```bash
   g++ -o app app.cpp -std=c++11
   ```

3. **Executar o programa**

   Após compilar, execute o programa com o seguinte comando:

   ```bash
   ./app
   ```

   O programa solicitará o número de cartões de crédito para testar simultaneamente.

4. **Configuração do arquivo de entrada**

   O arquivo de entrada `db.txt` deve conter informações de cartões no formato:

   ```
   <número do cartão>|<data de validade>|<CVV>
   ```

   Cada linha representa um cartão de crédito que será processado.

## Contribuições

Contribuições são bem-vindas! Se você tem sugestões ou melhorias, fique à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto é de uso educativo e não tem fins comerciais. Não é autorizado o uso para transações financeiras reais.
