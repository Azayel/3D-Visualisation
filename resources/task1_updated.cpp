#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cassert>
#include <cmath>

// Range: [65535.9999847412109375, 0.0] 
// or just : (65536, 0]
class Festkommazahl {
    uint32_t v;

public:
    Festkommazahl() : v{0x0000'0000} { }
    Festkommazahl(double value) { set(value); }

    constexpr void setRaw(uint32_t i) { v=i; }
    constexpr uint32_t getRaw(/*uint32_t i*/) const { return v; }

    constexpr void set(double value){
        if(value < 0.){
            v = 0x0;
            return;
        }
        if(value >= 0x10000){ // = 65536
            v = 0xFFFF'FFFF;
            return;
        }
        int vorkomma = (int)std::floor(value);
        v = (vorkomma << 16);
        value -= vorkomma;
        v |= (uint32_t)(value * pow(2, 16));  
    }

    constexpr double get(){
        int lowBits = v & 0x0000FFFF;
        double small = lowBits / pow(2,16);
        int highBits = v >> 16;
        double result = (float)highBits + small;
        return result;
    }

    constexpr operator double(){ // is used for iostream!
        return get();
    }
};

int main() {
    assert( fabs( Festkommazahl(-33.99) - 0 ) < 1e-5); // value<0 --> 0
    assert( fabs( Festkommazahl(133.99) - 133.99 ) < 1e-5);
    assert( fabs( Festkommazahl(88.123) - 88.123 ) < 1e-5);
    
    assert( fabs( Festkommazahl(99.9999999) - 99.9999999 ) < 1e-5);
    assert( fabs( Festkommazahl(1e-4) - (1e-4)) < 1e-5);

    double numbers[] = { // add more funny numbers like PI, sqrt(2) and euler number 
        0., 
        1., 
        0.5, 
        99.9999999,                 // converted to 100
        -99.9999999,                // converted to 0
        3.34,
        sqrt(2),
        exp(1.0),
        M_PI,
        1e-1,
        1e-2,
        1e-3,
        1e-4,
        1e-5,                       // ouch... equals 0
        static_cast<float>(0xFFFF), 
        static_cast<float>(0x1FFFF) // outside of max value
    };

    std::cout << "NUM\t-> DEC.\t| HEX\n";
    for(double n : numbers){
        Festkommazahl temp(n);
        std::cout << n << "\t-> " << temp << "\t| 0x" << std::hex << temp.getRaw() << "\n";
    }

    uint32_t raws[] = {
        0x0000'0000,    // = 0
        0x0000'0001,    // = LSB (1 / 2^16)
        0x0000'8000,    // = 0.5
        0x0001'0000,    // = 1
        0x8000'0000,    // = MSB (2^15)
        0xFFFF'FFFF,    // = max
    };
    
    std::cout << "\nRAW/HEX\t-> DEC.\t\n";
    for(uint32_t r : raws){
        Festkommazahl temp{};
        temp.setRaw(r);
        std::cout << std::hex << "0x" << r << "\t-> " << temp << "\n";
    }

    std::cout << "\nHigher Precision 0x0000'0001\n";
    Festkommazahl temp{};
    temp.setRaw(0x0000'0001);
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n";

    std::cout << "\nHigher Precision 0xFFFF'FFFF\n";
    temp.setRaw(0xFFFF'FFFF);
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n";
    
    std::cout << "\nHigher Precision sqrt(2)\n";
    temp.set(sqrt(2));
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n"; 

    std::cout << "\nHigher Precision exp(1.0)\n";
    temp.set(exp(1.0));
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n"; 
    
    std::cout << "\nHigher Precision M_PI\n";
    temp.set(M_PI);
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n"; 

    std::cout << "\nHigher Precision 1e-5\n";
    temp.set(1e-5);
    std::cout << std::hex << std::setprecision(50) << "\t-> " << temp << "\n";
    // precision lost because min value is 1.525e-05 (> 1e-5)
}