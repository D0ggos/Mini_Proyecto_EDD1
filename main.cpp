#include <bits/stdc++.h>
#include "ListArrLinked.h"

using namespace std;

int main(){
    
    ListArrLinked list = ListArrLinked(100);

    // ###############################################################################
    // Función insert_left

/*
   auto start1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000; i++){
        list.insert_left(i+3);
    }

   auto stop1 = chrono::high_resolution_clock::now();
   auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);

   cout << duration1.count() << "\n";
   

   // Tiempo de ejecución promedio con 10000 elementos (b=1) = 2643 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 10000 elementos (b=100) = 333 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 10000 elementos (b=1024) = 339 milisegundos aproximadamente.
*/

/*  
   auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; i++){
        list.insert_left(i+3);
    }

   auto stop2 = chrono::high_resolution_clock::now();
   auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);

   cout << duration2.count() << "\n";
   

   // Tiempo de ejecución promedio con 100000 elementos (b=1) = 24434 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 100000 elementos (b=100) = 3548 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 100000 elementos (b=1024) = 3374 milisegundos aproximadamente.
*/

/*
    auto start3 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++){
        list.insert_left(i+3);
    }

    auto stop3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);

    cout << duration3.count() << "\n";
*/

   // Tiempo de ejecución promedio con 1000000 elementos (b=1) = 111380 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 1000000 elementos (b=100) = 24844 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 1000000 elementos (b=1024) = 22692 milisegundos aproximadamente.

    // ###############################################################################

    // Función insert_right 

/*
   auto start4 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000; i++){
        list.insert_right(i+3);
    }

   auto stop4 = chrono::high_resolution_clock::now();
   auto duration4 = chrono::duration_cast<chrono::microseconds>(stop4 - start4);

   cout << duration4.count() << "\n";
*/

   // Tiempo de ejecución promedio con 10000 elementos (b=1) = 2934 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 10000 elementos (b=100) = 384 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 10000 elementos (b=1024) =  348 milisegundos aproximadamente.

/*
   auto start5 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; i++){
        list.insert_right(i+3);
    }

   auto stop5 = chrono::high_resolution_clock::now();
   auto duration5 = chrono::duration_cast<chrono::microseconds>(stop5 - start5);

   cout << duration5.count() << "\n";
*/

   // Tiempo de ejecución promedio con 100000 elementos (b=1) = 21562 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 100000 elementos (b=100) = 3680 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 100000 elementos (b=1024) = 3419 milisegundos aproximadamente.

/*
   auto start6 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++){
        list.insert_right(i+3);
    }

   auto stop6 = chrono::high_resolution_clock::now();
   auto duration6 = chrono::duration_cast<chrono::microseconds>(stop6 - start6);

   cout << duration6.count() << "\n";
*/

   // Tiempo de ejecución promedio con 1000000 elementos (b=1) = 113369 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 1000000 elementos (b=100) = 25891 milisegundos aproximadamente.
   // Tiempo de ejecución promedio con 1000000 elementos (b=1024) = 23510 milisegundos aproximadamente.



    // ###############################################################################

    // Función find


    return 0;
}