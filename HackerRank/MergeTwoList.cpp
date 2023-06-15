#include<iostream>

//Date due liste di interi ordinate, l1 e l2, si vuole creare una nuova lista senza modificare l1 e l2
//che sia ordinata e contenga tutti gli elementi di l1 e l2.
//Questa operazione si chiama merge. Attenzione: le liste l1 e l2 non vanno modificate in alcun modo.
//Non utilizzate altre strutture dati che non siano liste semplici con i tipi presentati nell'esercizio.


struct Cell{
    int info;
    Cell* next;
};

typedef Cell* List;

void append(List& l, int elem) {
    if (l==nullptr) {
        l = new Cell{elem, nullptr};
    }
    else
        append(l->next, elem);
}


void readlist(List& l) {
    int q, e;

    std::cin>>q;

    while (q>0) {
        std::cin>>e;
        append(l, e);
        q--;
    }
}

void destroy(List& l) {
    if (l) {
        destroy(l->next);
        delete l;
        l=nullptr;
    }
}


void printlist(List l) {
    if (l) {
        std::cout<<l->info<<std::endl;
        printlist(l->next);
    }
}


List merge(List l1, List l2) {

    List l3= nullptr;

    while (l1 != nullptr && l2 != nullptr){
        if(l1->info <= l2->info){
            append(l3,l1->info);
            l1 = l1->next;
        }else if(l2->info < l1->info){
            append(l3, l2->info);
            l2 = l2->next;
        }
    }

    //controllo casi singoli
    while (l1 != nullptr){
        append(l3, l1->info);
        l1 = l1->next;
    }

    while (l2 != nullptr){
        append(l3, l2->info);
        l2 = l2->next;
    }

    return l3;

}

int main() {
    List l1{nullptr}, l2{nullptr}, l3;

    readlist(l1);
    readlist(l2);

    l3 = merge(l1, l2);
    std::cout<<"L1:"<<std::endl;
    printlist(l1);
    std::cout<<"L2:"<<std::endl;
    printlist(l2);
    std::cout<<"L3:"<<std::endl;
    printlist(l3);

    destroy(l1);
    destroy(l2);
    destroy(l3);

    return 0;

}