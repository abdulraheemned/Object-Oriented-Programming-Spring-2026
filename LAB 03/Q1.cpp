//1. Write a C++ program to copy the value of one object to another object using copy
//constructor. For example you can define a class for complex number and create its
//object for performing this task. Remember that you must allocate memory
//dynamically to data members.
#include <iostream>
using namespace std;

class Complex {
private:
    int *even;
    int *odd;

public:
    // Parameterized Constructor
    Complex(int e, int o) {
        even = new int;
        odd = new int;
        *even = e;
        *odd = o;
    }

    // Copy Constructor
    Complex(const Complex &c) {
        even = new int;
        odd = new int;
        *even = *(c.even);
        *odd = *(c.odd);
    }

    void display() {
        cout << "Complex Number: " << *even << " + " << *odd << "i" << endl;
    }
    // Destructor
    ~Complex() {
        delete even;
        delete odd;
    }
};
int main() {
//	    Constructor called
    Complex c1(2, 5);  
//    Copy constructor called
		Complex c2(c1);  

    c1.display();
    c2.display();
    return 0;
}

