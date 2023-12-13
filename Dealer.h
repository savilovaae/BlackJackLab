#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H
#include "Deck.h"
#include "Card.h"

class Dealer {
public:
    virtual ~Dealer();
    virtual Card giveCard();
};


class SimpleDealer : Dealer {
public:
    Dealer() = default;
    Card giveCard();
private:
    static const int deckSize = 10;
};


/*
class OneDeckDealer : Dealer {
public:
    Card giveCard();
    virtual void shuffle();
    virtual void reset();
    virtual void dealCard();
private:
    std::vector<Card> deck;
    size_t currCardIndex;
    size_t size;
};


class NDeckDealer : OneDeckDealer {
public:
    void shuffle();
    void reset();
    void dealCard();
};
*/


#endif //BLACKJACK_DEALER_H
