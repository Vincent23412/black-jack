#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player(string name, int money){
    this->bet = 500;
    this->cardNum = 0;
    this->point = 0;
    setName(name);
    setMoney(money);
}

void Player::setBet(int bet){
    this->bet = bet;
}

void Player::setName(string name){
    this->name = name;
}

void Player::setMoney(int money){
    this->money = money;
}

void Player::printInfo(){
    cout << this->name << ": " << this->money << endl;
}

void Player::printCardList(){
    //cout << "inside function " << this->cardNum << endl;
    //this->cardList[0]->printCard();

    for (int i = 0 ; i < 7; i++){
        //cout << "i = " << i << endl;
        for (int j = 0 ; j < this->cardNum; j++){
            //cout << "j = " << j << endl;
            for (int k = 0 ; k < 11; k++){
                //cout << "k = " << k << endl;
                cout << this->cardList[j]->image[i][k];
            }
            cout << ' ';
        }
        cout << endl;

    }
}

void Player::printBankerCard(){
    for (int i = 0 ; i < 7; i++){
        for (int j = 0 ; j < this->cardNum; j++){
            for (int k = 0 ; k < 11; k++){
                if (j == 1){
                    cout << '*';
                }
                else{
                    cout << this->cardList[j]->image[i][k];
                }
            }
            cout << ' ';
        }
        cout << endl;

    }
}
