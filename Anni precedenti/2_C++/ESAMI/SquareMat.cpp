#include <iostream>
#include <vector>

using namespace std;

/*
 *Inzializzare una matrice
 */

class SquareMat{
public:
    SquareMat(int dim);//costruttore
    SquareMat(const SquareMat& s);//costruttore di copia
    ~SquareMat();//distruttore

    void read();
    void print()const;//stampa la matrice
    int& at(int r, int c);
    const int& at(int r, int c)const;
    SquareMat reduce(int r, int c)const;

    int determinant()const;
    int size()const;


private:
    vector<vector<int>> mat;
};

void SquareMat::print()const{
    for(int i=0; i < size(); i++){
        for(int j=0; j < size(); j++){
            cout << this->at(i,j) << " ";
        }
        cout <<endl;
    }
}


void SquareMat::read(){
    for(int i=0; i < size(); i++){
        for(int j=0; j < size(); j++){
            cin >> this->at(i,j);
        }
    }

}

SquareMat::SquareMat(int dim) {
    mat.resize(dim, vector<int>(dim,0));
}

SquareMat::SquareMat(const SquareMat &s){
    mat = s.mat;
}

/* non c'è bisogno di implementare un distruttore oppure un operatore uguale
*  dato che la struttura dati dei vector li ha già e noi lavoriamo con oggetti
*  che contengono solo un vector, se avesse un altro membro dovremmo creare un
*  distruttore per quel membro
*/
SquareMat::~SquareMat() {
    //quando termina la vita del vect automaticamente veniva eliminato

}//fine


// es 1, at dice cosa ce in una determinata posizione;
int& SquareMat::at(int r, int c){
    return mat.at(r).at(c);

}

const int& SquareMat::at(int r, int c)const{
    return mat.at(r).at(c);
}

SquareMat SquareMat::SquareMat::reduce(int r, int c) const {
    if(r < mat.size() && c < mat.size()){
        SquareMat res(mat.size()-1);
        for(int i=0; i < mat.size(); i++){
            for(int j=0; j < mat.size(); j++){
                if(i != r && j != c){
                    int tr, tc;
                    if(i < r){
                        tr = i;
                    }else{
                        tr = i-1;
                    }
                    if(j < c){
                        tc = j;
                    }else{
                        tc = j-1;
                    }
                    res.mat.at(tr).at(tc) = mat.at(i).at(j);
                }
            }
        }
        return res;

    }else{
        return *this;
    }

}

int SquareMat::determinant() const {
    if(mat.size() == 1){
        return mat.at(0).at(0);
    }else{
        int res=0;
        int sign = 1;
        for(int i=0; mat.size(); i++){
            res += sign * this->at(0,1)* reduce(0,1).determinant();
            sign = sign * (-1);
        }
        return res;
    }
}

int SquareMat::size() const {
    return mat.size();
}

//ES3_funzio.controllo se un numero è primo
bool isprime(int n){
    if(n <= 1){
        return false;
    }else{
        bool prime = true;
        int d = 2;
        while (d*d <= n && prime){
            if(n%d==0){
                prime=false;
            }else
                d++;

        }
        return prime;
    }

}


bool allprimes(SquareMat m){
    bool resp = true;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j < m.size(); j++){
            if(!isprime(m.at(i,j))){
                resp = false;
            }
        }
    }
    return resp;
}


int main() {
    //la matrice quadrata deve essere un array di interi
    int dim;
    std::cout<<"Inserisci dim ";
    std::cin>>dim;
    std::cout<<std::endl;
    SquareMat x(dim);
    x.read();
    SquareMat y(x);
    y.at(0,0)=25;
    x.print();
    y.print();

    std::cout<<x.determinant()<<std::endl;
    std::cout<<y.determinant()<<std::endl;
    if(allprimes(x))
        std::cout<<"Tutti primi"<<std::endl;
    else
        std::cout<<"Almeno uno non primo"<<std::endl;
    return 0;
}
