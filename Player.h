#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>
#include "poker.h"

using namespace std;

class Player {
//private:
public:
    string name;
    int money;
    int bet;
    int cardNum;
    vector<poker*>cardList;
    int insurance;
    int point;

//public:
    Player(string, int = 10000);
    void setName(string);
    void setMoney(int);
    void printInfo();
    void setBet(int);
    void printCardList();
    void printBankerCard();
};

#endif // PLAYER_H_INCLUDED
