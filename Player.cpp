#include "Player.h"

bool Player::getFlag() const {
    return flag_;
}

int Player::getScore() const {
    return score_;
}

void Player::takeCard(const Card &card) {
    hand_.push_back(card);
    score_ = calculateScore();
    if (strategy_) flag_ = strategy_->shouldTakeCard(*this);
}

int Player::calculateScore() {
    int score = 0;
    for (const auto &card: hand_) {
        score += card.getValue();
    }
    return score;
}

void Player::reset() {
    hand_.clear();
    score_ = 0;
}

