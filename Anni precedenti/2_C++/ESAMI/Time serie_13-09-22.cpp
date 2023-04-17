#include<iostream>

struct Impl;
typedef Impl* List;

class Timeserie{
public:
    Timeserie();
    ~Timeserie();
    Timeserie(const Timeserie& t);
    void add(unsigned long timestamp, double value);
    void print() const;
    void read();
    Timeserie& operator=(const Timeserie& t);
    Timeserie operator+(const Timeserie& t) const;

private:
    List pimpl;
};



//se serve puoi modificare questa struct
struct Impl{
    unsigned long timestamp;
    double value;
    Impl* next;
};

Timeserie::Timeserie() {  //da implementare
    //pimpl = new Impl;
    pimpl = nullptr;
    //std::cout << pimpl <<std::endl;
}

Timeserie::~Timeserie() { //da implementare
    delete this->pimpl;
}


Timeserie::Timeserie(const Timeserie& c) { //da implementare
    pimpl = c.pimpl;

}

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Timeserie::add(unsigned long timestamp, double value) {  //inserimento ordinato per timestamp

    List temp= new Impl;
    temp = pimpl;


    //std::cout << pimpl <<std::endl;
    while (pimpl != nullptr) {
        std::cout << pimpl->value <<std::endl;

        if(temp->timestamp < pimpl->timestamp){
            std::cout << temp->timestamp <<std::endl;

            temp->timestamp = pimpl->timestamp;

            add(temp->next->timestamp, temp->value);

        }else{

            temp->timestamp = pimpl->value;
            add(temp->next->timestamp, temp->value);

        }
        //temp = temp->next;

    }
    //std::cout << temp->timestamp <<std::endl;

}


//operatore di assegnamento: attenzione all'autoassegnamento!
/*Timeserie& Timeserie::operator=(const Timeserie& t) {

}


//costruisce una serie temporale contiene tutti gli elementi di *this e di t
//in modo ordinato, senza modificare *this o t
Timeserie Timeserie::operator+(const Timeserie& t) const {

}*/


//non modificare questo metodo
void Timeserie::print() const {
    List pc = pimpl;

    while (pc) {
        std::cout << "(" << pc->timestamp <<", "<<pc->value<<")"<<std::endl;
        pc = pc->next;
    }
}

//non modificare questo metodo
void Timeserie::read() {
    int element;
    std::cin>>element;

    for (int i=0; i<element; i++) {
        unsigned long ts;
        double v;
        std::cin>>ts;
        std::cin>>v;
        add(ts,v);
    }
}

//Questo main testa: costruttore di default, distruttore, add
int main() {
    Timeserie t;
    t.read();
    t.print();
    return 0;
}