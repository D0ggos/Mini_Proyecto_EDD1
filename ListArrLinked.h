#include<bits/stdc++.h>
#include "ListArr.h"
using namespace std;

struct Nodo {
    int* ar;
    int b;
    int n;
    bool esResumen;
    Nodo* tail;
    Nodo* izq;
    Nodo* der;
    Nodo(int b);
};


class ListArrLinked : public ListArr{

    public:
        Nodo* raiz;
        int n;
        int b;
        ListArrLinked(int b);
        int size();
        void insert_left(int v);
        void insert_left(int v, Nodo* nodo);
        void insert_right(int v);
        void insert_right(int v, Nodo* nodo);
        void insert(int v, int i, Nodo* nodo);
        void insert(int v, int i);
        void print();
        void print_hojas(Nodo* nodo);
        bool find(int v);
        bool find(int v, Nodo* nodo_actual);
        void actualizar_resumenes(Nodo* nodo);
        void nuevo_nodo(Nodo*& raiz);
};


