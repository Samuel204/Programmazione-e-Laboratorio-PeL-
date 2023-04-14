#include <iostream>


struct TCella{
    int info;
    TCella* next;
};

typedef TCella* Tlist;

//ricerca di un elemento in una lista

bool presente(Tlist l,int elem){
    if(l == nullptr){
        return false;
    }else{
        return (l->info == elem) || presente(l->next,elem);
    }

}

Tlist presente_1(Tlist l, int elem){
    if(l == nullptr){
        return nullptr;
    }else{
        if(l->info == elem){//funzione alternatia di pl
            return l;
        }else{
            return presente_1(l->next,elem);
        }
    }

    /*Tlist pl = presente_1(l->next,elem);
    if(pl == nullptr){
        if(l->info == elem){
            return l;
        }else{
            return nullptr;
        }
    }else{
        return pl;
    }*/
}

void stampa_l(Tlist l){
    if(l != nullptr){
        std::cout << l->info << std::endl;
        stampa_l(l->next);
    }
}

void stampa_rev(Tlist l) {//2 5 7 9 stampa 9 7 5
    if(l != nullptr){
        stampa_rev(l->next);
        std::cout << l->info << std::endl;
    }

}


int main() {


    return 0;
}
