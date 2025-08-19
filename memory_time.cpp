#include <iostream>
#include <chrono>
#include <unistd.h> 

using namespace std;

int main() {
    const long N = 10000000;

    // 'volatile' para evitar que o compilador otimize o loop de atribuição.
    volatile int a = 0;

    // --- Medindo o tempo de atribuição ---
    auto inicio_atribuicao = chrono::high_resolution_clock::now();
    for (long i = 0; i < N; ++i) {
        a = 1 + 2;
    }
    auto fim_atribuicao = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao_atribuicao = fim_atribuicao - inicio_atribuicao;
    double tempo_medio_atribuicao = duracao_atribuicao.count() / N;

    cout << "Tempo médio de uma atribuição: "
         << tempo_medio_atribuicao * 1e9 // em nanosegundos (10^9)
         << " ns" << endl;

    // --- Medindo o tempo de chamada ao sistema (write) ---
    const char msg = 'x'; // Caractere a ser escrito
    auto inicio_write = chrono::high_resolution_clock::now();
    for (long i = 0; i < N; ++i) {
        ssize_t bytes = write(STDERR_FILENO, &msg, 1);
        (void)bytes; 
    }

    auto fim_write = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao_write = fim_write - inicio_write;
    double tempo_medio_write = duracao_write.count() / N;

    cout << "\nTempo médio de uma chamada ao sistema (write): "
         << tempo_medio_write * 1e6 // em microssegundos (10^6)
         << " µs" << endl;

    // --- Calculando e imprimindo a razão entre os tempos ---
    double razao = tempo_medio_write / tempo_medio_atribuicao;
    cout << "\nUma chamada de sistema (write) leva o mesmo tempo que "
         << fixed << razao << " atribuições." << endl;

    return 0;
}
