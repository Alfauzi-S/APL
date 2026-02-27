#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
    int hp;
};

void displayPlayer(Player *p) {
    cout << "Nama: " << p->name << endl;
    cout << "Score: " << p->score << endl;
    cout << "HP: " << p->hp << endl;
    cout << "------------------------\n";
}

int main() {
    Player player1 = {"Warrior", 100, 50};
    Player *ptr1 = &player1;

    Player player2 = {"Mage", 120, 40};
    Player *ptr2 = &player2;

    cout << "Data Player 1:\n";
    displayPlayer(ptr1);

    cout << "Data Player 2:\n";
    displayPlayer(ptr2);

    return 0;
}