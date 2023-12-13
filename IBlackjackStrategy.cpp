//
// Created by WonderKid on 24.11.2023.
//

#include "IBlackjackStrategy.h"

bool AlwaysHitStrategy::shouldTakeCard(const Player &player, const Card &dealerCard) const {
    return player.getScore() < 17;
}

bool NeverBustStrategy::shouldTakeCard(const Player &player, const Card &dealerCard) const {
    return player.getScore() < 12;
}

bool DealerBasedStrategy::shouldTakeCard(const Player &player, const Card &dealerCard) const {
    if (dealerCard.getValue() >= 7) {
        return player.getScore() < 17;
    }
    return player.getScore() < 12;
}