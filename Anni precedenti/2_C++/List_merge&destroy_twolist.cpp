#include <iostream>

//quando viene fatto un passaggio per copia, o chiamo esplicitamnete una copia della lista copy constructor

class ListInt{
public:
    ListInt();  //Deafult Constructor
    ~ListInt();  //Destructor
    ListInt(const ListInt& s); //Copy constructor

    void prepend(int el);
    void append(int el);
    void print() const;
    void read();


    void merge_and_destroy(ListInt& l1, ListInt& l2); /*date due liste ordinate l1 e l2 l'oggetto corrente ruba lo stato di memorizzazione
                                                        *le celle in ordine. Dopo la chiamata sia li che l2 sono le liste vuote*/

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
    Pcell merge_and_destroy_rec(Pcell l1, Pcell l2);

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

//legge la lista,
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


void ListInt::append(int el) {
    if (head==nullptr)
        prepend(el);
    else {
        Pcell pc = head;
        while (pc->next!=nullptr)
            pc = pc->next;
        pc->next = new Cell;
        pc->next->info = el;
        pc->next->next = nullptr;
    }
}

void ListInt::prepend(int el) {
    Pcell newone = new Cell;
    newone->info = el;
    newone->next = head;
    head = newone;
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

void ListInt::merge_and_destroy(ListInt &l1, ListInt &l2) {
    //non funziona se l1 e l2 sono proprio l'oggetto su cui chiamo il metodo

    if(this != &l1 &&  this != &l2) {
        destroy(head);

        head = merge_and_destroy_rec(l1.head, l2.head);
        l1.head = nullptr;
        l2.head = nullptr;
    }else{
        if(this == &l1 && this != &l2){
            ListInt supp(l1);
            merge_and_destroy(supp, l2);

        }else if(this != &l1 && this == &l2){
                ListInt supp(l2);
                merge_and_destroy(l1, supp);

        }else{
            ListInt supp1(l1); // mi fa la merge and dest di a.merge_and_dest(a,a)
            ListInt supp2(l2);
            merge_and_destroy(supp1,supp2);

        }
    }
}

ListInt::Pcell ListInt::merge_and_destroy_rec(Pcell l1, Pcell l2) {
    if(l1 == nullptr && l2 == nullptr){
        return nullptr;
    }else{
        if(l1 == nullptr) {
            return l2;
        }else{
            if(l2 == nullptr){
                return l1;
            }else{
                if(l1->info < l2->info){
                    l1->next = merge_and_destroy_rec(l1->next,l2);
                    return l1;
                }else{
                    l2->next = merge_and_destroy_rec(l1,l2->next);
                    return l2;
                }
            }
        }
    }
}


int main() {
    int a;
    //int b(a);
    //int b{a} ;//sto facendo la copy costructor
    ListInt l1, l2;

    l1.read();
    l2.read();
    {
        ListInt l;
        l.merge_and_destroy(l1,l2);
        l.print();
    }

    l1.print();
    l2.print();

    return 0;
}
