#include<iostream>
#include<string>

using namespace std;

/*Classe lista di stringhe ordinate alfabeticamente in modo
 * crescente. La lista e' doppiamente concatenata*/

class ListStrings{
public:
  ListStrings();
  ListStrings(ListStrings&& ls);
  ~ListStrings();
  void print_forward() const;
  void print_reversed() const;
  void add(const string& s);
  ListStrings& operator=(const ListStrings& ls);
  ListStrings operator+(const ListStrings& ls) const;
private:
  struct Cell{
    string info;
    Cell* next;
    Cell* prev;
  };
  Cell* head; //puntatore alla prima cella
  Cell* tail; //puntatore all'ultima cella
};


//Default constructor
ListStrings::ListStrings() {
  head = nullptr;
  tail = nullptr;
}


//Move constructor
ListStrings::ListStrings(ListStrings&& ls) {
  std::cout<<"Move costructor"<<endl;
  head = ls.head;
  tail = ls.tail;
  ls.head = nullptr;
  ls.tail = nullptr;
}

//stampa da head a tail
void ListStrings::print_forward() const{
  Cell* ptr=head;
  while (ptr) {
    cout<<ptr->info<<endl;
    ptr = ptr->next;
  }
}

//stampa da tail a head
void ListStrings::print_reversed() const{
  Cell* ptr=tail;
  while(ptr) {
    cout<<ptr->info<<endl;
    ptr=ptr->prev;
  }
}



//Destructor: 
ListStrings::~ListStrings() {
    //scrivi qui il tuo codice Esercizio 1
    while(head){
        Cell* sup=head;
        head=head->next;
        delete(sup);
    }
}


void ListStrings::add(const string& s) {
   //Scrivi qui il tuo codice Esercizio 1
   if(head){
        Cell* pc=tail;
        //bool fatto=false;

        //considerato i casi estremi (aggiungere in coda e in testa)
        if(!pc->next && s>pc->info){
          //pc=tail;
          Cell* sup=new Cell{s,nullptr,pc};
          tail=sup;
          fatto=true;
          pc->next=sup;
        }else 
        //pc=head;
        if(!pc->prev && s<pc->info){
          pc=head;
          Cell* sup=new Cell{s,pc,nullptr};
          head=sup;
          fatto=true;
          pc->prev=sup;
        }else{ 
          while(pc /*&& !fatto*/){
              if(s>=pc->info && s<pc->next->info){    //s piu grande di curr ma più piccolo di quello dopo (caso in mezzo)
                  Cell* sup=new Cell{s,pc->next,pc};
                  pc->next->prev=sup;
                  pc->next=sup;
                  fatto=true;
              }
              pc=pc->next;
            }
        }
   }else{
    this->head=new Cell{s, nullptr, nullptr};
    this->tail=this->head;
   }
}

ListStrings& ListStrings::operator=(const ListStrings& ls) {
   //Scrivi qui il tuo codice Esercizio 2
   if(this != &ls){
        Cell* pc=ls.head;
        while(pc){
            add(pc->info);
            pc=pc->next;
        }
    }

  return *this;
}

ListStrings ListStrings::operator+(const ListStrings& ls) const {
   //Scrivi qui il tuo codice Esercizio 3
  ListStrings res;
  Cell* sup1=head;
    Cell* sup2=ls.head;
    while(sup1){
        res.add(sup1->info);
        sup1=sup1->next;
    }
    while(sup2){
        res.add(sup2->info);
        sup2=sup2->next;
    }
  return res;
}

int main() {
  int n;
  string s;
  ListStrings ls;

  cin >> n;
  for (; n>0; n--) {
    cin>>s;
    ls.add(s);
  }
  cout<<endl;
  ls.print_forward();
  cout<<endl;
  ls.print_reversed();
  return 0;
}