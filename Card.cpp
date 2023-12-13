#include "Card.h"

Card::Card(Suit suit, Face face) : suit(Hearts), face(Ace), value(1) {}

Card::~Card() {
    delete this;
}

Card::Face Card::getFace() {
    return face;
}

Card::Suit Card::getSuit() {
    return suit;
}

int Card::getValue() const {
    return calculateValue(this->face);
}

std::string Card::printCard() {
    std::string suitStr, faceStr;
    switch (this->suit) {
        case Hearts:
            suitStr = "Hearts";
            break;
        case Diamonds:
            suitStr = "Diamonds";
            break;
        case Clubs:
            suitStr = "Clubs";
            break;
        default:
            suitStr = "Spades";
    }
    switch (this->face) {
        case Ace:
            faceStr = "Ace";
            break;
        case Two:
            faceStr = "Two";
            break;
        case Three:
            faceStr = "Three";
            break;
        case Four:
            faceStr = "Four";
            break;
        case Five:
            faceStr = "Five";
            break;
        case Six:
            faceStr = "Six";
            break;
        case Seven:
            faceStr = "Seven";
            break;
        case Eight:
            faceStr = "Eight";
            break;
        case Nine:
            faceStr = "Nine";
            break;
        case Ten:
            faceStr = "Ten";
            break;
        case Jack:
            faceStr = "Jack";
            break;
        case Queen:
            faceStr = "Queen";
            break;
        default:
            faceStr = "King";
    }
    return faceStr + " " + suitStr;
}

