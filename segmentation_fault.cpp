#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    //ERRO DE SEGMENTAÇÃO 
    cout << "Forçando segmentation fault com ponteiro nulo:" << endl;
    int *ptr = nullptr;
    cout << *ptr << endl; // falha

    return 0;
}
