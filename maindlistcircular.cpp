#include <iostream>
#include "DListCircularRecursiva.h"
using namespace std;

int main(){
    DListCircular lista, lista2;

    lista.push_back(2);
    lista.push_back(1);
    lista.show();
    lista2.show();
//    lista2.push_back(2);
//    lista2.push_back(1);
//    lista2.push_back(3);
    //    lista2.show();
    //    lista.show();
    lista2.clone(lista);
    lista.show();
    // lista.reverse_print();

    lista2.show();
//    cout << "Front: " <<lista.front()->value << endl;
//    cout << "Back: " << lista.back()->value << endl;

//    cout << "Empty: " << lista.is_empty() << endl;

//    cout << "Find: " << lista.find(1)->value << endl;

//    cout << "Size: " << lista.size() << endl;

//    cout << "Equals: " << lista.equals(lista2) << endl;

    return 0;
}
