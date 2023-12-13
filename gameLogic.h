#ifndef BLACKJACK_GAMELOGIC_H
#define BLACKJACK_GAMELOGIC_H

#include <list>
#include "Dealer.h"
#include "Player.h"
#include "IBlackjackStrategy.h"

class Game {
public:
    enum Mode {
        detailed, fast, tournament
    };

    Game(Dealer dealer, const std::list <IBlackjackStrategy>& strategies, Mode mode);

    void run();

private:
    void runFast();
    void runDetailed(Player first, Player second);
    void runTournament();
    Dealer *dealer;
    std::list <IBlackjackStrategy> strategies;
    Mode mode;
};

#endif //BLACKJACK_GAMELOGIC_H
