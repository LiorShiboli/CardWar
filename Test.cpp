#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
#include "doctest.h"
TEST_CASE("throws"){
    Player player2("Bean");
    Player player1("Ender");
    //should be zero because no one got a deck but should not throw
    CHECK_NOTHROW(player1.cardesTaken());
    CHECK_NOTHROW(player2.stacksize());
    
    Game game(player1,player2);
    //check that before theres plays game cant print a winner but can print stats and log(should be empty but printable) but not last turn
    CHECK_THROWS(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_THROWS(game.printLastTurn());
    // check that he can in fact play turn 
    CHECK_NOTHROW(game.playTurn());
    //check that can display stats and stuff
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLastTurn());
    // check he can still play all(in the case that there was a definite tie{is very rare} should just play nothing)
    CHECK_NOTHROW(game.playAll());
    //check that he still print stats
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    //check the players still can turn the stats after all the plays
    CHECK_NOTHROW(player1.cardesTaken());
    CHECK_NOTHROW(player2.stacksize());
    // check that he can play all the turns left(0) but but cant play the rest
    CHECK_THROWS(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    //check that after throwing exception he can still display the stats,even if someone messed up by asking something he shouldnt
    // you shouldnt lose all info
    

}
TEST_CASE("throws"){
    Player player2("David lightman");
    Player player1("Magnus");
    CHECK(player1.cardesTaken()==0);
    CHECK(player2.stacksize()==0);
    Game game(player1,player2);
    //check cards have been given
    CHECK(player1.cardesTaken()==0);
    CHECK(player2.stacksize()==26);
    game.playTurn();
    CHECK(player1.stacksize()<26);
    //check that one of the players took cards(can be both in the case of a definite tie,though extremely unlikely, in which case they are supposed to split the deck)
    CHECK(player2.cardesTaken()>0);
    CHECK(player1.cardesTaken()>0);
    //check p1 and p2 still together have all cards
    CHECK(player1.cardesTaken()+player2.cardesTaken()+player1.stacksize()+player2.stacksize()== 52);
    game.playAll();
    //check players played all their cards
    CHECK(player2.stacksize()==0);
    CHECK(player1.stacksize()==0);
    //check p1 and p2 still together have all cards
    CHECK(player1.cardesTaken()+player2.cardesTaken()== 52);
    
    }
