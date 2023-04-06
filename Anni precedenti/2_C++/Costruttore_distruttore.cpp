#include <iostream>

//struct costruttore e distruttore
struct Prima{
    Prima(){
        std::cout << "Hey hai chiamato il costruttore "<<std::endl;
        a = 15;
        b = 20.3;
    }
    ~Prima(){
        std::cout <<"E io sono il distruttore " << std::endl;
    }
    int a;
    double b;
};

void stampa(Prima par){
    std::cout << par.a << " " <<par.b <<std::endl;
}

int main() {
    Prima x,y; // con una variabile y me l'ho crea due volte//dichiarazione e definizione
    /*std::cout << x.a << " " << x.b << std::endl;

    std::cout << "" <<std::endl;

    {
        std::cout<< "Entro nel bloco" <<std::endl;
        Prima* z;
        std::cout << "Ho dichiarato il puntatore"<<std::endl;
        z = new Prima;
        std::cout<<"Ho fatto la new" <<std::endl;
        delete z;
        std::cout<<"ho fatto la delete"<<std::endl;
    }
    std::cout << "Sto per terminare" <<std::endl;
    std::cout << "" <<std::endl;*/

    stampa(x);
    std::cout << "Sto per terminare" <<std::endl;
    return 0;
}
