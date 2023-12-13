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
        blackjack_test
        IBlackjackStrategy.h IBlackjackStrategy.cpp
        Player.h Player.cpp
        Card.h Card.cpp
        Deck.h Deck.cpp
        gameLogic.h gameLogic.cpp
        Dealer.h Dealer.cpp
        blackjack_test.cpp
)

target_link_libraries(
        blackjack_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(blackjack_test)