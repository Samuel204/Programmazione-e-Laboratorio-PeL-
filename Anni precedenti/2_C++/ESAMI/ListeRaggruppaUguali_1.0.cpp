#include<iostream>

/*
 * In questo esame implementerai una lista di interi speciale che raggruppa gli elementi uguali.
 * Potrai scegliere come codificare lo stato della lista, ma non potrai importare librerie aggiuntive a
 * quelle indicate nel testo. La struttura dati che devi implementare funziona così:
- all'inserimento di un nuovo elemento: se l'elemento è già presente nella lista,
 il nuovo elemento va inserito in una posizione adiacente a quella di quello esistente.
 Se l'elemento non è presente, il nuovo elemento va aggiunto in coda.
 - cancellazione di un elemento: avviene in modo standard.
Facciamo un esempio: supponiamo vengano fatto gli inserimento degli elementi 1, 5, 1, 1, 3, 5
La stampa della lista deve dare:1,1,1,5,5,3
supponiamo venga eliminato l'elemento 5.
Allora la lista diventa 1,1,1,5,3 supponiamo venga eliminato ancora l'elemento 5.
Allora la lista diventa 1,1,1,3 ora aggiungiamo l'elemento 5. Allora la lista diventa 1,1,1,3,5
Definiremo anche l'operatore di +. l1+l2 genera una nuova lista dove ogni elemento di 12 viene aggiunto alla
lista l1 seguendo la politica di inserimento descritta precedentemente.
 * */


class List_uguali{
  public:
    List_uguali();
    List_uguali(const List_uguali& l);

    void aggiungi(int elem);
    void rimuovi(int elem);
    void stampa() const; 

    List_uguali operator+(const List_uguali& l) const;
    List_uguali& operator=(const List_uguali& l);

    ~List_uguali();

  private:
    struct Cella;
    typedef Cella* pCella;
    pCella list;
    pCella tail = nullptr; 
    int size = 0; 
    void append(int elem); 
    void prepend(int elem); 
    void add(int pos, int elem); 
    void remove(int pos); 
    /*spazio per altri metodo privati*/
};

struct List_uguali::Cella{
  //Definisci qui le informazioni da mettere nella cella
  pCella next;
  pCella prev; 
  int info; 
};

//Costruttore di default: non modificare il metodo
List_uguali::List_uguali() {
  list = nullptr;
}

//Distruttore: non modificare il metodo
List_uguali::~List_uguali() {
  pCella p=list;
  while(p) {
    p=p->next;
    delete list;
    list=p;
  }
}

void List_uguali::append(int elem){
    pCella pc = new Cella{nullptr, this->tail, elem}; 
    if(this->tail!=nullptr) this->tail->next = pc; 
    else this->list = pc; 
    this->tail = pc; 
    this->size++;  
}

void List_uguali::prepend(int elem){
    pCella pc = new Cella{this->list, nullptr, elem}; 
    if(this->list!=nullptr) this->list->prev = pc; 
    else this->tail = pc; 
    this->list = pc; 
    this->size++;  
}

void List_uguali::add(int pos, int elem){
    if(pos == 0){
        this->prepend(elem); 
    }
    else if(pos == this->size-1){
        this->append(elem); 
    }
    else{
        pCella current; 
        for(current = this->list; current && pos>1; current=current->next) pos--; 
        pCella pc = new Cella{current->next, current, elem}; 
        current->next->prev = pc; 
        current->next = pc; 
    }
    this->size++; 
}

//Implementare: Esercizio 1
//Aggiungi un elemento alla lista
void List_uguali::aggiungi(int elem) {
    int pos = 0;
    int resPos = 0;  
    pCella pc = this->list; 
    if(pc == nullptr || pc->next == nullptr) {
        this->append(elem);
        return;
    } 
    while(pc){
        if(pc->info == elem) {
            resPos = pos;
            break; 
        } 
        pos++; 
        pc=pc->next; 
    }
    this->add(resPos, elem); 
}

//Implementare: Esercizio 1
//Stampa gli elementi della lista
void List_uguali::stampa() const {
    pCella pc = this->tail; 
    while(pc){
        std::cout << pc->info << std::endl; 
        pc = pc->prev; 
    }
}

void List_uguali::remove(int pos){
    pCella pc; 
    for(pc= this->list; pc && pos>0; pc=pc->next) pos--; 
    if(pc == nullptr) return; 
    if(pc->prev == nullptr){ //siamo su head
        this->list = pc->next; 
    }
    else{
        pc->prev->next = pc->next; 
    }
    if(pc->next == nullptr){ //siamo su tail
        this->tail = pc->prev; 
    }
    else{
        pc->next->prev = pc->prev; 
    }
    this->size--; 
}

//Implementare: Esercizio 1
//Rimuovi un elemento dalla lista
void List_uguali::rimuovi(int elem) {
    int pos = 0; 
    int resPos = 0; 
    pCella pc = this->list; 
    if(pc == nullptr) return; 
    while(pc){
        if(pc->info == elem){
            resPos = pos;
            break; 
        }  
        pos++; 
        pc = pc->next; 
    }
    this->remove(resPos); 
}

//Implementare: Esercizio 2
//Ridefinizione del copy constructor
List_uguali::List_uguali(const List_uguali& l) {
    this->head = nullptr; 
    this->tail = nullptr; 
    this->size = 0; 
    for(Pcell pc = l.head; pc!=nullptr; pc=pc->next) this->append(pc->info); 
}

//Implementare: Esercizio 3
List_uguali& List_uguali::List_uguali::operator=(const List_uguali& l) {
    pCella p=list;
    while(p) {
      p=p->next;
      delete list;
      list=p;
    }
    List_uguali(l); 
    return *this;
}


//Implementare: Esercizio 3
List_uguali List_uguali::List_uguali::operator+(const List_uguali& l) const{
  List_uguali res;
  pCella pc = list;
  while(pc){
    res.append(pc->info);
    pc = pc->next;
  }

  pCella pc2 = l.list;
  while(pc2){
    res.aggiungi(pc2->info);
    pc2 = pc2->next;
  }

  return res;


}

void leggi_lista(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.aggiungi(e);
  }
}

void rimuovi(List_uguali& l) {
  int tote;
  int e;
  std::cin>>tote;
  for (int i=0; i<tote; i++) {
    std::cin>>e;
    l.rimuovi(e);
  }
}

void leggi_ancora(List_uguali l) {
  leggi_lista(l);
  std::cout<<"Output copia"<<std::endl;
  l.stampa();
}

int main() {
  List_uguali l;
  leggi_lista(l);
  rimuovi(l);
  leggi_lista(l);
  std::cout<<"Output"<<std::endl;
  l.stampa();

  return 0;
}