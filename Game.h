#include <vector>
#include "Player.h"
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game{
private:
    int playerNum;
    int round;
    int bet;
    int banker;
    std::vector<Player*> playerList;
    std::vector<bool> stillPlayingList;
    int winner;
    bool bankerAce;
public:
    Game(int, int);
    void setPlayer(int);
    void setRound(int);
    void printPlayerInfo();
    void playGame();
    void setPlayerBet();
    void sendCard();
    void askForInsurance(int);
    void doubleOrSurrender();
    void sendOneCard(int);
    void printAllCard();
    void showWinner();
    void resetGame();
    bool checkStraight(int);
    void finalWinner();
};



#endif // GAME_H_INCLUDED
