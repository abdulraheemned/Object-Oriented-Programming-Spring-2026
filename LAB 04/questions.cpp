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
