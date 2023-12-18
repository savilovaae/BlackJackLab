#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <string>

class Card {
public:
    enum Suit {
        Hearts, Diamonds, Clubs, Spades
    };
    enum Face {
        Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
    };

    Card();

    Card(Suit suit, Face face);

    ~Card();

    Suit getSuit();

    Face getFace();

    [[nodiscard]] int getValue() const;

    std::string printCard();


private:
    int value_;
    Face face_;
    Suit suit_;

    static int calculateValue(Face face);

    static std::string printFace(Face face);

    static std::string printSuit(Suit suit);
};

#endif //BLACKJACK_CARD_H
