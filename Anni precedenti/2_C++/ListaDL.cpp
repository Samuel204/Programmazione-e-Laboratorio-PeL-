#include <iostream>

struct CellaDl{
    int info;
    CellaDl* prev;
    CellaDl* next;
};
//la ListaDl vuote sono codificate da 2 puntatori nullptr
typedef CellaDl* ListaDL; //puntatore alla cella

void prepend(ListaDL& head, ListaDL& tail, int elem){
    ListaDL pcell = new CellaDl; // creo una nuova cella
    pcell->prev = nullptr;
    pcell->info = elem;
    pcell->next= head;

    if(head != nullptr){
        head->prev= pcell;
    }else{
        tail = pcell;
    }
    head = pcell; //inserimento in testa
}

void append(ListaDL& head, ListaDL& tail, int elem);//identica alla prepend il ruolo di head e tail sono scambiati
//specchio della prepend con head<-> tail e succ <->next

void insert(ListaDL& head, ListaDL& tail, int pos, int elem){
    if(pos > 0 && head != nullptr){
        insert(head->next,tail,pos-1,elem);
    }else if(pos == 0){
        ListaDL pcell = new CellaDl;
        pcell->info= elem;
        pcell->info = elem;
        if(head != nullptr){
            pcell->prev = head->prev;
            head->prev = pcell;
        }else{
            pcell->prev = tail;
            tail = pcell;
        }
        pcell->next = head;
        head = pcell;
    }
}

//distruzione lista doppiamente concatenata
void distruggi(ListaDL& head, ListaDL& tail){
    while(head){
        ListaDL pc = head;
        head = head->next;
        delete pc;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {


    return 0;
}
