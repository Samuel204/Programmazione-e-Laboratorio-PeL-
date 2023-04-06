#include <iostream>
#include <cmath>

constexpr double PI = 3.1415;

using std::cout;

class Complex{
private:
    double real;
    double im;

public:
    Complex(): real(0), im{0} {};
    Complex(double r, double i): real{r}, im{i} {};

    Complex(double modulo, double arg, bool polar){
        real = modulo*cos(arg);
        im = modulo *sin(arg);
    }

    void print() const {
        cout << "Real part: " <<  real;
        cout << " Imaginary part :" <<im;
    }

    Complex somma(const Complex& x) const {
        Complex res{x};
        res.real +=real;
        res.im += im;
        return res;
    }
};

int main() {
    Complex x {2,5}, y{10,PI/6, true};

    x.print();
    cout << std::endl;

    y.print();
    cout << std::endl;

    Complex z{x.somma(y)};
    return 0;
}
