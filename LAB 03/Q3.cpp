//3. Create a class tollbooth. The two data items are a type int to hold the total number
//of cars and a type double to hold the total amount of money collected. A
//constructor initializes both these to 0. When a car passes the toll, a member
//function called payingCar( ) increments the car total and adds 0.50 to the cash
//total. Another member function displays the two totals. DESIGN and IMPLEMENT
//this case. Make assumptions (if required) and include it in the description before
//designing the solution.
#include <iostream>
using namespace std;

class TollBooth {
private:
    int totalCars;
    double totalCash;

public:
    // Default Constructor
    TollBooth() {
        totalCars = 0;
        totalCash = 0.0;
    }

    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    void display() {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Cash: Rs. " << totalCash << endl;
    }
};

int main() {
    TollBooth booth;

    booth.payingCar();
    booth.payingCar();
    booth.payingCar();

    booth.display();
    return 0;
}

