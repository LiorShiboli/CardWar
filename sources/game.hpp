#include "player.hpp"
namespace ariel
{
    #ifndef GAME_
    #define GAME_
    class Game
    {
    private:
        /* data */
    public:
        Game(Player p1, Player p2);
        ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
    
    #endif
    
} // namespace ariel
