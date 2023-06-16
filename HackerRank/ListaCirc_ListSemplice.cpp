#include <iostream>
#include <string>

using namespace std;

/*
 * Data una lista circolare, scrivere la funzione decircle che la
trasforma in una lista semplice. Se p è il puntatore
all'elemento di riferimento della lista circolare (cioè quello
che usiamo per accedervi) allora p deve puntare al primo
elemento della lista semplice. Attenzione: non si devono
duplicare gli elementi (quindi non usare new e delete per
risolvere Ivesercizio).
 */


struct Cell{
    int info;
    Cell* next;
};

typedef Cell* List;

void addcircular(List& l, int elem) {
    if (l==nullptr) {
        l = new Cell;
        l->info = elem;
        l->next = l;
    }
    else {
        List nuova = new Cell{elem, l->next};
        l->next = nuova;
    }
}



List read_input() {
    int q;
    int el;

    List res = nullptr;

    std::cin >> q;

    while (q>0) {
        std::cin >> el;
        addcircular(res, el);
        q--;
    }

    return res;
}



void print(List l) {
    if (l) {
        std::cout<<l->info << " ";
        print(l->next);
    }
    else
        std::cout<<std::endl;
}


void destroy(List& l) {
    if (l) {
        destroy(l->next);
        delete l;
        l=nullptr;
    }
}



void linearize(List& l) {

    List pc=l;

    if(l == nullptr)return;

    while (l != nullptr){
        if(pc->next == l){
            pc->next = nullptr;
        }
        l= l->next;
    }
}



int main() {

    List l = read_input();

    linearize(l);

    print(l);

    destroy(l);


    return 0;
}
