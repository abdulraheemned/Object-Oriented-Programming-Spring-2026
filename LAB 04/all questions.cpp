//QUESTION 1:
//Create a class ‘Employee’ having two data members 
//‘EmployeeName’ (char*) and ‘EmployeeId’ (int). Keep both data members private. Create three initialized 
//objects ‘Employee1’, ‘Employee2’ and ‘Employee3’ of type ‘Employee’ in such a way that the employee name for each 
//employee can be changed when required but the employee Id for each employee must be initialized only once and 
//should remain same always. Use member initializer list, accessors/getters and mutators/setters for appropriate 
//data members. The result must be displayed by calling the accessors.
#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* EmployeeName;
    const int EmployeeId;

public:
    Employee(const char* name, int id) : EmployeeId(id) {
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    void setName(const char* name) {
        delete[] EmployeeName;
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    const char* getName() const {
        return EmployeeName;
    }

    int getId() const {
        return EmployeeId;
    }

    ~Employee() {
        delete[] EmployeeName;
    }
};

int main() {
    Employee Employee1("Ali", 101);
    Employee Employee2("Ahmed", 102);
    Employee Employee3("Sara", 103);

    Employee1.setName("Ali Khan");

    cout << Employee1.getName() << " - " << Employee1.getId() << endl;
    cout << Employee2.getName() << " - " << Employee2.getId() << endl;
    cout << Employee3.getName() << " - " << Employee3.getId() << endl;

    return 0;
}



//QUESTION 2:
//Create a class called DynamicArray. The class should 
//contain a pointer to the array, and size of the array as 
//data members. Create the parameterized constructor 
//which takes size of the array as input and initializes 
//all the values with 0. Create the member function 
//“push” which takes value as parameter and push it to 
//the end of the array. Create the member function size() 
//which returns the size of the array.
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity;
    int currentSize;

public:
    DynamicArray(int size) {
        capacity = size;
        currentSize = 0;
        arr = new int[capacity];

        for(int i = 0; i < capacity; i++)
            arr[i] = 0;
    }

    void push(int value) {
        if(currentSize < capacity) {
            arr[currentSize++] = value;
        } else {
            cout << "Array is full!" << endl;
        }
    }

    int size() const {
        return currentSize;
    }

    void display() const {
        for(int i = 0; i < currentSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray d(5);
    d.push(10);
    d.push(20);
    d.push(30);

    d.display();
    cout << "Current Size: " << d.size() << endl;

    return 0;
}



QUESTION 3:
Write a program in which a class named Account has 
private member variables named account_no, account_bal, 
security_code. Use a public function to initialize the 
variables and print all data. Keep track of number of 
objects using the keyword static.

#include <iostream>
using namespace std;

class Account {
private:
    int account_no;
    double account_bal;
    int security_code;
    static int objectCount;

public:
    void initialize(int no, double bal, int code) {
        account_no = no;
        account_bal = bal;
        security_code = code;
        objectCount++;
    }

    void display() const {
        cout << "Account No: " << account_no << endl;
        cout << "Balance: " << account_bal << endl;
        cout << "Security Code: " << security_code << endl;
    }

    static void showObjectCount() {
        cout << "Total Accounts Created: " << objectCount << endl;
    }
};

int Account::objectCount = 0;

int main() {
    Account a1, a2;

    a1.initialize(1001, 50000, 1234);
    a2.initialize(1002, 70000, 5678);

    a1.display();
    a2.display();

    Account::showObjectCount();

    return 0;
}



//QUESTION 4:
//By considering a scenario of your own choice, write a 
//program to demonstrate the concept of constant keyword.
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    const int rollNo;
    float cgpa;

public:
    Student(string n, int r, float c) : rollNo(r) {
        name = n;
        cgpa = c;
    }

    void setCGPA(float c) {
        cgpa = c;
    }

    int getRollNo() const {
        return rollNo;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1("Ali", 202401, 3.5);
    s1.setCGPA(3.8);
    s1.display();

    return 0;
}



//QUESTION 5:
//“Hotel Mercato” requires a system module that will help 
//the hotel to calculate the rent of the customers.
//
//Requirements:
//- The hotel wants such a system that should have the 
//  feature to change the implementation independently 
//  of the interface.
//- The hotel charges each customer 1000.85 per day.
//  This amount cannot be changed.
//- If customer stays more than a week, he gets discount.
//- Discounted rent is calculated after subtracting 
//  one day from total days.
//- Display:
//    Customer name
//    Days
//    Rent
//- The display function must not modify any data member.

#include <iostream>
using namespace std;

class HotelMercato {
private:
    string customerName;
    int days;
    static constexpr double rentPerDay = 1000.85;

    double calculateRent() const {
        if(days > 7) {
            return (days - 1) * rentPerDay;
        }
        return days * rentPerDay;
    }

public:
    HotelMercato(string name, int d) {
        customerName = name;
        days = d;
    }

    void display() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Days: " << days << endl;
        cout << "Rent: " << calculateRent() << endl;
    }
};

int main() {
    HotelMercato h1("Ahmed", 10);
    h1.display();

    return 0;
}

