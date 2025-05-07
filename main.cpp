#include "Triangulo.h"

int main(){
    Triangulo T1(5), T2(5), T3;
    T3 = T1 + T2 - (T1 * T2);
    
    cout << "T1:\n" << T1 << endl;
    cout << "T2:\n" << T2 << endl;
    cout << "T3:\n" << T3 << endl;
}

