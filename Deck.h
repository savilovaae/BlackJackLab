#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H
#include "Card.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <memory>
#include <stdexcept>

class Deck {
public:
    Deck();

    Deck(size_t N);

    void reset();

    void shuffle();

    Card dealCard();

private:
    std::vector<Card> cards;
    size_t currentCardIndex;
    size_t deckSize;
};

#endif //BLACKJACK_DECK_H
