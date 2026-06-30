//Q1. Write a program that take input of your roll number along with the marks obtained
//in five subjects and display the total marks obtained and the percentage.
#include <iostream>
using namespace std;
int main(){
	int rollno;
	float marks,percentage;
	cout<<"Enter your Rollno and Marks obtained in five subjects: ";
	cin>> rollno >>marks;
	cout<<"Total Marks in five subjects: "<<marks<<endl;
	percentage = (marks/500)*100;
	cout<<"percentage is: "<<percentage << "%";
}
//Q2. Write a program to swap three numbers entered by a user using pointers.

int main(){

	int a, b, c, temp;

	int *pqa = &a;
	int *pqb = &b;
	int *pqc = &c;
	
	cout<<"Enter the value of a b c: "<<endl;
	cin>>a>>b>>c;
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	
	temp = *pqa;
	*pqa = *pqb;
	*pqb = *pqc;
	*pqc = temp;
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	
	return 0;
}

//Q3. Write a program to convert temp from Fahrenheit to Celsius unit using equation
//C=(F-32)/1.8
int main(){
	double fahrenheit;
	double celsius;
	
	cout<<"Enter temp in fahrenheit: "<<endl;
	cin>>fahrenheit;
	
	celsius = (fahrenheit - 32) / 1.8;
	
	cout<<"The temp in celsius is "<<celsius<<endl;
	
	return 0;
}

//Q4. Using 2-D arrays, write a program that allows the user to input two, 3x3 matrices.
//Write a function for adding two matrices. Write another function for multiplying
//the two matrices.
#include<iostream>
using namespace std;

void sumMatrix(int arrA[3][3], int arrB[3][3], int sum[3][3]){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			sum[i][j] = arrA[i][j] + arrB[i][j];
			 
		}
	}
}

void multiplyMatrix(int arrA[3][3], int arrB[3][3], int product[3][3]){
	int i,j,k;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			product[i][j] = 0;
			for(k=0; k<3; k++){
				product[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}
}

void display(int arr[3][3]){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
}
}

int main(){
	int arrA[3][3], arrB[3][3];
	int sum[3][3], product[3][3];
	int i,j,k;
	
	cout<<"Enter elements of first 3x3 matrix "<<endl;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			cin>>arrA[i][j];
		}
	}
	
	cout<<"Enter elements of second 3x3 matrix "<<endl;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			cin>>arrB[i][j];
		}
	}
	
	sumMatrix(arrA, arrB, sum);
	multiplyMatrix(arrA, arrB, product);
	
	cout<<"====Sum of Matrices===="<<endl;
	display(sum);
	
	cout<<"====Product of matrices===="<<endl;
	display(product);
	
	return 0;
}

//Q5. Write a program to find Surface area and volume of a sphere using functions.


float surfaceArea(float r){
	float surface;
	surface = 4 *3.14 *r *r;
	return surface;
}

float volSphere(float r){
	float vol;
	vol = (4.0/3.0) *(3.14) *r *r *r;
	return vol;
}

int main(){
	float r;
	cout<<"Enter the radius of sphere: "<<endl;
	cin>>r;
	
	surfaceArea(r);
	volSphere(r);
	
	cout<<"Surface Area of Sphere = "<<surfaceArea(r)<<endl;
	cout<<"Volume of Sphere = "<<volSphere(r)<<endl;
	
	return 0;
}

//Q6. Write a program to help a bank create its withdrawal system. Your program should
//allow the user to input their account type. Account types are: savings, current.
//Following business rules apply when withdrawing from a certain account:
//? Savings:
//User must provide the savings account number and code ‘S’ (for savings).
//When withdrawing from a savings account, users need to pay a set 2% of
//the money that they withdraw. If the amount of money withdrawn is over
//50,000, then a 5% tax will be deducted. The money deducted shall be from
//the remaining money in the account.
//? Current:
//User must provide the current account number and code „C" (for current).
//When withdrawing from a current account, users need to pay a withdrawal
//fee of 100. If the amount of money withdrawn is over 50,000, then a 5% tax
//will be deducted. The money deducted shall be from the remaining money
//in the account.
//Assume all users have the 200,000 in their accounts, and cannot withdraw more
//than 100,000 at a time.

int main() {
    char accountType;
    int accountNumber;
    float withdrawAmount;
    float balance = 200000;   // initial balance
    float deduction = 0;

    cout << "Enter account type (S for Savings, C for Current): ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;

    if (withdrawAmount > 100000) {
        cout << "Error: Cannot withdraw more than 100,000 at a time.";
        return 0;
    }

    if (accountType == 'S' || accountType == 's') {
        deduction = withdrawAmount * 0.02;   // 2% fee
        balance = balance - withdrawAmount - deduction;

        if (withdrawAmount > 50000) {
            balance = balance - (balance * 0.05);  // 5% tax
        }

        cout << "\nAccount Type: Savings";
    }

    else if (accountType == 'C' || accountType == 'c') {
        deduction = 100;  
        balance = balance - withdrawAmount - deduction;

        if (withdrawAmount > 50000) {
            balance = balance - (balance * 0.05); 
        }

        cout << "\nAccount Type: Current";
    }

    else {
        cout << "Invalid account type!";
        return 0;
    }

    cout << "\nAccount Number: " << accountNumber;
    cout << "\nWithdrawn Amount: " << withdrawAmount;
    cout << "\nRemaining Balance: " << balance;

    return 0;
}

