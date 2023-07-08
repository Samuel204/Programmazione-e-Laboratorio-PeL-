#include <iostream>
#include<vector>

//dato un array e un sum, ritornare true se è possibile sommare una coppia di addendi per formare un sum.

using namespace std;

//iterativo
bool sumint(vector<int> v, int sum){
    bool res=false;

    for(int i=0; i < v.size()-1; i++){
        for(int j=i+1; j < v.size(); j++){
            if((v[i] + v[j]) == sum){//sommo il primo elemento con il secondo se è = a sum
                res = true;
            }
        }
    }
    return res;
}



//ricorsivo, parte con complessità minore
bool sumint_ric(vector<int> v, int sum){

    if(sum==0){//caso base
        return true;
    }
    if(v.empty() && sum!=0){
        return false;
    }
    int val=v.back();//retituisce l'ultimo elemento
    v.pop_back();//toglie l'ultimo elemento
    
    return sumint_ric(v,sum-val) || sumint_ric(v,sum);
}


int main() {

    //parte iterativa
    vector<int> v1 = {2,4,4,7};
    if(sumint(v1,9)){
        cout <<"v1=sum trovato"<<endl;
    }else{
        cout << "sum non trovato"<<endl;
    }

    //parte ricorsiva
    vector<int> v2 = {2,4,4,7};
    if(sumint_ric(v2,9)){
        cout <<"v2=sum trovato"<<endl;
    }else{
        cout << "sum non trovato"<<endl;
    }
    return 0;
}