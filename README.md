# edIII-hashmap

Documentação do Projeto Jumanji: O Codex do Poder das Gemas

Este documento detalha as funcionalidades implementadas para o "Trabalho II - Estrutura de Dados III: Jumanji: o Codex do Poder das Gemas!". O objetivo principal é otimizar a busca e manipulação de informações sobre gemas no universo Jumanji, superando as limitações de uma busca binária simples para cenários específicos.
1. Estrutura da Gema (Gema.hpp)

A base do sistema é a estrutura Gema, que representa cada gema com as seguintes propriedades:

    id: Identificador único da gema (inteiro).

    corHex: Representação hexadecimal da cor da gema (string, ex: #RRGGBB).

    intensidade: Valor numérico que representa a intensidade da cor da gema (double).

    proxID: Ponteiro para a próxima gema na lista encadeada da tabela hash de IDs.

    proxIntensidade: Ponteiro para a próxima gema na lista encadeada da tabela hash de Intensidades.

Funções Auxiliares de Cor e Intensidade:

    hexCharParaInt(char c): Converte um caractere hexadecimal para seu valor inteiro correspondente.

    retornaHexUInt(string hex): Converte uma string hexadecimal (ex: #FFFFFF) para um unsigned int.

    hexParaRGB(unsigned int valorHex): Converte um valor hexadecimal inteiro em um vetor de inteiros RGB (Red, Green, Blue).

    retornaLuminosidadeHSV(vector<int> RGB): Calcula a luminosidade (Valor V do HSV) a partir dos componentes RGB.

    calcularIntensidade(string hex): Função principal para calcular a intensidade de uma gema a partir de sua cor hexadecimal. Resolve o problema de representar a intensidade da cor com um valor tangível, conforme solicitado no enunciado.

Funções de Ordenação:

Para as operações de busca binária, é crucial que o vetor de gemas esteja ordenado. As seguintes funções de ordenação são fornecidas:

    ordenarGemasCor(vector<Gema>* vetorDeGemas): Ordena o vetor de gemas pela corHex.

    ordenarGemasID(vector<Gema>* vetorDeGemas): Ordena o vetor de gemas pelo id.

    ordenarGemasIntensidade(vector<Gema>* vetorDeGemas): Ordena o vetor de gemas pela intensidade.

2. Tabelas Hash (Hash.hpp)

Para agilizar as operações de busca por ID e intensidade, foram implementadas duas tabelas hash separadas, conforme a restrição de não usar HashMaps prontos e a sugestão de manter múltiplas estruturas em memória com ponteiros para evitar duplicação de dados.

    hashtableID[HASH_TABLE_SIZE]: Tabela hash para indexar gemas por seu id.

    hashtableIntensidade[HASH_TABLE_SIZE]: Tabela hash para indexar gemas por sua intensidade.

Funções de Hash:

    hashfunctionID(int id): Calcula o índice na tabela hash para um dado id. A função simples de módulo (id % HASH_TABLE_SIZE) é utilizada.

    hashFunctionIntensidade(double intensidade): Calcula o índice na tabela hash para uma dada intensidade. Normaliza a intensidade (0-100) para um valor entre 0-255 e aplica o módulo.

Operações nas Tabelas Hash:

    incializaTabelaHash(): Inicializa ambas as tabelas hash com nullptr.

    inserirNasTabelasHash(Gema* gema): Insere uma gema nas duas tabelas hash. Utiliza listas encadeadas para resolver colisões (encadeamento separado).

    consultaTabelaHashID(int id, int& saltos): Busca uma única gema pelo id na tabela hash de IDs. Conta os "saltos" (comparações) necessários. Resolve o problema de buscar uma gema por ID de forma rápida, visando um custo próximo de O(1) em casos ideais, conforme o enunciado.

    consultaTabelaHashIntensidade(double intensidade, int& saltos): Busca uma única gema pela intensidade na tabela hash de Intensidades. Conta os "saltos".

    deletarNasTabelasHash(Gema* gema): Remove uma gema de ambas as tabelas hash. Essencial para a funcionalidade do "raio".

    consultarTodasTabelaHashID(int id, int& saltos): Retorna um vetor de ponteiros para todas as gemas com o mesmo id. Embora o enunciado sugira que IDs são únicos, esta função está preparada para múltiplos resultados, caso a regra mude ou haja dados inconsistentes.

    consultarTodasTabelaHashIntensidade(double intensidade, int& saltos): Retorna um vetor de ponteiros para todas as gemas com a mesma intensidade. Resolve o problema de encontrar todas as gemas com uma determinada intensidade de forma eficiente.

3. Buscas Binárias (Busca_binaria.hpp)

As funções de busca binária são implementadas para comparação de desempenho com as tabelas hash, conforme exigido pelo trabalho. Elas operam em um vetor de gemas que deve estar previamente ordenado pelo critério de busca.

    buscaBinariaUnitariaCor(vector<Gema>* vetorDeGemas, string corHex, int& saltos): Realiza uma busca binária para encontrar uma única gema por sua corHex. Conta os "saltos".

    buscaBinariaMultiplaCor(vector<Gema>* vetorDeGemas, string corHex, int& saltos): Realiza uma busca binária para encontrar todas as gemas com a mesma corHex. Isso é feito encontrando a primeira ocorrência e depois expandindo para a esquerda e direita. Conta os "saltos".

    buscaBinariaID(vector<Gema>* vetorDeGemas, int id, int& saltos): Realiza uma busca binária para encontrar uma única gema por seu id. Conta os "saltos".

    buscaBinariaIntensidade(vector<Gema>* vetorDeGemas, double intensidade, int& saltos): Realiza uma busca binária para encontrar todas as gemas com a mesma intensidade. Conta os "saltos".

4. Raio (Raio.hpp)

A funcionalidade do "raio" simula um evento aleatório que altera uma gema, exigindo que as estruturas de dados sejam atualizadas.

    aplicarRaio(vector<Gema>* gemas):

        Seleciona uma gema aleatoriamente do vetor principal.

        Deleta essa gema de ambas as tabelas hash.

        Gera uma nova corHex aleatória para a gema.

        Recalcula a intensidade da gema com base na nova cor.

        Reinsere a gema (com suas novas propriedades) em ambas as tabelas hash.

        Imprime as informações da gema afetada.

    Esta função resolve o requisito de "Um raio deve aleatoriamente alterar a cor de uma gema. Essa alteração deve ser atualizada em ambas as organizações."

5. Parser (Parser.hpp)

O parser é responsável por ler o arquivo de entrada (gemas2.txt) e popular o vetor de gemas e as tabelas hash.

    retornaId(string linha): Extrai o ID de uma linha JSON.

    retornaCor(string linha): Extrai a cor hexadecimal de uma linha JSON.

    retornaGemas(string nomeArquivoEntrada): Lê o arquivo, parseia cada linha para criar objetos Gema, calcula suas intensidades e as insere nas tabelas hash. Resolve o problema de carregar o catálogo de gemas.

6. Funções de Impressão (Print_functions.hpp)

Um conjunto de funções para auxiliar na visualização dos dados e resultados das operações.

    printarTodasGemas(vector<Gema>& gemas): Imprime os detalhes de todas as gemas em um vetor.

    printarTodasGemasPonteiro(vector<Gema*>& gemas): Imprime os detalhes de todas as gemas em um vetor de ponteiros.

    printarUmaGema(Gema* gema): Imprime os detalhes de uma única gema.

    printarHashTableID(): Imprime o conteúdo da tabela hash de IDs, mostrando o encadeamento.

    printarHashTableIntensidade(): Imprime o conteúdo da tabela hash de Intensidades, mostrando o encadeamento.

    printarRaio(Gema gema): Imprime as informações de uma gema após a aplicação do raio.

7. main.cpp e testes.cpp

O main.cpp implementa o menu interativo para demonstrar as funcionalidades, permitindo ao usuário realizar buscas, aplicar o raio e visualizar as tabelas hash. Ele também mede o tempo de execução e o número de "saltos" para cada operação, conforme solicitado.

O testes.cpp é um arquivo separado para realizar testes de desempenho automatizados, comparando as buscas por ID e Intensidade entre as tabelas hash e as buscas binárias. Os resultados são salvos em um arquivo CSV (resultados_busca.csv) para análise posterior, cumprindo a exigência de comparar o desempenho das soluções propostas com a busca binária.
8. Gerador de Gemas (gerador_gemas.py)

Este script Python é responsável por criar um arquivo de texto (gemas2.txt) contendo um número especificado de gemas no formato JSON. Cada gema possui um id único e uma cor hexadecimal gerada aleatoriamente.
Funções:

    gerar_cor_hex(): Gera uma string de cor hexadecimal aleatória no formato #RRGGBB.

    gerar_gemas(qtd=100, nome_arquivo='gemas2.txt'):

        Recebe como parâmetros a quantidade de gemas a serem geradas (qtd, padrão 100) e o nome do arquivo de saída (nome_arquivo, padrão gemas2.txt).

        Abre o arquivo no modo de escrita.

        Itera qtd vezes, criando um dicionário Python para cada gema com id e cor.

        Converte o dicionário para uma string JSON e a escreve no arquivo, seguida por uma nova linha.

        Imprime uma mensagem de confirmação após a geração.

Execução:

Quando o script é executado diretamente (if __name__ == "__main__":), ele chama a função gerar_gemas() para criar 100 gemas por padrão. Este arquivo é essencial para criar os dados de entrada para o programa C++, garantindo um conjunto de dados consistente para testes e demonstrações.
Resolução dos Problemas do Enunciado:

    Construir um Codex das gemas, organizando o catálogo de gemas para agilizar a busca e alterações: Resolvido pela implementação das duas tabelas hash (por ID e por Intensidade) que indexam as gemas, permitindo acesso rápido.

    Indexação por ID e Intensidade: As tabelas hash hashtableID e hashtableIntensidade cumprem este requisito, utilizando ponteiros para evitar duplicação de dados.

    Buscar gema por ID (único e múltiplo): As funções consultaTabelaHashID e consultarTodasTabelaHashID (embora a última seja mais genérica para múltiplos) resolvem isso com eficiência, visando O(1) no melhor caso.

    Buscar gema por cor específica (busca binária): A função buscaBinariaUnitariaCor e buscaBinariaMultiplaCor (para múltiplas) abordam esta busca, utilizando ordenação prévia do vetor.

    Buscar gema por intensidade (busca binária): A função buscaBinariaIntensidade permite buscar gemas por intensidade, também requerendo ordenação prévia.

    Criar um raio (alterar cor de uma gema e atualizar ambas as organizações): A função aplicarRaio gerencia a alteração aleatória da gema e a atualização consistente em ambas as tabelas hash.

    Medir tempo e "saltos": Todas as operações de busca e o main e testes.cpp incluem medições de tempo (std::chrono) e contagem de "saltos" para análise de desempenho.

    Comparação com Busca Binária: O testes.cpp é dedicado a essa comparação, gerando dados para demonstrar a superioridade das soluções baseadas em hash para os casos específicos.

    Medição de memória: A função printarHashTableID e printarHashTableIntensidade no main.cpp inclui a impressão do tamanho das tabelas hash e do vetor de gemas em bytes, atendendo ao requisito de medir a memória gasta.
