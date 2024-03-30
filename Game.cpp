#include "Game.h"
#include "Player.h"
#include "poker.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

Game::Game(int playerNum, int round){
    setPlayer(playerNum);
    setRound(round);
    this->bet = 500;
    this->bankerAce = false;
    srand(time(0));
    int randomNum = rand();
    this->banker = randomNum % this->playerNum;
    for (int i = 0; i < this->playerNum; i++) {
        stillPlayingList.push_back(true);
    }

}

void Game::setPlayer(int playerNum){
    while (playerNum < 1 || playerNum > 4){
        cout << "please enter playerNum between 0 to 4" << endl;
        cin >> playerNum;
    }
    vector<string>List = {"player1", "player2", "player3", "player4"};
    this->playerNum = playerNum;
    for (int i = 0 ; i < playerNum; i++){
        Player *player = new Player(List[i]);
        this->playerList.push_back(player);
    }
}

void Game::setRound(int round){
    while (round < 1){
        cout << "please set round greater than 0" << endl;
        cin >> round;
    }
    this->round = round;
}

void Game::printPlayerInfo(){
    cout << "The banker is " << (this->playerList)[this->banker]->name << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        (this->playerList)[i]->printInfo();
    }
}

void Game::setPlayerBet(){
    for (int i = 0 ; i < this->playerNum; i++){
        if (i != this->banker){
            int bet = 0;
            while (bet < this->bet){
                cout << (this->playerList)[i]->name << ", please enter your bet: " << endl;
                cout << "please enter higher than " << this->bet << endl;
                cin >> bet;
            }
            (this->playerList)[i]->setBet(bet);
        }
    }
    for (int i = 0 ; i < this->playerNum; i++){
        if (i != this->banker){
            cout << (this->playerList)[i]->name << "'s bet is " << (this->playerList)[i]->bet << endl;
        }
    }
}

char changeNum(int num){
    if (num == 0) return 'A';
    else if (num == 9) return 'T';
    else if (num == 10) return 'J';
    else if (num == 11) return 'Q';
    else if (num == 12) return 'K';
    return static_cast<char>(num + 1 + '0');;
}

void Game::sendCard(){
    for (int i = 0 ; i < this->playerNum; i++){
        //cout << (this->playerList)[i]->name << endl;
        int randomNum = rand() % 13;
        char cardNum = changeNum(randomNum);
        //cout << randomNum << ':' << cardNum << endl;

        poker *card = new poker(cardNum);
        //card->printCard();
        (this->playerList)[i]->cardList.push_back(card);
        this->playerList[i]->cardNum++;
        if (randomNum == 10 || randomNum == 11 || randomNum == 12){
            randomNum = 9;
        }

        if (randomNum == 0){
            int random = rand() % 2;
            if (random == 1){
                randomNum = 9;
                cout << "we suggest your A should be 10 point" << endl;
            }
            else{
                randomNum = 1;
                cout << "we suggest your A should be 1 point" << endl;
            }
        }


        this->playerList[i]->point += randomNum + 1;
    }
    int askInsurance = 0;
    cout << "----------------------------------------------------------------------------------" << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        if ((this->playerList)[this->banker]->name == (this->playerList)[i]->name){
            cout << "Banker: ";
            cout << "player " << i + 1 << endl;
        }
        else{
            cout << "player " << i + 1 << endl;
            cout << "now point " << this->playerList[i]->point << endl;
        }

        if ((this->playerList)[this->banker]->name == (this->playerList)[i]->name){
            this->playerList[i]->printBankerCard();
            if (this->playerList[i]->cardList[0]->value == 'A'){
                askInsurance = 1;
            }
        }
        else{
            this->playerList[i]->printCardList();
        }
        cout << "----------------------------------------------------------------------------------" << endl;
    }
    if (askInsurance && (this->playerList)[this->banker]->cardNum == 2){
        askForInsurance(this->banker);
        this->bankerAce = true;
    }
}

void Game::sendOneCard(int i){
    //cout << (this->playerList)[i]->name << endl;


    int randomNum = rand() % 13;
    char cardNum = changeNum(randomNum);
    //cout << randomNum << ':' << cardNum << endl;

    poker *card = new poker(cardNum);
    card->printCard();
    (this->playerList)[i]->cardList.push_back(card);

    this->playerList[i]->cardNum++;
    if (randomNum == 10 || randomNum == 11 || randomNum == 12){
        randomNum = 9;
    }

    if (randomNum == 0){
        int random = rand() % 2;
        if (random == 1){
            randomNum = 9;
            cout << "we suggest your A should be 10 point" << endl;
        }
        else{
            randomNum = 1;
            cout << "we suggest your A should be 1 point" << endl;
        }
    }


    this->playerList[i]->point += randomNum + 1;
    cout << "you're now " << this->playerList[i]->point << " points" << endl;
}

void Game::printAllCard(){
    cout << "----------------------------------------------------------------------------------" << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        if ((this->playerList)[this->banker]->name == (this->playerList)[i]->name){
            cout << "Banker: ";
        }
        cout << "player " << i + 1 << endl;
        cout << "now point " << this->playerList[i]->point << endl;
        if (!this->stillPlayingList[i]){
            //this->playerList[i]->printCardList();
            vector<vector<char>> Loser(7, vector<char>(20, ' '));
            Loser[0] = {'*', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', '*','*','*','*'};
            Loser[1] = {'*', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', '*', '*',' ',' ',' '};
            Loser[2] = {'*', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', '*',' ',' ',' '};
            Loser[3] = {'*', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', '*','*','*','*'};
            Loser[4] = {'*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '*',' ',' ',' '};
            Loser[5] = {'*', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', '*', '*',' ',' ',' '};
            Loser[6] = {'*', '*', '*', ' ', '*', '*', ' ', '*', '*', ' ', '*','*','*','*'};
            for (int i = 0 ; i < 7; i++){
                for (int j = 0 ; j < 14; j++){
                    cout << Loser[i][j];
                }
                cout << endl;
            }

            cout << endl;
        }
        else{
            this->playerList[i]->printCardList();
        }
        cout << "----------------------------------------------------------------------------------" << endl;
    }
}


void Game::askForInsurance(int bankId){
    cout << "Banker: Player" << bankId + 1 << " gets Ace" << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        if (i == bankId){
            continue;
        }
        cout << this->playerList[i]->name << ", do you want to buy insurance?(Type 0 for not)" << endl;
        int want = 0;
        cin >> want;
        this->playerList[i]->insurance = want;
    }
}

void Game::doubleOrSurrender(){
    for (int i = 0 ; i < this->playerNum; i++){
        if (i != this->banker){
            cout << "hello "<< this->playerList[i]->name << endl;
            cout << "Double or Surrend(1 for double, 2 for Surrend 3 for continue as ususal" << endl;
            int ask;
            cin >> ask;
            if (ask == 1){
                this->playerList[i]->bet *= 2;
                cout << "set your bet to " << playerList[i]->bet << endl;
            }
            else if (ask == 2){
                this->playerList[i]->money -= this->playerList[i]->bet;
                this->playerList[this->banker]->money += this->playerList[i]->bet;
                cout << this->playerList[i]->name << ", you lose, you now have " << this->playerList[i]->money << endl;
                this->stillPlayingList[i] = false;
            }
            else{
                cout << this->playerList[i]->name << " remain your bet: " << this->playerList[i]->bet << endl;
            }
        }
    }
}

bool Game::checkStraight(int i){
    int six = 0, seven = 0, eight = 0;
    for (int i = 0 ; i < this->playerList[i]->cardNum; i++){
        if (this->playerList[i]->cardList[i]->value == 6){
            six++;
        }
        if (this->playerList[i]->cardList[i]->value == 7){
            seven++;
        }
        if (this->playerList[i]->cardList[i]->value == 8){
            eight++;
        }
    }
    if (six > 0 && seven > 0 && eight > 0){
        cout << "you got a straight" << endl;
        return true;
    }
    return false;
}

void Game::showWinner(){
    int maxPlayer = 0;
    int maxPoint = 0;
    cout << "showWinner" << endl;;
    for (int i = 0; i < this->playerNum; i++){
        cout << "showWinner2" << endl;
        if (checkStraight(i)){
            maxPlayer = i;
            maxPoint = this->playerList[i]->point;
            this->playerList[i]->money += 3 * this->playerList[i]->bet;
            this->playerList[this->banker]->money -= 3 * this->playerList[i]->bet;
            this->stillPlayingList[i] = 0;
            break;
        }
        if (this->playerList[i]->cardNum == 5 && this->stillPlayingList[i]){
            this->playerList[i]->money += 3 * this->playerList[i]->bet;
            this->playerList[this->banker]->money -= 3 * this->playerList[i]->bet;
            this->stillPlayingList[i] = 0;
        }

        if (this->playerList[i]->point > maxPoint && this->stillPlayingList[i]){
            maxPlayer = i;
            maxPoint = this->playerList[i]->point;
        }
    }
    cout << "showWinner3" << endl;;
    cout << endl;
    cout << "winner is " << this->playerList[maxPlayer]->name << endl;
    this->winner = maxPlayer;
    cout << endl;
    if (maxPlayer == this->banker){
        for (int i = 0 ; i < this->playerNum; i++){
            if (i != this->banker){
                cout << this->playerList[i]->bet << endl;
                this->playerList[this->banker]->money += this->playerList[i]->bet;
                if (this->bankerAce && this->playerList[i]->insurance != 0){
                    if (this->playerList[this->banker]->point == 21){
                        this->playerList[i]->money += this->playerList[i]->insurance * 2;
                        this->playerList[this->banker]->money -= this->playerList[i]->insurance * 2;
                    }
                    else{
                        this->playerList[i]->money -= this->playerList[i]->insurance;
                        this->playerList[this->banker]->money += this->playerList[i]->insurance ;
                    }
                }

                if (this->stillPlayingList[i]){
                    this->playerList[i]->money -= this->playerList[i]->bet;
                }
            }

        }
    }
    else{
        for (int i = 0 ; i < this->playerNum; i++){
            if (this->stillPlayingList[i]){
                this->playerList[this->banker]->money -= this->playerList[i]->bet;
                this->playerList[i]->money += this->playerList[i]->bet;
            }
        }
    }
    cout << "end of this round" << endl;
    cout << "now score" << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        cout << this->playerList[i]->name << ": " << this->playerList[i]->money << endl;
    }
    cout << endl << endl;
}

void Game::resetGame(){
    this->banker = this->winner;
    this->winner = -1;
    this->bankerAce = false;
    for (int i = 0 ; i < this->playerNum; i++){
        this->playerList[i]->cardList.clear();
        this->playerList[i]->bet = 0;
        this->playerList[i]->cardNum = 0;
        this->playerList[i]->insurance = 0;
        this->playerList[i]->point = 0;
    }
}


void Game::finalWinner(){
    cout << endl;
    cout << "end of the game" << endl;

    for (int i = this->playerNum - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            //cout << this->playerList[j]->money << ", " << this->playerList[j+1]->money << endl;
            if (this->playerList[j]->money < this->playerList[j+1]->money){
                Player *temp = this->playerList[j];
                this->playerList[j] = this->playerList[j+1];
                this->playerList[j+1] = temp;
            }
        }
    }
    cout << "final winner" << endl;
    for (int i = 0 ; i < this->playerNum; i++){
        cout << "The " << i + 1  << " price is "<< this->playerList[i]->name << " the point is " << this->playerList[i]->money << endl;
    }
}


void Game::playGame(){
    for (int i = 0 ; i < this->round; i++){
        cout << endl;
        cout << "round " << i + 1 << endl;
        cout << endl;
        printPlayerInfo();
        cout << endl;
        setPlayerBet();
        cout << endl;
        sendCard();
        sendCard();
        doubleOrSurrender();

        for (int i = 0 ; i < this->playerNum; i++){
            if (i != this->banker && this->stillPlayingList[i]){
                bool doubleChance = false;
                cout << this->playerList[i]->name << " your point is " << this->playerList[i]->point <<", do you want to add a card?";
                int addCard = 1;
                cin >> addCard;
                if (this->playerList[i]->point == 11){
                    cout << "You are 11 point now, you have a chance to double your bet, but you can only get one more card" << endl;
                    cin >> doubleChance;
                    if (doubleChance){
                        this->playerList[i]->bet *= 2;
                        cout << "your bet is now " << this->playerList[i]->bet << endl;
                    }
                }
                while (addCard){
                    if (addCard){
                        sendOneCard(i);
                        if (this->playerList[i]->point> 21){
                            cout << "Bomb" << endl;
                            this->stillPlayingList[i] = false;
                            break;
                        }
                        if (doubleChance){
                            break;
                        }

                        cout << "add another card" << endl;
                        cin >> addCard;
                    }
                }
            }
        }

        printAllCard();
        cout << "it banker's turn" << endl;
        cout << "your point is now " << this->playerList[this->banker]->point << endl;

        bool bankBomb = false;
        while (this->playerList[this->banker]->point < 17){
            cout << "you should at least 17 points" << endl;
            sendOneCard(this->banker);
            if (this->playerList[this->banker]->point > 21){
                cout << "Bomb" << endl;
                this->stillPlayingList[this->banker] = false;
                bankBomb = true;
                break;
            }
        }
        if (!bankBomb){
            cout << this->playerList[this->banker]->name <<", do you want to add a card?";
            int addCard = 1;
            cin >> addCard;
            while (addCard){
                if (addCard){
                    sendOneCard(this->banker);
                    if (this->playerList[this->banker]->point > 21){
                        cout << "Bomb" << endl;
                        this->stillPlayingList[this->banker] = false;
                        break;
                    }
                    cout << "add another card" << endl;
                    cin >> addCard;
                }
            }
        }
        printAllCard();
        if (i < this->round){
            showWinner();
        }
        resetGame();
    }
    finalWinner();
}
