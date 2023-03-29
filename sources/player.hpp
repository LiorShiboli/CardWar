#include <string>
namespace ariel
{
    #ifndef PLAYER_
    #define PLAYER_
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
