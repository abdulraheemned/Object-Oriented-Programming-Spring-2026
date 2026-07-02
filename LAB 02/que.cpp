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
