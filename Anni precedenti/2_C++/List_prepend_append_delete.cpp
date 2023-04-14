#include <iostream>

struct TCella{
    int info;
    TCella* next;
};

typedef TCella* Tlist;

//creazione lista vuota,prepend, append,

//lista vuota
Tlist crea(){
    return nullptr;
}


//prepend (aggiungere un elemento in testa)
void prepend(Tlist& t, int elem){
    Tlist nuova;
    nuova = new TCella;
    nuova->info = elem;
    nuova->next = t;
    t = nuova;

}

//append (aggiungere in coda)iteraiva //(se lo eseguo sulla lista vuota va in segmentation foult)
void append(Tlist& t, int elem){

    if(t != nullptr) {
        Tlist pc = t;
        while (pc->next != nullptr) {
            pc = pc->next;
        }
        pc->next = new TCella;
        pc->next = nullptr;
        pc->next->info = elem;
    }else{
        prepend(t,elem);
    }
}

//append (aggiungere in coda)ricorsiva
void ric_append(Tlist& t, int elem){
    if(t == nullptr){
        prepend(t,elem);
    }else{
        ric_append(t->next,elem);
    }

}

//distruggere una lista ricorsiva
void ric_distruggi(Tlist& t){
    if(t!= nullptr){
        ric_distruggi(t->next);
        delete t;
        t = nullptr;
    }
}

int main() {
    Tlist l;
    l = crea();
    prepend(l,4);
    std::cout << l ;


    return 0;
}
