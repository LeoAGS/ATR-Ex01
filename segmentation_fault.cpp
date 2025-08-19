#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    //ERRO DE SEGMENTAÇÃO GARANTIDO
    cout << "Forçando segmentation fault com ponteiro nulo..." << endl;
    int *ptr = nullptr;
    cout << *ptr << endl; // Aqui vai falhar!

    return 0;
}
