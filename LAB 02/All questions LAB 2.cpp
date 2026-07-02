//1. Write a program in which a class named student has member variables name, roll_no,
//semester and section. Create 4 objects of this class to store data of 4 different students,
//now display data of only those students who belong to section A.
#include <iostream>
using namespace std;

class student{
	public:
	string name;
	int rollno;
	int semester;
	string section;
//	CONSTRUCTOR:
  student(string n, int r,int sem , string sec){  
  	name = n;
  	rollno = r;
  	semester = sem;
  	section = sec;
	}
//	DISPLAY FUNCTION:
  void display(){
  	cout<< name << " " << rollno << " " << semester << " " << section << endl;
	}
};
int main(){
//	OBJECTS:
  student s1("abdul", 190 , 2 , "D");
	student s2("ali",170 , 2 , "A");
	student s3("anas", 160 , 3 , "b");
	student s4("akber", 180 , 4 , "A");
	
	if (s1.section == "A") s1.display();
  if (s2.section == "A") s2.display();
  if (s3.section == "A") s3.display();
  if (s4.section == "A") s4.display();
  return 0;
}

//2. You are a programmer for the ABC Bank assigned to develop a class that models the basic
//workings of a bank account. The class should perform the following tasks:
//o Save the account balance.
//o Save the number of transactions performed on the account.
//o Allow deposits to be made to the account.
//o Allow with drawls to be taken from the account.
//o Report the current account balance at any time.
//o Report the current number of transactions at any time.
//Menu
//1. Display the account balance
//2. Display the number of transactions
//3. Display interest earned for this period
//4. Make a deposit
//5. Make a withdrawal
//6. Exit the program
#include <iostream>
using namespace std;

class BankAccount {
public:
    int balance;
    int transactions;

    BankAccount() {
        balance = 0;
        transactions = 0;
    }

    void deposit(int amount) {
        balance += amount;
        transactions++;
    }

    void withdraw(int amount) {
        balance -= amount;
        transactions++;
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() {
        cout << "Transactions: " << transactions << endl;
    }
};

int main() {
    BankAccount acc;

    acc.deposit(5000);
    acc.deposit(300);
    acc.withdraw(4000);

    acc.showBalance();
    acc.showTransactions();

    return 0;
}

//Q3. Create a class called Employee that includes three pieces of information as data
//members—a first name (type char* (DMA)), a last name (type string) and a monthly salary
//(type int). Your class should have a setter function that initializes the three data members.
//Provide a getter function for each data member. If the monthly salary is not positive, set it
//to 0. Write a test program that demonstrates class Employee’s capabilities. Create two
//Employee objects and display each object’s yearly salary. Then give each Employee a 10
//percent raise and display each Employee’s yearly salary again. Identify and add any other
//related functions to achieve the said goal.
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class employee{
	private:
		char* firstname;
		string lastname;
		int monthlySalary;
		
	public:
		employee(){
			firstname = NULL;
			lastname = "";
			monthlySalary = 0;
		}
		
		void setemployee(const char* fname, string lname, int salary){
			firstname = new char[strlen(fname) + 1];
			strcpy(firstname, fname);
			
			lastname = lname;
			
			if(salary > 0){
				monthlySalary = salary;
			}
			else{
				monthlySalary = 0;
			}
		}
		
		char* getFirstname(){
			return firstname;
		}
		
		string getLastname(){
			return lastname;
		}
		
		int getYearlysalary(){
			return monthlySalary * 12;
		}
		
		void Giveraise(){
			monthlySalary += monthlySalary * 0.10;
		}
		
		int getMonthlysalary(){
			return monthlySalary;
		}
		
		~employee(){
			delete[] firstname;
		}
};

int main(){
	employee e1, e2;
	
	e1.setemployee("Abdul", "Raheem", 50000);
	e2.setemployee("Ali", "khan", 60000);
	
	cout<<"\n===Yearly salary before raise===\n"<<endl;
	cout<<e1.getFirstname()<<" "<<e1.getLastname()<<": "<<e1.getYearlysalary()<<endl;
	cout<<e2.getFirstname()<<" "<<e2.getLastname()<<": "<<e2.getYearlysalary()<<endl;
	
	e1.Giveraise();
	e2.Giveraise();
	
	cout<<"\n===Yearly salary after raise===\n"<<endl;
	cout<<e1.getFirstname()<<" "<<e1.getLastname()<<": "<<e1.getYearlysalary()<<endl;
	cout<<e2.getFirstname()<<" "<<e2.getLastname()<<": "<<e2.getYearlysalary()<<endl;
	
	return 0;
}

//Q4. Write C++ code to represent a hitting game by using OOP concept. The details are as
//follows: This game is being played between two teams (i.e. your team and the enemy
//team). The total number of players in your team is randomly generated and stored
//accordingly. The function generates a pair of numbers and matches each pair. If the
//numbers get matched, the following message is displayed: “Enemy got hit by your team!”
//Otherwise, the following message is displayed: “You got hit by the enemy team!” The
//number of hits should be equal to the number of players in your team. The program should
//tell the final result of your team by counting the hits of both the teams. Consider the
//following sample output:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
    public:
        int players, wins, losses;

        Game() : players(rand() % 10 + 1), wins(0), losses(0) {}

        void hit(void) {
            int num1 = rand() % 5 + 1;
            int num2 = rand() % 5 + 1;
            cout << "Pair of Numbers:"<<endl;
            cout << "Number 1: " << num1 << endl;
            cout << "Number 2: " << num2 << endl;
            if (num1 == num2) {
                cout << "Enemy got hit by your team!" << endl;
                wins++;
            } else {
                cout << "You got hit by the enemy team!" << endl;
                losses++;
            }
        }

        void displayResult(void) {
            cout << "Game Over! ";
            if (wins > losses)
                cout << "You won" << endl;
            else if (losses > wins)
                cout << "You lost" << endl;
            else
                cout << "The game is a draw" << endl;
        }
};

int main(void) {
    srand(time(0));
    Game team;
    cout << "Number of players in the team: " << team.players << endl;
    for (int i = 0; i < team.players; i++)
        team.hit();
    team.displayResult();
    return 0;
}




