#include <iostream>

//Data una lista circolare acquisita da standard input, si vuole scrivere una funzione che rimuova tutte
//le occorrenze di un particolare elemento.
//Il puntatore alla lista deve essere cambiato solo se punta ad un elemento che va rimosso e
//in questo caso punterà al primo elemento successivo non rimosso
//(o a nullptr se saranno rimossi tutti gli elementi). L'ordine degli elementi della lista
//non devono essere cambiati.

struct Cella_circ{
    int info;
    struct Cella_circ* next;
};


typedef Cella_circ* Lista_circ;


void add(Lista_circ& lista, int x) {
    Lista_circ nuovo = new Cella_circ;
    nuovo->info = x;
    if (lista==nullptr) {
        nuovo->next = nuovo;
        lista = nuovo;
    }
    else {
        nuovo->next = lista->next;
        lista->next = nuovo;
    }
}

//stampa lista
void stampa_lista(Lista_circ l) {
    if (l) {
        Lista_circ pc{l};
        do {
            std::cout<<l->info << " ";
            l=l->next;
        } while (l!=pc);
    }
    std::cout<<std::endl;
}

//distruggi lista
void distruggi(Lista_circ& l) {
    if (l) {
        Lista_circ supp, sentinella{l};
        do {
            supp = l;
            l=l->next;
            delete supp;
        } while (l!=sentinella);
        l = nullptr;
    }
}


//leggi lista
void leggi_lista(Lista_circ& l) {
    int elem, n;
    std::cin>>n;
    while (n>0) {
        std::cin>>elem;
        add(l, elem);
        n--;
    }
}

void rimuovi_occore(Lista_circ& l, int elem){

    if(l){
        Lista_circ pc = l;
        Lista_circ old = pc;

        pc = pc->next;
        Lista_circ temp;//per eliminare la lista corrente

        while (l != pc){
            if(pc->info == elem){
                temp = pc;
                old->next = old->next->next;//salta la lista e va a quello successivo
                pc = pc->next;
                l = l->next->next;//perche ho eliminato la lista precedente
                delete temp;
            }else{
                pc = pc->next;
                old = old->next;
                l = l->next;
            }
        }
    }
}


int main() {
    int elimina;
    Lista_circ l=nullptr;

    leggi_lista(l);
    std::cin>>elimina;

    std::cout<<"Prima: ";
    stampa_lista(l);

    rimuovi_occore(l, elimina);

    std::cout<<"Dopo: ";
    stampa_lista(l);


    distruggi(l);
    return 0;
}