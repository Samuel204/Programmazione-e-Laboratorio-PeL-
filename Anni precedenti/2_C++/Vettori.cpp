#include <iostream>
#include <vector> //una delle classi containers


void stamp(std::vector<int> v); //passagio per copia

void stamp2(std::vector<int>& v){//passaggio per refecerence
    v.at(0) = 0;
}


int main() {
    /*int v[30]; // lecito con dei però, è deprecato(non fa controlli di range)*/
    /*v[h] = 4 //non fa controlli di range */
    int d; // la size che mi dice quanti sono gli elementi

    std::vector<int> v = {3,5,2,6}; //sto dichiarando un vector di interi
    std::vector<double> v2(50,3.14); //ho 50 double e valgono tutti 3.14, se non viene specifitcato vengono inizializz a 0
    std::vector<int> v3(v); //costruzione per copia, v3 sarà un array di una copia di v

    //accedere agli elementi
    /*v.at(h) = 4 //il controllo viene fatto(restituisce una reference)*/

    /*v.push_back(elemento) //viene copiato in coda all vttore, eggiungo elementi all array*/
    std::vector<int> a (100); //
    a.push_back(30); //la capacity vale 101
    //la size è <= della capacity



    //versione C
    /*int *v1 = (int*) malloc(sizeof(int)*7);
    int *v2 = (int*) malloc(sizeof(int)*7);
    v2 = v1 // ho generato garbage*/

    //versione C++
    /*std::vector<int> v1 = {3,5,2,3};
    std::vector<int> v2;
    v2 = v1 // copio tutti gli elementi di v2*/


    return 0;
}
