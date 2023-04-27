#include<bits/stdc++.h> //Biblioteca donde se encuentra la función cout
#include "ListArr.h"
using namespace std;

class Nodo {
public:
    int* arr;
    int b;//tamano de los arreglos dentro de los nodos
    int n;//cantidad de elementos almacenados
    Nodo* next;
    Nodo(int b);
};


class ListArrLinked : public ListArr{
    public:
        Nodo* head;
        Nodo* tail;
        int n;
        int b;
        ListArrLinked(int b);
        int size();
        void insert_left(int v);
        void insert_right(int v);
        void insert(int v, int i);
        void print();
        bool find(int v);
};


