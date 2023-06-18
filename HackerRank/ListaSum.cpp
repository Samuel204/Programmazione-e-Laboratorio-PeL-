#include <iostream>


/*Data una lista di interi (possibilmente negativi), una somma sum e un numero di addendi add, scrivere una
funzione ricorsiva che ritorni true se è possibile sommare add addendi della lista per formare la somma sum.
Per esempio, consideriamo la lista [1,2,3,4,5 ]e supponiamo sum=9. Se add=0 o 1 allora la risposta è false, se add=2
allora la risposta è true (5+4), se add=3 la risposta è true (4+3+2), per tutti gli altri valori di add, la risposta è false.
La somma di 0 addendi è sempre pari a 0 (in particolare, sum=0 e add=0 deve restituire true).
Non creare funzioni ausiliarie. Suggerimento: ogni elemento della lista può partecipare
alla somma oppure no. Pertanto, considerato l'elemento di testa la somma sarà formabile se si trova una soluzione
includendolo oppure se si trova una soluzione escludendolo...
 * */


struct Cella{
    int info;
    Cella* next;
};

typedef Cella* Lista;

void append(Lista& l, int elem) {
    if (l==nullptr) {
        l = new Cella{elem, nullptr};
    }
    else
        append(l->next, elem);
}


void readlist(Lista& l) {
    int q, e;

    std::cin>>q;

    while (q>0) {
        std::cin>>e;
        append(l, e);
        q--;
    }
}


bool findsum(Lista l, int sum, int add) {
    bool res = true;
    bool with, without;

    if(sum == 0 && add == 0){
        return res;
    }

    if(l == nullptr){
        return res = false;
    }

    with = findsum(l->next, sum - l->info, add-1);
    without = findsum(l->next, sum, add);

    return with || without;

}

int main() {
    Lista l{nullptr};

    readlist(l);

    int sum;
    int add;

    std::cout << "sum "<<std::endl;
    std::cin>>sum;

    std::cout << "add "<<std::endl;
    std::cin>>add;

    if (findsum(l, sum, add))
        std::cout<<"Somma trovata"<<std::endl;
    else
        std::cout<<"Somma non trovata"<<std::endl;

    return 0;
}
