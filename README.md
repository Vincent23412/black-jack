# Black Jack Game Implementation in C++

This repository contains a C++ implementation of the classic card game, Black Jack. The project is structured into several components to encapsulate different aspects of the game, making it easy to understand, maintain, and extend.

## Components

The implementation is divided into the following main components, each residing in its own pair of header (`.h`) and implementation (`.cpp`) files:

- **Game Logic (`Game.h`, `Game.cpp`):** This component manages the rules and procedures of Black Jack, orchestrating the game flow, handling player actions, and determining the outcome of each round.

- **Poker Card (`Poker.h`, `Poker.cpp`):** Represents a poker card object, encapsulating attributes such as suit and rank, and providing functionalities related to individual cards.

- **Player (`Player.h`, `Player.cpp`):** Defines a player in the game, including attributes like the player's hand, and methods for player actions such as hit, stand, or bet.

## Game Flow

The game follows the standard rules of Black Jack. It begins by dealing two cards to each player and the dealer. Players then choose to hit (draw a card) or stand (end their turn) with the goal of getting as close to 21 points without going over. The dealer plays last, following a simple set of rules. The winner is determined based on the final hands.

## Screenshots

Below are screenshots demonstrating the game in action. They provide a glimpse into the user interface and game dynamics.

![image](https://github.com/Vincent23412/black-jack/assets/87458133/17b687ce-2823-499a-8f84-f3751371a2ff)
*Fig 1: Starting the game.*

![image](https://github.com/Vincent23412/black-jack/assets/87458133/9d1b5e79-4abe-4165-84e4-ed9fe0ca09bf)
*Fig 2: Player making a decision.*

![image](https://github.com/Vincent23412/black-jack/assets/87458133/fe723c85-f9ad-4877-b747-3fa245869132)
*Fig 3: End of a round showing the outcome.*

## How to Run

To compile and run the game, ensure you have a C++ compiler installed. Navigate to the project directory in your terminal, and run the following commands:

```bash
g++ -o blackjack Game.cpp Poker.cpp Player.cpp main.cpp
./blackjack


