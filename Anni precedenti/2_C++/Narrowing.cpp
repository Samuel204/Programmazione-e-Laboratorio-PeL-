#include <iostream>

using namespace std;

int main() {

    //int a = 12.4;
    int a= {12}; //la variabile a è inizialitazzato con 12.4
    double b;
    char c; // oggetto per indentificare . una variabile è un oggetto a cui è identificato . un valore e una sequenza di bit che viene genererata grazie al tipo. una dichiarazione e l abinamento tra un identificatore e un oggetto una definizione è l abinamento tra

    c = a; //casting implicito con perdita di informazioni con narrowing
    b = c; //ok
    c = b; // casting implicito con narrowing(perdita di informazioni)

    std::cin>>b;
    std::cout<<b<<std::endl;
    std::cout<<a<<std::endl;
    return 0;
}
