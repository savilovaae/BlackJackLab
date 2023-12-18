#include "Card.h"

Card::Card() : suit_(Hearts), face_(Ace), value_(1) {}

Card::Card(Suit suit, Face face) : suit_(suit), face_(face), value_(calculateValue(face)) {}

Card::~Card() {}

Card::Face Card::getFace() {
    return face_;
}

Card::Suit Card::getSuit() {
    return suit_;
}

int Card::getValue() const {
    return calculateValue(this->face_);
}

std::string Card::printCard() {
    return printFace(this->face_) + " " + printSuit(this->suit_);
}

std::string Card::printSuit(Suit suit) {
    std::string sSuit;
    switch (suit) {
        case Hearts:
            sSuit = "Hearts";
            break;
        case Diamonds:
            sSuit = "Diamonds";
            break;
        case Clubs:
            sSuit = "Clubs";
            break;
        default:
            sSuit = "Spades";
    }
    return sSuit;

}

std::string Card::printFace(Face face) {
    std::string sFace;
    switch (face) {
        case Ace:
            sFace = "Ace";
            break;
        case Two:
            sFace = "Two";
            break;
        case Three:
            sFace = "Three";
            break;
        case Four:
            sFace = "Four";
            break;
        case Five:
            sFace = "Five";
            break;
        case Six:
            sFace = "Six";
            break;
        case Seven:
            sFace = "Seven";
            break;
        case Eight:
            sFace = "Eight";
            break;
        case Nine:
            sFace = "Nine";
            break;
        case Ten:
            sFace = "Ten";
            break;
        case Jack:
            sFace = "Jack";
            break;
        case Queen:
            sFace = "Queen";
            break;
        default:
            sFace = "King";
    }
    return sFace;

}

int Card::calculateValue(Card::Face face) {
    if (face >= Two && face <= Ten) {
        return static_cast<int>(face);
    } else if (face >= Jack && face <= King) {
        return 10;
    } else if (face == Ace) {
        return 1;
    }
    return 0;
}



