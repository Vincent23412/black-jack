#include <iostream>
#include <vector>
#include "poker.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main(){
    cout << "How many players?" << endl;
    int playerNum = 0;
    cin >> playerNum;
    int round = 0;
    cout << "How many rounds?" << endl;
    cin >> round;
    Game game(playerNum, round);

    game.playGame();


    //printAll();
}
