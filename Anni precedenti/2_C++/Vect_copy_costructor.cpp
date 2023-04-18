#include <iostream>

struct Vettore{
    int capacity;
    int size;
    int * vet;

    Vettore(){
        std::cout <<"Costruttore"<<std::endl;
        capacity = 100;
        size =0;
        vet = new int(capacity);
    }

    Vettore(int dim, int val){//sto facendo un overloading
        std::cout << "Fill Costruttore" << std::endl;
        capacity = 2*dim;
        vet = new int[capacity];
        size = dim;
        for(int i=0; i < dim; i++){
            vet[i] = val;
        }
    }

    ~Vettore(){
        std::cout<< "Distruttore" <<std::endl;
        delete[] vet;
    }

    Vettore(const Vettore& copy){ //copy constructur
        std::cout <<"Costruttore di copia"<<std::endl;
        capacity = copy.capacity;
        size = copy.size;

        vet = new int[capacity];

        for(int i=0; i < size; i++){
            vet[i] = copy.vet[i];
        }

    }

    void resize(int newsize){
        if(newsize >= 0) {
            if (newsize <= capacity) {
                size = newsize;
            } else {
                int *pc = new int[newsize];
                for (int i = 0; i < size; i++) {
                    pc[i] = vet[i];
                }
                delete[] vet;
                vet = pc;
                capacity = newsize;
            }
        }
    }

    void stampa()const{//ogni volta che viene chiamato quel oggetto non viene cambiato il contenuto
        for(int i=0; i < size; i++){
            std::cout << vet[i] <<std::endl;
        }
    } //distruttore interviene

    int& at(int pos){
        if(pos < size && pos >= 0){
            return vet[pos];
        }else{
            return vet[0]; // bruttissimo! usare le eccezioni quando le avete imparate
        }

    }

    const int& at(int pos)const{//overloading
        if(pos < size && pos >= 0){
            return vet[pos];
        }else{
            return vet[0]; // bruttissimo! usare le eccezioni quando le avete imparate
        }

    }
};

void foo(const Vettore& x){//il metodo stampa non modifica  lo stato dell oggetto e puo essere modificato
    x.stampa();
    //const reference possono stare a destra di un assegnamento
}

int main() {
    Vettore a;//parametro effettivo //costruttore
    a.size=2;
    a.vet[0] = 23;
    a.vet[1] = 33;
    //stampa(a); //costruttore copia
    a.vet[1] = 0;

    Vettore b = a; //copy constructor

    foo(a);

    Vettore c{20,4};
    foo(c);
    return 0;
}
