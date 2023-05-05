#include <iostream>

using namespace std;

class Nodo {
public:
    int *ar;
    int b;
    int n;
    Nodo *next;
    Nodo(int b);
};

Nodo::Nodo(int b) {
    this->ar = new int[b];
    this->b = b;
    this->n = 0;
    this->next = nullptr;
}

class NodoResumen : public Nodo {
public:
    int cap_total;
    int n_total;
    NodoResumen(Nodo *nodo1, Nodo *nodo2);
};

NodoResumen::NodoResumen(Nodo *nodo1, Nodo *nodo2) : Nodo(0) {
    this->cap_total = nodo1->b + nodo2->b;
    this->n_total = nodo1->n + nodo2->n;
}

class ListArr {
public:
    int b;
    int n;
    Nodo *head;
    Nodo *tail;
    ListArr(int b);
    virtual int size() = 0;
    virtual void insert_left(int v) = 0;
    virtual void insert_right(int v) = 0;
    virtual void insert(int v, int i) = 0;
};

ListArr::ListArr(int b) {
    this->b = b;
    this->n = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

class ListArrLinked : public ListArr {
public:
    ListArrLinked(int b) : ListArr(b) {};
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int i);
};

int ListArrLinked::size() {
    return this->n;
}

void ListArrLinked::insert_left(int v) {
    if (this->head == nullptr || this->head->n == this->b) {
        Nodo *new_head = new Nodo(this->b);
        new_head->next = this->head;
        this->head = new_head;
        if (this->tail == nullptr) {
            this->tail = this->head;
        }
    }
    int j = 0 / this->b;
    Nodo *curr = this->head;
    while (j > 0) {
        curr = curr->next;
        j--;
    }
    int k = 0 % this->b;
    for (int l = curr->n - 1; l >= k; l--) {
        curr->ar[l + 1] = curr->ar[l];
    }
    curr->ar[k] = v;
    curr->n++;
    this->n++;
}

void ListArrLinked::insert_right(int v) {
    if (this->tail == nullptr || this->tail->n == this->b) {
        Nodo *new_tail = new Nodo(this->b);
        if (this->tail != nullptr) {
            this->tail->next = new_tail;
        }
        this->tail = new_tail;
        if (this->head == nullptr) {
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



int main(){
    ListArrLinked list = ListArrLinked(3); // Crea una lista con arreglo de tamaño 3
    list.insert(1, 0); // Inserta 1 en el índice 0
    list.insert(2, 1); // Inserta 2 en el índice 1
    list.insert(2, 1); // Inserta 2 en el índice 1
    list.insert(2, 1); // Inserta 2 en el índice 1
    list.insert(3, 2); // Inserta 3 en el índice 2


    cout << "Tamano de la lista: " << list.size() << endl; // Imprime 3

    list.print(); // Imprime 1 2 3

    cout << "Se encuentra el valor 2 en la lista? " << (list.find(2) ? "Si" : "No") << endl; // Imprime Sí
    cout << "Se encuentra el valor 4 en la lista? " << (list.find(4) ? "Si" : "No") << endl; // Imprime No

    list.insert_left(0);
    list.insert_left(0);
    list.insert_left(0);
    list.insert_left(0);
    list.insert_right(4);
    list.insert_right(5);
    list.insert_right(5);
    list.insert_right(5);
    list.insert_right(5);


    list.print(); // Imprime 0 1 2 3 4

    return 0;
}