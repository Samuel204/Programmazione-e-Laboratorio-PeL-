#include <iostream>
#include <vector>


//struct list
class ListInt{
public:
    ListInt();//defoult Costructor
    ~ListInt();// distruttore
    ListInt(const ListInt& s);//copy constructor

    void prepend(int elem);
    void print()const;

    int& at(unsigned int pos);
    const int& at(unsigned int pos)const;
    int dummy;

private:
    struct Cell{
        int info;
        Cell* next;
    };
    Cell* head;

    void destroy(Cell* pc);
    Cell* copy(Cell* source);


};
ListInt::ListInt() {
    head = nullptr;
    std::cout<<"Lista creata"<<std::endl;
}

ListInt::~ListInt() {
    std::cout<<"Entro nel distruttore"<<std::endl;
    destroy(head);
}

void ListInt::destroy(Cell *pc){//non è un metodo qualsiasi ma un metodo alla classe
    std::cout<<"Entro nella destroy"<<std::endl;
    if(pc != nullptr){
        destroy(pc->next);
        delete pc;
    }
}


//aggiungere elelmento in testa
void ListInt::prepend(int elem){
    Cell* newone = new Cell;
    newone->info = elem;
    newone->next = head;
    head = newone;
}


//stampare la lista
void ListInt::print()const{
    Cell* pc = head;
    while (pc){
        std::cout << pc->info << std::endl;
        pc = pc->next;
    }
}

ListInt::ListInt(const ListInt& s) {

    head = copy(s.head);
}

//
ListInt::Cell* ListInt::copy(Cell* source){
    if(source == nullptr){
        return nullptr;
    }else{
        Cell* dest = new Cell;
        dest->info = source->info;
        dest->next = copy(source->next);
        return dest;
    }
}



int& ListInt::at(unsigned int pos) {
    Cell* pc = head;
    while(pc != nullptr && pos>0){
        pc = pc->next;
        pos--;
    }
    //assert(pc != nullptr);//test che faccio nel programma se è false interompe il programma e da errore
    if(pc){
        return pc->info;
    }else{
        return dummy;
    }
}

const int& ListInt::at(unsigned int pos)const {
    Cell* pc = head;
    while(pc != nullptr && pos>0){
        pc = pc->next;
        pos--;
    }
    //assert(pc != nullptr);//test che faccio nel programma se è false interompe il programma e da errore
    if(pc){
        return pc->info;
    }else{
        return dummy;
    }
}

//
void myprint(ListInt& l){//non vado a modificare la lia l con &, garantire che print non va a modificare lo stato della mia l ed imposto print a const
    std::cout <<"Here's my list"<<std::endl;
    std::cout << l.at(1); // una const reference non puo stare a sinistra di un assegnamento
    l.print();
}


int main() {

    ListInt l;
    //l.destroy(l.head)//privato quindi non posso chiamarlo nel main

    l.prepend(5);
    l.prepend(10);
    l.prepend(20);

    myprint(l); //attenzione scatta la deep copy del copy const
    l.at(0) = 200;
    l.at(2) = 4202;

    l.print();
    return 0;
}
