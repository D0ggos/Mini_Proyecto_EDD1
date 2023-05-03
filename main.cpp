#include <bits/stdc++.h>
#include "ListArrLinked.h"

using namespace std;

int main(){
    
    ListArrLinked list = ListArrLinked(100);

    // Probamos con arreglos (b) de tamaño 100.


    // Función insert_left


   /*

   auto start1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++){

        list.insert_left(i+3);
    }

   auto stop1 = chrono::high_resolution_clock::now();
   auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);

   cout << duration1.count() << "\n";

   */

   // Tiempo de ejecución promedio con 10000 elementos (insert_left) = 333 milisegundos aproximadamente.

   /*

   auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++){

        list.insert_left(i+3);
    }

   auto stop2 = chrono::high_resolution_clock::now();
   auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);

   cout << duration2.count() << "\n";

   */

   // Tiempo de ejecución promedio con 100000 elementos (insert_left) = 3548 milisegundos aproximadamente.

   /*

   auto start3 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++){

        list.insert_left(i+3);
    }

   auto stop3 = chrono::high_resolution_clock::now();
   auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);

   cout << duration3.count() << "\n";

   */

   // Tiempo de ejecución promedio con 1000000 elementos (insert_left) = 24844 milisegundos aproximadamente.



    // 


   auto start4 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000; i++){

        list.insert_right(i+3);
    }

   auto stop4 = chrono::high_resolution_clock::now();
   auto duration4 = chrono::duration_cast<chrono::microseconds>(stop4 - start4);

   cout << duration4.count() << "\n";

   // Tiempo de ejecución promedio con 10000 elementos (insert_right) = 384 milisegundos aproximadamente.

    return 0;
}