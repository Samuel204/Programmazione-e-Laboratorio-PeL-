#include <iostream>

struct Prima{
    int a;
    double b;

    Prima(const Prima& copia){
        std::cout <<"Costruttore per copia" <<std::endl;
        a= copia.a;
        b = copia.a;
    }
};

int main() {
    /*Prima x, y;

    Prima z=x;//costruttor per copia Primaz{x} nome alternativo di x
    Prima* pz = new Prima(z); //Costruttore per copia quando inizializzo un oggetto e dico il valore iniziale*/


    return 0;
}
