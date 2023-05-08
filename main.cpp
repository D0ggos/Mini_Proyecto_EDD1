#include <bits/stdc++.h>
#include "ListArrLinked.h"

int main(){

    int x;

    ListArrLinked list(6);

    list.nuevo_nodo(list.raiz);
    
    cout << list.raiz->b << "\n";

    list.insert_left(3);
    list.insert_left(1);
    list.insert_left(2);
    list.insert_left(4);
    list.insert_left(5);
    list.insert_right(6);
    list.insert_left(7);
    x=list.delete_right();
   
    

    cout << "Se encuentra el valor 2 en la lista? " << (list.find(2) ? "Si" : "No") << endl; // Imprime Sí
    cout << "Se encuentra el valor 4 en la lista? " << (list.find(4) ? "Si" : "No") << endl; // Imprime No

    list.print();
    cout<<"\n";
    cout<<"eliminado:"<<x<<endl;

    cout << list.size() << "\n";

    return 0;
}