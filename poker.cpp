#include "poker.h"
#include <iostream>
#include <string>
#include <vector>

poker::poker(char v, char t) : image(20, std::vector<char>(20, ' ')) {
    setValue(v);
    setType(t);
    createImage();
}

void poker::setValue(char v){
    if (v == 'A' || (v >= '2' && v <= '9') || v == 'T' || v == 'J' || v == 'Q' || v == 'K') {
        value = v;
    }
}

void poker::setType(char t){
    if (t == 'H' || t == 'D' || t == 'C' || t == 'S') {
        type = t;
    }
}

void poker::printCard(){
    std::cout << "value: " << value << "," << "type: " << type << std::endl;
    for (int i = 0 ; i < 7; i++){
        for (int j = 0 ; j < 11 ; j++){
            std::cout << image[i][j];
        }
        std::cout << std::endl;
    }
}

void poker::createImage(){
    // 愛心 (H)
    if (type == 'H') {
        image[0] = {value, value, value, value, value, value, value, value, value, value, value};
        image[1] = {value, ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', value};
        image[2] = {value, '*', '*', '*', '*', '*', '*', '*', '*', '*', value};
        image[3] = {value, ' ', '*', '*', '*', '*', '*', '*', '*', ' ', value};
        image[4] = {value, ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', value};
        image[5] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[6] = {value, value, value, value, value, value, value, value, value, value, value};
    }

    // 方塊 (D)
    else if (type == 'D') {
        image[0] = {value, value, value, value, value, value, value, value, value, value, value};
        image[1] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[2] = {value, ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', value};
        image[3] = {value, '*', '*', '*', '*', '*', '*', '*', '*', '*', value};
        image[4] = {value, ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', value};
        image[5] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[6] = {value, value, value, value, value, value, value, value, value, value, value};
    }
    // 梅花（C）
    else if (type == 'C') {
        image[0] = {value, value, value, value, value, value, value, value, value, value, value};
        image[1] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[2] = {value, ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', value};
        image[3] = {value, ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', value};
        image[4] = {value, '*', '*', '*', '*', '*', '*', '*', '*', '*', value};
        image[5] = {value, ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', value};
        image[6] = {value, value, value, value, value, value, value, value, value, value, value};
    }
    // 黑桃（S）
    else if (type == 'S') {
        image[0] = {value, value, value, value, value, value, value, value, value, value, value};
        image[1] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[2] = {value, ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', value};
        image[3] = {value, ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', value};
        image[4] = {value, ' ', '*', '*', '*', '*', '*', '*', '*', ' ', value};
        image[5] = {value, ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', value};
        image[6] = {value, value, value, value, value, value, value, value, value, value, value};
    }
}



void printAll(){
    char printType;
    int row;
    std::cout << "input type(H, D, C, S)" << std::endl;
    std::cin >> printType;
    std::cout << "input row" << std::endl;
    std::cin >> row;

    std::vector<char>cardList = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    std::vector<poker> card;
    for (int i = 0 ; i < 13; i++){
        card.push_back(poker(cardList[i], printType));
    }


    std::vector<int> rowArea = {};
    int temp_count = 0;
    while (temp_count < 13){
        rowArea.push_back(temp_count);
        temp_count += row;
    }
    rowArea.push_back(13);
    //std::cout << rowArea[5];
    //std::cout << rowArea.size();

    //for (int i = 0 ; i < rowArea.size(); i++)
    //    std::cout << rowArea[i] << ' ';
    //std::cout << std::endl;

    for (int num = 0 ; num < rowArea.size()-1; num++){
        for (int j = 0 ; j < 7; j++){
            for (int i = rowArea[num] ; i < rowArea[num+1]; i++){
                for (int k = 0 ; k < 11; k++){
                    std::cout << card[i].image[j][k];
                }
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
}
