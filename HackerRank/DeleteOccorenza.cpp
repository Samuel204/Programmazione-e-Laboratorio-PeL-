#include<iostream>
#include<string>

using namespace std;

/*
Data la classe Listlnt vista a lezione implementare un
metodo ricorso che elimini tutte le occorrenze di elementi identici consecutivi lasciandone uno soltanto.
Per esempio, la lista: 322422244 diventerà la lista 32424
Per realizzare il metodo remove consec si dovrà anche implementare il
metodo privato che sviluppa la ricorsione remove_consec_rec.*/

class ListInt{
public:
    ListInt();  //Deafult Constructor
    ~ListInt();  //Destructor
    ListInt(const ListInt& s); //Copy constructor

    void prepend(int el);
    void append(int el);
    void print() const;
    void read();

    void remove_consec();

    int& at(unsigned int pos);
    const int& at(unsigned int pos) const;
private:
    struct Cell {
        int info;
        Cell* next;
    };

    typedef Cell* Pcell;

    Pcell head;
    int dummy;

    void destroy(Pcell pc);
    Pcell copy(Pcell source);

    void remove_consec_rec(Pcell& l);
};

ListInt::ListInt() {
    head = nullptr;
}

ListInt::~ListInt() {
    destroy(head);
}

void ListInt::destroy(Pcell pc) {

    if (pc!=nullptr) {
        destroy(pc->next);
        delete pc;
    }
}

void ListInt::read() {
    destroy(head);
    head=nullptr;
    int elem;
    std::cin>>elem;

    for (int i=0; i<elem; i++) {
        int e;
        std::cin>>e;
        append(e);
    }
}

void ListInt::print() const {
    Pcell pc = head;
    while (pc) {
        std::cout<<pc->info<<std::endl;
        pc = pc->next;
    }
}


ListInt::ListInt(const ListInt& s) {
    head = copy(s.head);
}

ListInt::Pcell ListInt::copy(Cell* source) {
    if (source == nullptr)
        return nullptr;
    else {
        Pcell dest = new Cell;
        dest->info = source->info;
        dest->next = copy(source->next);
        return dest;
    }
}


int& ListInt::at(unsigned int pos) {
    Pcell pc = head;
    while (pc!=nullptr && pos>0) {
        pc = pc->next;
        pos--;
    }

    if (pc)
        return pc->info;
    else
        return dummy;
}

const int& ListInt::at(unsigned int pos) const {
    Pcell pc = head;
    while (pc!=nullptr && pos>0) {
        pc = pc->next;
        pos--;
    }

    if (pc)
        return pc->info;
    else
        return dummy;
}



void ListInt::prepend(int el) {
    Pcell newone = new Cell;
    newone->info = el;
    newone->next = head;
    head = newone;
}

void ListInt::append(int el) {
    if(head == nullptr){
        prepend(el);
    }else{
        Pcell pc = head;
        while (pc->next != nullptr){
            pc = pc->next;
        }

        pc->next = new Cell;
        pc->next->info = el;
        pc->next->next = nullptr;
    }
}

void ListInt::remove_consec() {
    remove_consec_rec(head);
}

void ListInt::remove_consec_rec(Pcell &l) {

    if(l == nullptr)return;

    if(l->next != nullptr){
        Pcell temp = l->next;

        if(l->info == temp->info){
            delete l;
            l = temp;
            remove_consec_rec(l);
        }else{
            remove_consec_rec(l->next);
        }
    }

}

int main() {
    ListInt l;

    l.read();

    l.remove_consec();

    l.print();


    return 0;
}