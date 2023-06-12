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


    /*spazio per altri metodo privati*/
};

struct List_uguali::Cella{
  //Definisci qui le informazioni da mettere nella cella
  int num;
  pCella next;
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

//Implementare: Esercizio 1
//Aggiungi un elemento alla lista
void List_uguali::aggiungi(int elem) {
    pCella pc=list;
    //se e vuota
    if(pc==nullptr){
        list=new Cella;
        list->num=elem;
        list->next=nullptr;
    }else{//se non e vuota
        //scorro fino alla posizione da inserire
        while(pc->num!=elem && pc->next!=nullptr)
            pc=pc->next;
        
        //inserisco
        pCella tmp= pc->next;
        pc->next=new Cella;
        pc=pc->next;
        pc->num=elem;
        pc->next=tmp;
    }
    
}

//Implementare: Esercizio 1
//Stampa gli elementi della lista
void List_uguali::stampa() const {
    if(list){
        pCella pc=list;
        
        while(pc!=nullptr){
            std::cout<<pc->num<<std::endl;
            pc=pc->next;
        }
    }
}

//Implementare: Esercizio 1
//Rimuovi un elemento dalla lista
void List_uguali::rimuovi(int elem) {
    if(this->list!=nullptr){
        pCella pc=this->list;
        pCella prev=pc;
        
        //se lelemento da eliminare e in testa
        if(pc->num==elem){
            pCella del=pc;
            
            list=pc->next;
            delete del;
            return;
        }else{
            //se non e in testa scorro pc, in modo tale che prev->next sia pc
            pc=pc->next;
        }
        
        //scorro all'elemento da eliminare
        while(pc->num!=elem && pc!=nullptr){
            prev=pc;
            pc=pc->next;
        }
        
        //prev->next da eliminare (se non nullptr)
        if(prev->next!=nullptr){
            //se la lista dopo prev->next non è vuota
            if(prev->next->next!=nullptr){
                pCella dlm=prev->next;
                prev->next=prev->next->next;
                delete dlm;
            }else{
            //se la lista dopo prev->next è vuota   
                pCella dlm=prev->next;
                prev->next=nullptr;
                delete dlm;
            }       
        }
    }
}

//Implementare: Esercizio 2
//Ridefinizione del copy constructor
List_uguali::List_uguali(const List_uguali& l) {
    if(l.list!=nullptr){
        pCella cp=l.list;
        
        //aggiungo lelemento numero 1 a this
        list= new Cella;
        list->num=cp->num;
        list->next=nullptr;
        cp=cp->next;
        
        pCella aux=list;
        
        //effettuo la copia dalleì'elemento 2 in poi
        while (cp!=nullptr) {
            aux->next=new Cella;
            aux=aux->next;
            aux->num=cp->num;
            aux->next=nullptr;
            cp=cp->next;
        }
    }else{
        //se l è vuota
        this->list=nullptr;
    }
}

//Implementare: Esercizio 3
List_uguali& List_uguali::List_uguali::operator=(const List_uguali& l) {
      
        if(l.list!=nullptr){
        pCella cp=l.list;
        
        //aggiungo lelemento numero 1 a this
        list= new Cella;
        list->num=cp->num;
        list->next=nullptr;
        cp=cp->next;
        
        pCella aux=list;
        
        //effettuo la copia dalleì'elemento 2 in poi
        while (cp!=nullptr) {
            aux->next=new Cella;
            aux=aux->next;
            aux->num=cp->num;
            aux->next=nullptr;
            cp=cp->next;
        }
    }    
    
  return *this;
}


//Implementare: Esercizio 3
List_uguali List_uguali::List_uguali::operator+(const List_uguali& l) const{
  List_uguali res;
  
    //aggiungo this
    if(this->list!=nullptr){
        pCella aux=this->list;
        
        while(aux!=nullptr){
            res.aggiungi(aux->num);
            aux=aux->next;
        }
    }

    //aggiungo l
    if(this->list!=nullptr){
        pCella aux=l.list;
        
        while(aux!=nullptr){
            res.aggiungi(aux->num);
            aux=aux->next;
        }
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
  List_uguali l1, l2;
  leggi_lista(l1);
  leggi_lista(l2);
  l2 = l1+l2;
  std::cout<<"Output"<<std::endl;
  l1.stampa();
  std::cout<<"Output"<<std::endl;
  l2.stampa();

  return 0;
}
