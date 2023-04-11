#include <iostream>


struct TCella{
    int info;
    TCella* next;
};
typedef TCella* Tlist;


//sommare ricorsivamente gli elementi di una lista
int somma(Tlist l){
    if(l == nullptr){
        return 0;
    }else{
        return l->info + somma(l->next);
    }
}

//
int massimo(Tlist l){//l != nullptr per ipotesi
    if(l->next == nullptr){
        return l->info;
    }else{
        int max = massimo(l->next);

        if(max > l->info) {
            return max;
        }else{
            return l->info;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
