#include "player.hpp"
#include <string>
 namespace ariel
 {
    Player::Player(std::string name){

    }
    Player::~Player(){

    }
   int Player::cardesTaken(){
      return 5;
   }
   int Player::stacksize(){
      return 24;
   }
 }// namespace ariel
 