#include <iostream>
#include <vector>

using std::vector;

int main() {
    /*double x;

    double* px = &x;
    *px = 3.14;

    *px = 7.2;
    std::cout << "px=" <<" " << px << std::endl;
    std::cout<<  x << std::endl;*/


    /**************************/
    /*int vet[40];
    int *pv;
    vet[0] = 5;
    pv = vet; // &vet[0] non è un puntatore ma un indirizzo di memoria
    //vet = pv; //errore

    for(pv=vet; pv < vet+40; pv++){ //sommo a un indirizzo di memoria con un intero e il risultato è
        std::cout << *pv << std::endl;
    }*/

    /*****************************/

    vector<int> v{1,3,2,5,7,8};
    vector<int>::iterator it;

    for(it=v.begin(); it != v.end(); it++){
        std::cout << *it << std::endl; //dereferenziare un iteratore è accedere all elemento
    }

    int somma=0;
    for(it=v.begin(); it != v.end(); it++){
        somma += (*it - *(it+1) * (*it - *(it+1)));
    }//il vettore non deve essere modificatore in struttura durante il suo scorrimento come pusk_back o pop_back


    return 0;
}
