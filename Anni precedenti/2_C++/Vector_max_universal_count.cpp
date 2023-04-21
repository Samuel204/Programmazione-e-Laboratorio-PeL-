#include <iostream>
#include <vector>

//trovare l'elemento massimo
int massimo(const std::vector<int>& v){
    int max = v.at(0);

    for(int i=1; i < v.size(); i++){
        if(v.at(i) > max){
            max = v.at(i);
        }
    }
    return max;
}

bool contare(const std::vector<int>& v, int elem){
    bool trovato = false;
    for(int i=0; i < v.size(); i++){
        if(v.at(i) == elem){
            trovato= true;
        }
    }
    return trovato;

}

//tutti array positivi
bool universal(const std::vector<int>& v){
    bool resp = true;
    for(int i=0; i <v.size();i++){
        if(v.at(i) <= 0){
            resp = false;
        }
    }
    return resp;
}

int main() {
    std::vector<int> v= {2,5,2,40};

    std::cout <<massimo(v) << std::endl;
    return 0;
}
