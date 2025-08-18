#include <iostream>
#include <cstdlib>

using namespace std;

// Variáveis globais
int global_init = 10;      // global inicializada
int global_uninit;         // global não inicializada

int main() {
    // Stack
    int local_var = 20;

    // Heap
    int *heap_var = new int(30);

    // Código (endereço de uma função)
    cout << "Endereço de código (função main): " << (void*)main << endl;

    // Globais
    cout << "Endereço global inicializada: " << (void*)&global_init << endl;
    cout << "Endereço global não inicializada: " << (void*)&global_uninit << endl;

    // Heap
    cout << "Endereço no heap: " << (void*)heap_var << endl;

    // Stack
    cout << "Endereço no stack: " << (void*)&local_var << endl;

    delete heap_var;
    return 0;
}
