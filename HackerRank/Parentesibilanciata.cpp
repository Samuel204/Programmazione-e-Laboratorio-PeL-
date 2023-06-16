#include <iostream>
#include <string>
#include<stack>

using namespace std;

/*Una sequenza a parentesi bilanciate generalizzata è una stringa in cui possono comparire i caratteri A,B,...,Z (le
parentesi aperte) e a,b,...,z (le parentesi chiuse) ottenuta concatenando un certo numero di stringhe fatte come
segue: apri una parentesi di un certo tipo X, inserisci una serie di sequenze a parentesi bilanciate generalizzate,
chiudi con parentesi x (dove X può essere A,B,...,Z e x è la corrispondente lettera minuscola). Per esempio:
• ABbCBbBbca è bilanciata: le parentesi più esterne sono Ala, e dentro di esse abbiamo due sotto-sequenze che
sono chiaramente bilanciate: Bb e CBbBbc (quest'ultima apre C, seguito da Bb e Bb, ed infine chiude con c).
• DGgAad è bilanciata
• TAaBb non è bilanciata (la parentesi aperta 'T' non è accoppiata con una parentesi chiusa "t") scrivere una funzione
bool bilanciata(string& s) che decide se una stringa è una sequenza a parentesi
bilanciate generalizzata. La stringa vuota è sempre bilanciata.
 * */
/*-----------------------------------*/
/*
 * //come usare std::stack<char>:
 *
 * stack<char> S; //crea nuovo stack vuoto di char
 * char x = 'a';
 * S.push(x); // aggiungi x in cima allo stack
 * char& t = S.top(); // reference alla cima dello stack
 * S.pop(); //rimuove la cima dello stack
 *
 */

bool bilanciata(string& s){

    stack<int> s1;

    char elem;
    int i=0;

    while (i < s.size()){
        elem = s[i];

        if(s[i] >= 'A' && s[i] <= 'Z'){
            s1.push(elem);//inserisci gli elelmenti
        }else{
            //se i caratteri sono minuscoli
            if(s1.empty())return false;

            char temp = s1.top();
            s1.pop();
            temp = temp - 'A'+'a';

            if(temp != elem){
                return false;
            }
        }

        i++;
    }

    if(s1.size() == 0){
        return true;
    }else{
        return false;
    }
}


int main() {

    string s;
    getline(cin,s);

    cout << boolalpha <<  bilanciata(s);

    return 0;
}
