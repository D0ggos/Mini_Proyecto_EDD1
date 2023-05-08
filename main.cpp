#include <bits/stdc++.h>
#include "ListArrLinked.h"

int main(){

    ListArrLinked list(2);

    list.nuevo_nodo(list.raiz);
    list.nuevo_nodo(list.raiz);
    list.nuevo_nodo(list.raiz);
    list.nuevo_nodo(list.raiz);
    list.nuevo_nodo(list.raiz);
    cout << list.raiz->b << "\n";

    list.insert_left(3);
    list.insert_left(1);
    list.insert_left(2);
    list.insert_left(4);
    list.insert_left(5);
    list.insert(20, 3);

    list.print();
    cout<<"\n";

    cout << list.size() << "\n";

    return 0;
}