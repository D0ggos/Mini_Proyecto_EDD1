#include <bits/stdc++.h>
#include "ListArrLinked.h"

using namespace std; 

Nodo::Nodo(int b){

    this->ar = new int[b];
    this->b = b;
    this->n = 0;
    this->tail = nullptr;
    this->der = nullptr;
    this->izq = nullptr;
    bool esResumen = false;
}


ListArrLinked::ListArrLinked(int b){

    this->raiz = nullptr;
    this->n = 0;
    this->b = b;

}


void ListArrLinked::actualizar_resumenes(Nodo* nodo){

    if (nodo == nullptr){return;}

    if (nodo->izq != nullptr && nodo->der != nullptr){
        actualizar_resumenes(nodo->izq);
        actualizar_resumenes(nodo->der);
        nodo->n = nodo->izq->n + nodo->der->n;
        nodo->b = nodo->izq->b + nodo->der->b;
    }
}


void ListArrLinked::nuevo_nodo(Nodo*& raiz){

    Nodo* nuevo_nodo = new Nodo(this->b);

    if (raiz == nullptr){
        raiz = nuevo_nodo;
        return;
    }

    queue<Nodo*> por_procesar;
    por_procesar.push(raiz);

    while (!por_procesar.empty()){
        Nodo* actual = por_procesar.front();
        por_procesar.pop();

        if (actual->der != nullptr && actual->izq != nullptr){
            por_procesar.push(actual->izq);
            por_procesar.push(actual->der);
        }
        else {
            if (actual->izq == nullptr){
                actual->izq = nuevo_nodo;
                nuevo_nodo->tail = actual;
            }
            else{
                actual->der = nuevo_nodo;
                nuevo_nodo->tail = actual;
            }
            break;
        }
    }
    actualizar_resumenes(this->raiz);
}


int ListArrLinked::size(){
    return raiz->n;
}


void ListArrLinked::insert_left(int v, Nodo* nodo_actual){
    
    if (nodo_actual->izq == nullptr){
        if (nodo_actual->b == nodo_actual->n){ // Si es que el arreglo del nodo está lleno

            nuevo_nodo(nodo_actual);
            nuevo_nodo(nodo_actual);

            for (int i = 0; i < b; i++){
                nodo_actual->der->ar[i] = nodo_actual->ar[i];
            }
            delete[] nodo_actual->ar;
            nodo_actual->der->n = this->b;
            nodo_actual->izq->ar[0] = v;
            nodo_actual->izq->n++;
        }

        else if (nodo_actual->n == 0){
            nodo_actual->ar[0] = v;
            nodo_actual->n++;
        }

        else if (nodo_actual->n < nodo_actual->b){
            for (int i = nodo_actual->n; i > 0; i--){
                nodo_actual->ar[i] = nodo_actual->ar[i-1];
            }
            nodo_actual->ar[0] = v;
            nodo_actual->n++;
        }
        actualizar_resumenes(this->raiz);
    }
    else if (nodo_actual->izq != nullptr && nodo_actual->der != nullptr){
        insert_left(v, nodo_actual->izq);
    }
}


void ListArrLinked::insert_left(int v){
    insert_left(v, this->raiz);
}


void ListArrLinked::insert_right(int v, Nodo* nodo_actual){
    
    if (nodo_actual->izq == nullptr){
        if (nodo_actual->b == nodo_actual->n){ // Si es que el arreglo del nodo está lleno

            nuevo_nodo(nodo_actual);
            nuevo_nodo(nodo_actual);

            for (int i = 0; i < b; i++){
                nodo_actual->izq->ar[i] = nodo_actual->ar[i];
            }
            delete[] nodo_actual->ar;
            nodo_actual->izq->n = this->b;
            nodo_actual->der->ar[0] = v;
            nodo_actual->der->n++;
        }

        else if (nodo_actual->n == 0){
            nodo_actual->ar[0] = v;
            nodo_actual->n++;
        }

        else if (nodo_actual->n < nodo_actual->b){
            for (int i = nodo_actual->n; i > 0; i--){
                nodo_actual->ar[i] = nodo_actual->ar[i-1];
            }
            nodo_actual->ar[0] = v;
            nodo_actual->n++;
        }
        actualizar_resumenes(this->raiz);
    }
    else if (nodo_actual->izq != nullptr && nodo_actual->der != nullptr){
        insert_right(v, nodo_actual->der);
    }
}


void ListArrLinked::insert_right(int v){
    insert_right(v, this->raiz);
}


void ListArrLinked::insert(int v, int i){

}


void ListArrLinked::print_hojas(Nodo* nodo){

    if (nodo != nullptr){
        if (nodo->izq == nullptr && nodo->der == nullptr){
            for (int i = 0; i < nodo->n; i++) {
                cout << nodo->ar[i] << " ";
            }
        } 
        else{
            print_hojas(nodo->izq);
            print_hojas(nodo->der);
        }
    }
}


void ListArrLinked::print(){

    if (raiz == nullptr){
        cout << "El árbol está vacio" << "\n";
        return; 
    }
    print_hojas(this->raiz);
}


bool ListArrLinked::find(int v){
    return true;
}