#include "Player.h"


void Player::takeCard(const Card &card) {
    hand.push_back(card);
    score = calculateScore(); // Пересчет очков после добавления карты
}

int Player::getScore() const {
    return score;
}

bool Player::decideTakeCard(const Card &dealerCard) {
    flag = strategy->shouldTakeCard(*this, const_cast<Card &>(dealerCard));
    return flag;
}

int Player::calculateScore() {
    int newScore = 0;
    for (const auto& card : hand) {
        newScore += card.getValue();
    }
    return newScore;
}

void Player::reset() {
    hand.clear();
    score = 0;
}

bool Player::getFlag() {
    return flag;
}