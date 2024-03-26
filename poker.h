#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED
#include <vector>
#include <iostream>

class poker{
public:
    char value;
    char type;
    //char image[20][20] = {0};
    std::vector<std::vector<char>> image;
    poker(char = 'A', char = 'D');
    void printCard();
    void setValue(char);
    void setType(char);
    void createImage();
};
void printAll();




#endif // POKER_H_INCLUDED
