#include <iostream>
#include <vector>

//swap
void swap(int& a, int& b){
    int temp;
    temp=a;
    a = b;
    b = temp;
}

//bubble sort
void bubble(std::vector<int>& v){
    for(int soglia=0; soglia < v.size();soglia++){
        for(int i= v.size()-1; i>soglia  ;i--){
            if(v.at(i) < v.at(i-1)){
                swap(v.at(i), v.at(i-1));
            }

        }
    }

}

void print_vec(std::vector<int> v, size_t size){
    for(int i=0; i < size; i++){
        std::cout << v.at(i) << std::endl;
    }
}

int main() {

    std::vector<int> v= {2,1,4,6,3};
    bubble(v);
    print_vec(v,5);

    return 0;
}
