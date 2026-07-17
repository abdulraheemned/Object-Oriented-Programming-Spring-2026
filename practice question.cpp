//PRACTICE QUESTION OOPS
//CODE
#include <iostream>
#include <cstring>
using namespace std;

class Student {
 char* name;
public:
 // default constructor
 Student() {
 name = new char[20];
 strcpy(name, "Unknown");
 cout << "Default constructor called\n";
 }
 
 // parameterized constructor
 Student(const char* n) {
 name = new char[20];
 strcpy(name, n);
 cout << "Parameterized constructor called\n";
 }
 
 // copy constructor (deep copy)
 Student(const Student& s) {
 name = new char[20];
 strcpy(name, s.name);
 cout << "Copy constructor called\n";
 }
 
 void setName(const char* n) {
 strcpy(name, n);
 }
 
 void display() {
 cout << "Name: " << name << endl;
 }
 
 // destructor
 ~Student() {
 cout << "Destructor called for " << name << endl;
 delete[] name;
 }
};

int main() {
 Student s1; // default constructor
 Student s2("Abdul Raheem Sheikh"); // parameterized constructor
 Student s3(s2); // copy constructor
 cout << "Student names:";
 
 s1.display();
 s2.display();
 s3.display();
 cout << "Changing copied student's name:";
 s3.setName("Ali");
 cout << "After change:";
 s2.display(); // original remains same
 s3.display(); // copied object changed
 cout << "End of main";
 return 0;
}
