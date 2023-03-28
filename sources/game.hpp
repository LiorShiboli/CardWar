#include "player.hpp"
namespace ariel
{
    
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
    
    
    
} // namespace ariel
