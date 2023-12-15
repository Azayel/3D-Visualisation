#include <iostream>
/*#include <cstdint>

int main(){
    {
        bool a = true;
        bool b = false;
        auto c = a + b; // == int
    }
    { // WRONG LMAO
        uint64_t x = 1;
        int64_t y = -1;
        if(y<x) std::cout << y << "<" << x << "\n";
        else std::cout << y << ">=" << x << "\n";
    }
    { // CORRECT
        uint16_t x = 1;
        int16_t y = -1;
        if(y<x) std::cout << y << "<" << x << "\n";
        else std::cout << y << ">=" << x << "\n";
    }


    return 0;
}*/
void g(int) {std::cout << "g1\n";}
void g(long long) {std::cout << "g2\n";}
void f(int,double) {std::cout << "f1\n";}
void f(char,long double) {std::cout << "f2\n";}

int main(int argc, char** argv) {
    char c= 'a';
    double d=2;     // Fill in the conversion costs (1-3)
    float fl=2;     // in the following tables
    long l=2;

                // g1(int)  | g2(long long)
    g(c);       // (2)      | (3)                               => g1
    // g(l);    // (3)      | (3) // compiler error: ambigious

    //      f1(int, double) | f2(char, long double)
    f(c,fl);    // ( 2, 2 ) | ( 1 , 3)                          => f1
    f(c,d);     // ( 2, 1 ) | ( 1 , 3)                          => f1
}