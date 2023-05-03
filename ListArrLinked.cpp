#include <bits/stdc++.h>
#include "ListArrLinked.h"

using namespace std; 

Nodo::Nodo(int b){

    this->ar = new int[b];
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

    if (this->head == nullptr || this->head->n == this->b){

            Nodo* new_head = new Nodo(this->b);
            new_head->next = this->head;
            this->head = new_head;

            if (this->tail == nullptr){
                this->tail = this->head;
            }
        }

    this->head->ar[this->head->n] = v;
    this->head->n++;
    this->n++;
}

void ListArrLinked::insert_right(int v){

    if (this->tail == nullptr || this->tail->n == this->b){

        Nodo* new_tail = new Nodo(this->b);

        if (this->tail != nullptr){
            this->tail->next = new_tail;
        }

        this->tail = new_tail;

        if (this->head == nullptr){
            this->head = this->tail;
        }
    }

    this->tail->ar[this->tail->n] = v;
    this->tail->n++;
    this->n++;
}

void ListArrLinked::insert(int v, int i){

    if (i < 0 || i > this->n){
        throw out_of_range("El índice donde se quiere insertar el elemento no existe");
    }
    
    if (i == 0){
        this->insert_left(v);
    } 

    else if (i == this->n){
        this->insert_right(v);
    } 

    else{

        int j = i / this->b;
        Nodo* curr = this->head;

        while (j > 0){
            curr = curr->next;
            j--;
        }

        int k = i % this->b;
        for (int l = curr->n - 1; l >= k; l--){
            curr->ar[l+1] = curr->ar[l];
        }

        curr->ar[k] = v;
        curr->n++;
        this->n++;
    }
}

void ListArrLinked::print(){

    Nodo* curr = this->head;

    while (curr != nullptr){
        for (int i = 0; i < curr->n; i++){
            cout << curr->ar[i] << " ";
        }
        curr = curr->next;
    }

    cout << endl;
}

bool ListArrLinked::find(int v){

    Nodo* curr = this->head;

    while (curr != nullptr) {
        for (int i = 0; i < curr->n; i++) {
            if (curr->ar[i] == v) {
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}