#include <iostream>
#include <vector>
#include <stack>

/*class Prova{
public:
    Prova();
    ~Prova();
    void foo(int x);
    static void foos(int x);

private:
    int l;
    static int k; //una variabile che condivisa a tutte le variabili di tipo k es: qunate istante vuoi di tipo k

};
 */

//5+7notazione infissa
//notazione post fissa 5 7 +
/*
 * 5 7 + 8 + = 12 + 8 = 20
 * (5+7)*8 == 5 7 + 8 * == 5 7 8 * + == prima prende 7*8 poi 56 + 5
 */

/*
 * (12 : (5+1))*20 == 12 5 1 + : 20 * ==
 */

struct Token{
    double number;
    char op;
    bool is_number;
};

//notazione postfissa
//5 * (2+4) == 5 2 4 + *
double valuta(std::vector<Token> exp){
    std::stack<Token> s;

    for(const auto& t: exp){ // auto il compilatore valuta il tipo dell espressione che stai utilizzando per la variabile es 2.3 riconosce che è un double
        if(t.is_number){
            s.push(t);
        }else{//nel caso trovassi un operatore dentro la stack
            Token op2 = s.top(); s.pop(); // faccio la pop degli operatori
            Token op1 = s.top(); s.pop();
            Token result;
            result.is_number = true;
            switch (t.op) {
                case 'x': result.number = op1.number + op2.number;
                    break;
                case '*': result.number = op1.number * op2.number;
                    break;
            }
            s.push(result);
        }
    }
    return s.top().number;
}



int main() {
    /*Prova p; //è un oggetto di tipo prova
    int x=4;
    p.foo(x);
    p.foo(x);

    Prova::foos(15);//non deve accedere allo stato della classe il metodo static*/

    return 0;
}
