#include <iostream>

//Lista cicolare
struct Cella{
    int info;
    Cella* next;
};

typedef Cella* ListC;

void add(ListC& l, int info){
    ListC pnuova = new Cella;
    pnuova->info = info;
    pnuova->next = l->next;
    l->next = pnuova;
}

/*void add(ListC& l, int info){
    ListC pnuova = new Cella;
    pnuova->info = info;
    if(l != nullptr) {
        pnuova->next = l->next;
        l->next = pnuova;
    }else{
        pnuova->next = pnuova;
        l = pnuova;
    }
}*/

//scorrimento lista, questa funzione per le lista circolari ma SOLO per le liste normali
/*void print(ListC l){
    if(l){
        std::cout<<l->info;
        print(l->next);
    }
}*/

//scorrimento lista circolare
void print(ListC l){
    if(l){
        ListC p = l;
        do{
            std::cout <<l->info << std::endl;
            l = l->next;
        }while(l != p);//un tipo di dato è un insieme di operazioni che viene dato
    }
}

//rimozione di un elemento
bool elimina(ListC l, int elem){

}


int main() {


    return 0;
}
