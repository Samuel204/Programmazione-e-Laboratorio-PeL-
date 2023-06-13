//Scrivi una funzione che elimina gli elementi ripetuti consecutivamente di una lista lasciandone una sola copia. Per esempio la lista:
//3 4 4 4 5 3 3 3 3 1
//viene modificata in 3 4 5 3 1

#include <iostream>

struct Cella{
    int info;
    struct Cella* next;
};


typedef struct Cella* Lista;


//aggiunta in testa alla lista
void prepend(Lista& lista, int x) {
    Lista nuovo = new Cella;
    nuovo->info = x;
    nuovo->next = lista;
    lista = nuovo;
}

//aggiunta in coda alla lista
void append(Lista& l, int data) {
    if (!l)
        l = new Cella{data, nullptr};
    else append(l->next, data);
}

//stampa lista
void stampa_lista(Lista l) {
    if (l) {
        std::cout<<l->info<<std::endl;
        stampa_lista(l->next);
    }
}

//distruggi lista
void distruggi(Lista& l) {
    Lista supp;
    while(l) {
        supp = l;
        l = l->next;
        delete supp;
    }
}

void leggi(Lista& l) {
    distruggi(l);
    int elem;
    std::cin>>elem;

    while (elem > 0) {
        int e;
        std::cin >> e;
        append(l, e);
        elem--;
    }
}
void elimina_dup(Lista& l){

    if(l == nullptr)return;

    Lista temp = l;
    Lista temp2;

    while (temp != nullptr && temp->next != nullptr){
        
        if (temp->info == temp->next->info) {
            temp2 = temp->next->next;
            temp->next = temp2;
        }
        temp = temp->next;
    }
    


}
int main() {
    Lista l = nullptr;
    leggi(l);
    elimina_dup(l);
    std::cout<<"Nuova lista"<<std::endl;
    stampa_lista(l);
    distruggi(l);
    return 0;
}