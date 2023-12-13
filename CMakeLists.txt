cmake_minimum_required(VERSION 3.23)
project(BlackJackLab)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        BlackJackLab
        IBlackjackStrategy.cpp IBlackjackStrategy.h
        Player.h Player.cpp
        Card.cpp Card.h
        Deck.cpp Deck.h
        blackjack_test.cpp
        gameLogic.cpp
        Dealer.cpp
        Dealer.h
        gameLogic.h
        main.cpp
)

target_link_libraries(
        BlackJackLab
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(blackjack_test.cpp)