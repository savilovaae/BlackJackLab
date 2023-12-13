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

    Card(Suit suit, Face face);

    ~Card();

    Suit getSuit();

    Face getFace();

    [[nodiscard]] int getValue() const;

    std::string printCard();


private:
    int value;
    Face face;
    Suit suit;

    static int calculateValue(Face face) {
        if (face >= Two && face <= Ten) {
            return static_cast<int>(face);
        } else if (face >= Jack && face <= King) {
            return 10;
        } else if (face == Ace) {
            return 1;
        }
        return 0;
    }

};

#endif //BLACKJACK_CARD_H
