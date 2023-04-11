#include <iostream>

struct TCella{
    int info;
    TCella* next;
};

typedef TCella* Tlist;

/*date le liste cancellare tutti gli elemeti dell'ultima occorenza dello zero alla fine
 * 2 4 5 0 8 20 3 0 4 2 1 (cancello 0 4 2 1). torna true trovata lo 0 false altrimenti
*/
bool elimina(Tlist& l){
    if(l == nullptr){
        return false;
    }else{
        bool resp = elimina(l->next);
        if(resp == false){
            if(l->info==0){//resp= (l_>info==0)
                resp = true;
            }else{
                resp = false;
            }
            delete l;
            l = nullptr;
        }
        return resp;
    }
}


//3 0 2 1 4 diventa 4 1 2 0 3
void ribalta(Tlist& l){
    if(l != nullptr && l->next != nullptr){//l->next != nullptr opzionale per avere efficeinza
        Tlist supp = l->next;
        ribalta(supp);
        l->next->next = l;
        l->next = nullptr;
        l = supp;
    }

}

//data una lista dire se è possibile formare una certa somma s con i numeri presenti
// 2 4 5 6 3 (esiste 15? si perche 5+4+6)
bool esiste_somma(Tlist l, int somma){
    if(l== nullptr){
        return (somma==0);
    }else{
        return 0;
    }

    return esiste_somma(l->next,somma) || esiste_somma(l->next,somma - l->info);
}



int main() {


    return 0;
}
