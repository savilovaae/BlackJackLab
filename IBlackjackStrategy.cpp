#include "IBlackjackStrategy.h"

bool AlwaysHitStrategy::shouldTakeCard(Player &player) {
    return player.getScore() < 17;
}

bool NeverBustStrategy::shouldTakeCard(Player &player) {
    return player.getScore() < 12;
}

bool DealerBasedStrategy::shouldTakeCard(Player &player) {
    return player.getFlag();
//
}

bool IBlackjackStrategy::shouldTakeCard(Player &player) {
    return false;
}
