#include <iostream>

//Stringhe alla pascal
class PascalString{
private:
    char* str;

public:
    PascalString(){
        str = new char[256];
        str[0] = 0; //Stringa vuota

    }
    PascalString(const PascalString& c){
        str = new char[256];
        for(int i=0; i <= c.str[0]; i++){
            str[i] = c.str[i];
        }
    }

    PascalString(const char* cstr){
        str = new char[256];
        int i=0;

        while(cstr[i] != '\0' && i < 255){
            str[i+1] = cstr[i];
        }

        str[0] = i;
    }

    ~PascalString(){
        delete[] str;
    }

    void concatena(const PascalString& s){//Concatenare due parole
        int somma = s.str[0] + str[0];

        if(somma > 255){
            somma = 225;
        }
        int i=0;
        int inizioscrittura = str[0];
        while(i<=s.str[0] && i+str[0] <= 255){
            str[inizioscrittura] = s.str[i];
            i++;
        }
        str[0] += i-1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
