# Parallel Sortings: A Comparative Project in Serial and Parallel Programming

## Selecionar idioma / Select language:

<details>
  <summary>Clique para abrir a versão em Português</summary>

  # Parallel Sortings: Um Projeto Comparativo em Programação Serial e Paralela

  Bem-vindo ao repositório **Parallel Sortings**! Este projeto explora o poder da programação paralela por meio de algoritmos de ordenação seriais e paralelos implementados em **Java** (atualmente) e **C++** (em breve). Nosso objetivo é ilustrar como o paralelismo de tarefas pode otimizar significativamente o desempenho, especialmente para grandes conjuntos de dados.

  ## Visão Geral do Projeto

  Este repositório faz parte de um projeto universitário que introduz e demonstra a eficácia da programação paralela. Ao dividir as tarefas de ordenação e processá-las simultaneamente, buscamos alcançar resultados mais rápidos do que as abordagens seriais tradicionais.

  Este projeto demonstra:
  - **Algoritmos de ordenação seriais** para comparações de referência.
  - **Algoritmos de ordenação paralelos** para destacar os ganhos de desempenho por meio da divisão de tarefas.
  - **Métricas de desempenho** com diferentes tamanhos de conjuntos de dados para ilustrar a escalabilidade.

  ## Implementações

  ### Implementação em Java

  Nossa solução em Java implementa e avalia o desempenho de vários algoritmos de ordenação seriais e paralelos com diferentes tamanhos de arrays para comparar os tempos de execução.

  #### Algoritmos de Ordenação Incluídos
  1. **Algoritmos de Ordenação Seriais:**
     - Merge Sort (Ordenação por Intercalação)
     - Bubble Sort (Ordenação por Bolha)
     - Quick Sort (Ordenação Rápida)
     - Selection Sort (Ordenação por Seleção)
     - Insertion Sort (Ordenação por Inserção)
     - Counting Sort (Ordenação por Contagem)

  2. **Algoritmos de Ordenação Paralelos:**
     - Parallel Merge Sort (Ordenação por Intercalação Paralela)
     - Parallel Bubble Sort (Ordenação por Bolha Paralela)
     - Parallel Quick Sort (Ordenação Rápida Paralela)
     - Parallel Selection Sort (Ordenação por Seleção Paralela)
     - Parallel Insertion Sort (Ordenação por Inserção Paralela)
     - Parallel Counting Sort (Ordenação por Contagem Paralela)

  #### Exemplos de Resultados de Benchmark

  Abaixo estão alguns tempos de execução para cada algoritmo com tamanhos de arrays de **10**, **100**, **1.000** e **10.000** elementos. Os resultados ilustram os benefícios da ordenação paralela à medida que os tamanhos dos arrays aumentam.

  <details>
  <summary>Clique para expandir os resultados do benchmark</summary>

  ##### Tamanho do Array: 10
  - **Ordenações Paralelas**:
    - Tempo do Parallel Merge Sort: 11.970.428 ns
    - Tempo do Parallel Bubble Sort: 8.507.228 ns
    - Tempo do Parallel Quick Sort: 1.919.143 ns
    - Tempo do Parallel Selection Sort: 2.754.165 ns
    - Tempo do Parallel Insertion Sort: 7.078.392 ns
    - Tempo do Parallel Counting Sort: 6.335.696 ns
  - **Ordenações Seriais**:
    - Tempo do Serial Merge Sort: 649.523 ns
    - Tempo do Serial Bubble Sort: 6.842 ns
    - Tempo do Serial Quick Sort: 241.581 ns
    - Tempo do Serial Selection Sort: 5.233 ns
    - Tempo do Serial Insertion Sort: 7.125 ns
    - Tempo do Serial Counting Sort: 35.799 ns

  ... *(e assim por diante para tamanhos maiores de arrays)*

  </details>

  ### Implementação em C++ *(Em Breve)*

  A versão em C++ dos algoritmos de ordenação será introduzida para explorar ainda mais otimizações de desempenho na programação paralela. Esta versão irá:
  - Usar o **XMake** como sistema de build.
  - Incluir algoritmos de ordenação seriais e paralelos semelhantes para comparação direta com a implementação em Java.
  - Medir o desempenho com diferentes tamanhos de dados para comparar a eficiência do C++ vs. Java nas tarefas de ordenação paralela.

  ### Direções Futuras

  1. **Comparação entre Linguagens**: Após a implementação em C++, vamos analisar e comparar os resultados de desempenho entre Java e C++. Isso proporcionará insights sobre como as diferenças entre as linguagens e seus ambientes de execução afetam o desempenho de algoritmos paralelos.
  2. **Testes de Escalabilidade**: Com conjuntos de dados maiores, nosso objetivo é observar como os algoritmos se comportam com cargas de trabalho crescentes e determinar os pontos de equilíbrio para os benefícios da paralelização.

  ## Como Executar o Código em Java

  Para rodar a implementação em Java:
  1. **Compile** os arquivos Java: `javac *.java`
  2. **Execute a classe principal**: `java MainClass`
  3. Veja a saída do benchmark no console, conforme os resultados de exemplo mostrados acima.

  ## Como Executar o Código em C++ *(Planejado)*

  Para o código C++ que será disponibilizado:
  1. Clone o repositório e instale o **XMake** caso necessário.
  2. Compile e execute o programa usando:
     ```bash
     xmake
     xmake run
     ```

</details>

<details>
  <summary>Click to open the English version</summary>

  # Parallel Sortings: A Comparative Project in Serial and Parallel Programming

  Welcome to the **Parallel Sortings** repository! This project explores the power of parallel programming through serial and parallel sorting algorithms implemented in **Java** (current) and **C++** (coming soon). Our aim is to illustrate how task parallelism can significantly optimize performance, particularly for large datasets.

  ## Project Overview

  This repository is part of a college project that introduces and demonstrates the effectiveness of parallel programming. By breaking down sorting tasks and processing them simultaneously, we aim to achieve faster results than traditional serial approaches.

  This project showcases:
  - **Serial sorting algorithms** for baseline comparisons.
  - **Parallel sorting algorithms** to highlight performance gains via task division.
  - **Performance metrics** across varying dataset sizes to illustrate scalability.

  ## Implementations

  ### Java Implementation

  Our Java solution implements and benchmarks various serial and parallel sorting algorithms with different array sizes to compare execution times.

  #### Sorting Algorithms Included
  1. **Serial Sorting Algorithms:**
     - Merge Sort
     - Bubble Sort
     - Quick Sort
     - Selection Sort
     - Insertion Sort
     - Counting Sort

  2. **Parallel Sorting Algorithms:**
     - Parallel Merge Sort
     - Parallel Bubble Sort
     - Parallel Quick Sort
     - Parallel Selection Sort
     - Parallel Insertion Sort
     - Parallel Counting Sort

  #### Sample Benchmark Results

  Below are sample timings for each algorithm based on array sizes of **10**, **100**, **1,000**, and **10,000** elements. Results illustrate the benefits of parallel sorting as array sizes increase.

  <details>
  <summary>Click to expand benchmark results</summary>

  ##### Array Size: 10
  - **Parallel Sorts**:
    - Parallel Merge Sort Time: 11,970,428 ns
    - Parallel Bubble Sort Time: 8,507,228 ns
    - Parallel Quick Sort Time: 1,919,143 ns
    - Parallel Selection Sort Time: 2,754,165 ns
    - Parallel Insertion Sort Time: 7,078,392 ns
    - Parallel Counting Sort Time: 6,335,696 ns
  - **Serial Sorts**:
    - Serial Merge Sort Time: 649,523 ns
    - Serial Bubble Sort Time: 6,842 ns
    - Serial Quick Sort Time: 241,581 ns
    - Serial Selection Sort Time: 5,233 ns
    - Serial Insertion Sort Time: 7,125 ns
    - Serial Counting Sort Time: 35,799 ns

  ... *(and so forth for larger array sizes)*

  </details>

  ### C++ Implementation *(Coming Soon)*

  The C++ version of the sorting algorithms will be introduced to further explore performance optimizations in parallel programming. This version will:
  - Use **XMake** as the build system.
  - Include similar serial and parallel sorting algorithms for direct comparison with the Java implementation.
  - Measure performance across varying data sizes to compare the efficiency of C++ vs. Java in parallel sorting tasks.

  ### Future Directions

  1. **Cross-Language Comparison**: After the C++ implementation, we’ll analyze and compare performance results across Java and C++. This will provide insights into how language and runtime differences affect parallel algorithm performance.
  2. **Scalability Testing**: With larger data sets, we aim to observe how the algorithms perform under increasing workloads and determine the break-even points for parallelization benefits.

  ## Running the Java Code

  To run the Java implementation:
  1. **Compile** the Java files: `javac *.java`
  2. **Run the main class**: `java MainClass`
  3. View the benchmark output in the console, as shown in the sample results above.

  ## Running the C++ Code *(Planned)*

  For the upcoming C++ code:
  1. Clone the repository and install **XMake** if necessary.
  2. Compile and execute the program using:
     ```bash
     xmake
     xmake run
     ```

</details>
