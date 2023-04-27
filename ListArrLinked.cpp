#include<bits/stdc++.h> //Biblioteca donde se encuentra la función cout
#include "ListArrLinked.h"
using namespace std;  //uso del espacio de nombre 

Nodo::Nodo(int b){
    this->arr = new int[b];
    this->b = b;
    this->n = 0;
    this->next = nullptr;
}

ListArrLinked::ListArrLinked(int b){
    this->head = nullptr;
    this->tail = nullptr;
    this->n = 0;
    this->b = b;
}

int ListArrLinked::size(){
    return this->n;
}

void ListArrLinked::insert_left(int v){
    if (this->head == nullptr || this->head->n == this->b) {
            Nodo* new_head = new Nodo(this->b);
            new_head->next = this->head;
            this->head = new_head;
            if (this->tail == nullptr) {
                this->tail = this->head;
            }
        }
        this->head->arr[this->head->n] = v;
        this->head->n++;
        this->n++;
}

void ListArrLinked::insert_right(int v){
    if (this->tail == nullptr || this->tail->n == this->b) {
        Nodo* new_tail = new Nodo(this->b);
        if (this->tail != nullptr) {
            this->tail->next = new_tail;
        }
        this->tail = new_tail;
        if (this->head == nullptr) {
            this->head = this->tail;
        }
    }
    this->tail->arr[this->tail->n] = v;
    this->tail->n++;
    this->n++;
}

void ListArrLinked::insert(int v, int i){
    if (i < 0 || i > this->n) {
        throw std::out_of_range("Índice fuera de rango");
    }
    if (i == 0) {
        this->insert_left(v);
    } else if (i == this->n) {
        this->insert_right(v);
    } else {
        int j = i / this->b;
        Nodo* curr = this->head;
        while (j > 0) {
            curr = curr->next;
            j--;
        }
        int k = i % this->b;
        for (int l = curr->n - 1; l >= k; l--) {
            curr->arr[l+1] = curr->arr[l];
        }
        curr->arr[k] = v;
        curr->n++;
        this->n++;
    }
}

void ListArrLinked::print(){
    Nodo* curr = this->head;
    while (curr != nullptr) {
        for (int i = 0; i < curr->n; i++) {
            std::cout << curr->arr[i] << " ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

bool ListArrLinked::find(int v){
    Nodo* curr = this->head;
    while (curr != nullptr) {
        for (int i = 0; i < curr->n; i++) {
            if (curr->arr[i] == v) {
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}


int main(){
    ListArrLinked list = ListArrLinked(3); // Crea una lista con arreglo de tamaño 3
    list.insert(1, 0); // Inserta 1 en el índice 0
    list.insert(2, 1); // Inserta 2 en el índice 1
    list.insert(3, 2); // Inserta 3 en el índice 2
    list.insert(4, 3); // Inserta 4 en el índice 3 (fuera de rango)

    cout << "Tamano de la lista: " << list.size() << endl; // Imprime 3

    list.print(); // Imprime 1 2 3

    cout << "Se encuentra el valor 2 en la lista? " << (list.find(2) ? "Si" : "No") << endl; // Imprime Sí
    cout << "Se encuentra el valor 4 en la lista? " << (list.find(4) ? "Si" : "No") << endl; // Imprime No

    list.insert_left(0); // Inserta 0 a la izquierda de la lista
    list.insert_right(4); // Inserta 4 a la derecha de la lista

    list.print(); // Imprime 0 1 2 3 4

    return 0;
}