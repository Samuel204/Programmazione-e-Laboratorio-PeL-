#include <iostream>
#include <vector>

/*
 * Si desidera implementare la classe ListStrings che ha le seguenti caratteristiche:
• memorizza stringhe come oggetti del tipo string della standard library
• le stringhe sono memorizzate in ordine alfabetico crescente
• la lista è doppiamente concatenata
L'esercizio è diviso in tre parti:
1. Implementare il distruttore e il metodo add. Quest'ultimo aggiunge una stringa alla lista mantenendo l'ordinamento.
2. Implementare l'operatore di assegnamento
3. Implementare l'operatore di somma.
Questo produce una nuova lista (senzaalterare gli operandi) che contiene tutte le stringhe
della prima e della seconda lista. Quindi la lunghezza della lista somma è pari alla somma delle
lunghezze delle liste operandi. E' possibile introdurre metodi ausiliari ma non includere altre
librerie oltre a quelle fornite, ne' modificare la definizione della classe.
 */

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
    while (head){
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
    }
}

ListStrings ListStrings::operator+(const ListStrings& ls) const {
    ListStrings res;
    Cell* temp = head;

    if(head != nullptr){
        while (temp != nullptr){
            res.add(temp->info);
            temp = temp->next;
        }
    }

    Cell* temp2;
    temp2 = ls.head;

    while (temp2 != ls.head){
        res.add(temp2->info);
        temp2 = temp2->next;
    }
    return res;
}

ListStrings& ListStrings::operator=(const ListStrings& ls) {
    head = nullptr;
    tail = nullptr;
    
    if(this != &ls){
        Cell* pc = ls.head;

        while (pc){
            add(pc->info);
            pc = pc->next;
        }
        
    }else{
        Cell* pc = ls.head;
        Cell* temp = ls.head;
        temp = new Cell;
    }
    return *this;
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

    /*
     * int n1,n2;
  string s;
  ListStrings ls1;
  ListStrings ls2;
  ListStrings res;

  cin >> n1;
  cin >> n2;

  for (; n1>0; n1--) {
    cin>>s;
    ls1.add(s);
  }

  for (; n2>0; n2--) {
    cin>>s;
    ls2.add(s);
  }

  res = ls1+ls2;

  cout<<"Stampo la prima lista"<<endl;
  ls1.print_forward();
  cout<<endl;
  ls1.print_reversed();
  cout<<"Stampo la seconda lista"<<endl;
  ls2.print_forward();
  cout<<endl;
  ls2.print_reversed();
  cout<<"Stampo la lista somma"<<endl;
  res.print_forward();
  cout<<endl;
  res.print_reversed();
     */



    return 0;
}