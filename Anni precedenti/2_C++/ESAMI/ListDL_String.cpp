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
    
    while (head) {
        Cell* temp = head;
        head = head->next;
        delete temp;
        temp = head;
    
    }
}


void ListStrings::add(const string& s) {
   //Scrivi qui il tuo codice Esercizio 1
   Cell* temp_l = new Cell;
   
   if(head == nullptr){
       temp_l->info = s;
       temp_l->next = nullptr;
       temp_l->prev = nullptr;
       head = temp_l;
       tail = temp_l;
       return;
    }
   
    Cell *curr = head;
    do{
        temp_l->info = s;
        if(curr->info >=temp_l->info){
            if(curr == head){
                temp_l->next = head;
                head->prev = temp_l;
                head = temp_l;
                
            }else{
                
                temp_l->next = curr;
                temp_l->prev = curr->prev;
                curr->prev->next = temp_l;
                curr->prev=temp_l;
            }
            return;
        }
        curr = curr->next;
    
    }while (curr != nullptr);
    tail->next = temp_l;
    temp_l->prev = tail;
    tail = temp_l;
   
}
       
ListStrings& ListStrings::operator=(const ListStrings& ls) {
   //Scrivi qui il tuo codice Esercizio 2
    head = nullptr;
    tail = nullptr;
    if(this != &ls){
        Cell* pc = ls.head;
        while (pc) {
            add(pc->info);
            pc = pc->next;
        
        }
    }else{
        Cell* pc = ls.head;
        Cell* temp = ls.head;
        temp = new Cell;
        /*if(tail != nullptr){
            while (temp != nullptr){
                //pc->info = temp->info;
                //pc->next = nullptr;
                //pc->prev = tail;
                //add(pc->info);
                //pc = pc->next;
                
                temp = temp->next;
            }
            //head = pc;
        }*/
    }
    
  return *this;
}


ListStrings ListStrings::operator+(const ListStrings& ls) const {
   //Scrivi qui il tuo codice Esercizio 3
  ListStrings res;
    Cell* temp = head;

    if(head != nullptr){

        do{
            res.add(temp->info);
            temp = temp->next;
        }while (temp != nullptr);
    }


    Cell* temp2;
    temp2 = ls.head;
    while(temp2 != nullptr){
        res.add(temp2->info);
        temp2 = temp2->next;
    }

  return res;
}

int main() {
  int n;
  string s;
  ListStrings ls;
  ListStrings res;

  res.add("Prova");
  res.add("Trash");

  cin >> n;
  for (; n>0; n--) {
    cin>>s;
    ls.add(s);
  }

  res = ls;

  cout<<"Stampo la lista originale"<<endl;
  ls.print_forward();
  cout<<endl;
  ls.print_reversed();
  cout<<"Stampo la lista copiata"<<endl;
  res.print_forward();
  cout<<endl;
  res.print_reversed();

  return 0;
}
