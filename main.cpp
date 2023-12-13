#include <iostream>
#include "Card.h"
#include "Player.h"

int main() {
    Card AceDiamonds(Card::Diamonds, Card::Ace);
    auto *first = new Player();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
