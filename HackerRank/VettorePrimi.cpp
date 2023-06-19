#include <iostream>
#include <vector>

using namespace std;

/*
 * Si desidera scrivere una funzione che riempia un vettore con
numeri primi dove n è un numero non negativo.
 */

void print(const std::vector<int>& v) {
    for (auto x: v) {
        std::cout<<x<<std::endl;
    }
}

bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i=2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

std::vector<int> fill_with_primes(int size){

    vector<int> v;
    if(size == 0){
        return v;
    }

    int count;

    count += 2;
    for(int i=0; i < size;){
        if(isPrime(count)){
            v.push_back(count);
            i++;
        }
        count++;
    }

    return v;
}



int main() {
    int size;

    std::cin>>size;

    std::vector<int> v;

    v = fill_with_primes(size);

    print(v);


    return 0;
}