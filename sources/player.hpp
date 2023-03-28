#include <string>
namespace ariel
{
    #ifndef _GAME_
    #define _GAME_
    class Player
    {
    private:

    public:
        Player(std::string name);
        ~Player();
        int stacksize();
        int cardesTaken();
    };
    #endif
    
} // namespace ariel
