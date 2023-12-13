//
// Created by WonderKid on 24.11.2023.
//

#include "IBlackjackStrategy.h"

bool AlwaysHitStrategy::shouldTakeCard(Player &player, Card &dealerCard) {
    return player.getScore() < 17;
}

bool NeverBustStrategy::shouldTakeCard( Player &player, class Card &dealerCard) {
    return player.getScore() < 12;
}

bool DealerBasedStrategy::shouldTakeCard(Player &player, Card &dealerCard) {
    if (dealerCard.getValue() >= 7) {
        return player.getScore() < 17;
    }
    return player.getScore() < 12;
}

bool IBlackjackStrategy::shouldTakeCard(Player &player, Card &dealerCard) {
    return false;
}
