/*
 * 1. считывание данных с консоли для начала игры
 * 2. в зависимости от количества игроков - создание игроков
 * 3. проверка количества стратегий и мода переданного в консоль. если не совпало = выкидывать исключение
 * 4. бизнес логика игры :
            дилер выдает карту - игрок берет карту - проверка флага - другой берет карту - проверка флага
            игроки берут карты пока флаг тру. каждый раз когда берут карту меняется флаг
            как только ОБА флага фолс то карты не берутся и конец игры

            вывод результатов игры
 * 5. модульные тесты на основные методы классов
 * 6. покрытие тестами бизнес-логики???
1.создать дилера с колодой для выдачи кард в зависимости от режима игры
2. перемешать колоду
3. дилер хранит колоду карт, не существует класса деки

input :
дилер
режим турнир/быстрый/подробный
стратегия 1 стратегия 2 ...


 турнир: K players, all of them play with somebody else and we need to find the winner of tournament
*/
#include <iostream>
#include "gameLogic.h"

Game::Game(Dealer dealer, const std::list <IBlackjackStrategy>& strategies, Mode mode) : dealer(&dealer), mode(mode) {
    switch (mode) {
        case detailed:
            if (strategies.size() != 2) {
                throw std::invalid_argument("Стратегий должно быть 2");
            } break;
        case fast:
            if (strategies.size() != 2) {
                throw std::invalid_argument("Стратегий должно быть 2");
            } break;
        case tournament:
            break;
    }

}

void Game::run() {
    auto player1 = new Player();
    auto player2 = new Player();
    switch (mode) {
        case detailed:
            Game::runDetailed(*player1, *player2);
            break;
        case fast:
            //runFast(player1, player2);
            break;
        case tournament:
            break;
    }
}

void Game::runFast() {

}

void Game::runDetailed(Player player1, Player player2) {
    auto tmp = *new Card(Card::Hearts, Card::Two);
    while (player1.getFlag() && player2.getFlag()) {
        tmp = dealer->giveCard();
        player1.takeCard(tmp); //первый игрок взял карту
        std::cout << "Первый игрок взял карту " + tmp.printCard() << std::endl;
        tmp = dealer->giveCard();
        player2.takeCard(tmp); //второй игрок взял карту
        std::cout << "Второй игрок взял карту " + tmp.printCard() << std::endl;
    }

    while (player1.getFlag()) {
        tmp = dealer->giveCard();
        player1.takeCard(tmp); //первый игрок взял карту
        std::cout << "Первый игрок взял карту " + tmp.printCard() << std::endl;
    }

    while (player2.getFlag()) {
        tmp = dealer->giveCard();
        player2.takeCard(dealer->giveCard()); //второй игрок взял карту
        std::cout << "Второй игрок взял карту " + tmp.printCard() << std::endl;
    }
    //конец игры тут
    if (player1.getScore() > player1.getScore()) {
        std::cout << "Первый игрок победил" << std::endl;
    } else if (player1.getScore() < player2.getScore()) {
        std::cout << "Второй игрок победил" << std::endl;
    } else {
        std::cout << "Игроки сыграли вничью" << std::endl;
    }
}