#include<bits/stdc++.h> //Biblioteca donde se encuentra la función cout
using namespace std;  //uso del espacio de nombre std

class ListArr{

public:
    virtual int size() = 0;
    virtual void insert_left(int v) = 0;
    virtual void insert_right(int v) = 0;
    virtual void insert(int v, int i) = 0;
    virtual void print() = 0;
    virtual bool find(int v) = 0;
};