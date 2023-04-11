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


    int& at(unsigned int pos);
    const int& at(unsigned int pos) const;

    ListInt& operator = (const ListInt& x); // a = b o c = a = b
    ListInt operator+(const ListInt &x)const;

private:
    struct Cell {
        int info;
        Cell* next;
    };

    typedef Cell* Pcell;

    Pcell head;
    int dummy;

    void destroy(Pcell pc);
    Pcell copy(Pcell source) const;


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

ListInt::Pcell ListInt::copy(Cell* source) const {
    if (source == nullptr)
        return nullptr;
    else {
        Pcell dest = new Cell;
        dest->info = source->info;
        dest->next = copy(source->next);
        return dest;
    }
}

ListInt& ListInt::operator=(const ListInt &x) {
    if(this != &x ) {
        //distruggere la mia lista
        destroy(head);
        head = copy(x.head);
    }
    return *this;
}

ListInt ListInt::operator+(const ListInt &x)const {
    //
    ListInt supp (*this);
    Pcell pc = supp.head;
    if(pc == nullptr){
        supp.head = copy(x.head); // fa la deep copy
    }else{
        while (pc->next != nullptr){
            pc = pc->next;
        }
        pc->next = copy(x.head);
    }
    return supp;
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



int main() {
    int a;
    //int b(a);
    //int b{a} ;//sto facendo la copy costructor
    ListInt l1, l2;

    l1.read();
    l2.read();
    {
        ListInt l;

        l.print();
    }

    l1.print();
    l2.print();

    return 0;
}
