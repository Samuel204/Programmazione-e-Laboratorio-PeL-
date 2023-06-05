#include<iostream>
#include<string>

using namespace std;
/*DA SISTEMARE
Scrivere una funzione che, date due stringhe, decida se una è l'anagramma dell'altra. Notate che lo stesso carattere può
comparire più volte nelle stringhe. I caratteri di spaziatura vanno ignorati.
Le stringhe contengono caratteri alfabetici minuscoli e spazi (nient'altro).
La firma della funzione sarà: bool anagramma(string s1, string s2);
dove s1 e s2 sono le stringhe da considerare. Ad esempio "sogno
civetta" è l'anagramma di "cattivo segno",
PS: condizione perché s1 sia anagramma di s2 è che tutti i caratteri di s1 siano presenti in s2 e viceversa nello stesso
numero di volte.*/

bool anagramma(string s1, string s2){

    for(int i=0; i < s1.length(); i++) {
        if (s1.at(i) == ' ') {
            s1.erase(i,1);
        }
    }

    for(int i=0; i < s2.length(); i++){
        if(s2.at(i) == ' '){
            s2.erase(i, 1);
        }
    }

    //faccio lo swap di s1
    for(int i=0; i < s1.length()-1; i++){
        for(int j=0; s1.length()-1; j++){
            if(s1.at(j) > s1[j+1]){
                char temp = s1.at(j);
                s1.at(j) = s1[j+1];
                s1[j+1] = temp;
            }
        }
    }

    //swap di s2
    for(int i=0; i < s2.length()-1; i++){
        for(int j=0; j < s2.length()-1; j++){
            if(s2.at(j) > s2.at(j+1)) {
                char temp = s2.at(j);
                s2.at(j) = s2.at(j+1);
                s2.at(j+1) = temp;
            }

        }
    }

    if(s1 == s2){
        return true;
    }else{
        return false;
    }


}

int main() {
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);

    if (anagramma(a,b))
        std::cout << "Si" <<std::endl;
    else
        std::cout << "No" <<std::endl;

    return 0;
}