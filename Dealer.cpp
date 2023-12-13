#include "Dealer.h"
#include <random>


Card SimpleDealer::giveCard() {
    return Card(Card::Hearts, Card::Two);
}




/*
Card OneDeckDealer::giveCard() {
    return
}


void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    currentCardIndex = 0;
}

//-
void Deck::reset() {
    cards.clear();
    for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
        for (int face = Card::Two; face <= Card::Ace; ++face) {
            cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Face>(face));
        }
    }
    currentCardIndex = 0;
}

Card Deck::dealCard() {
    if (currentCardIndex >= cards.size()) {
        throw std::out_of_range("No more cards in the deck");
    }
    return cards[currentCardIndex++];
}*/