//2. In a virtual battle arena game called "Epic Clash," players control powerful
//characters to engage in intense battles against each other. Each character has
//distinct abilities and attributes, including health, attack power, and defense. Your
//task is to implement the Character class to encapsulate these attributes, provide
//getter and setter methods for them, and offer different constructors to create
//characters with various starting conditions.
//Encapsulation: Ensure that the character's attributes (health, attackPower, and
//defense) are private to the Character class, accessible only through appropriate
//getter and setter methods, allocated memory dynamically in heap.
//Constructors: Implement three constructors: A default constructor that initializes a
//character with standard starting values for health, attack power, and defense. A
//parameterized constructor that allows specifying custom values for health, attack
//power, and defense. A copy constructor that creates a new Character object by
//copying the data from an existing Character object.
#include <iostream>
using namespace std;

class Character {
private:
    int *health;
    int *attackPower;
    int *defense;

public:
    // Default Constructor
    Character() {
        health = new int(90);
        attackPower = new int(40);
        defense = new int(20);
    }

    // Parameterized Constructor
    Character(int h, int a, int d) {
        health = new int(h);
        attackPower = new int(a);
        defense = new int(d);
    }
    // Copy Constructor
    Character(const Character &c) {
        health = new int(*(c.health));
        attackPower = new int(*(c.attackPower));
        defense = new int(*(c.defense));
    }
    
    // Getters
    int getHealth() { return *health; }
    int getAttack() { return *attackPower; }
    int getDefense() { return *defense;
		 }
    // Setters
    void setHealth(int h) { *health = h; }
    void setAttack(int a) { *attackPower = a; }
    void setDefense(int d) { *defense = d; }
    
		void display() {
        cout << "Health: " << *health
             << ", Attack: " << *attackPower
             << ", Defense: " << *defense << endl;
    }
    
    // Destructor
    ~Character() {
        delete health;
        delete attackPower;
        delete defense;
    }
};
int main() {
    Character c1;
    Character c2(130, 100, 140);
    Character c3 = c2;
    
    c1.display();
    c2.display();
    c3.display();
    return 0;
}

