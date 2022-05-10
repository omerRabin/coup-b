#include "Player.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
        /* data */
    public:
        Duke(Game &game, string playerName);
        Duke();
        void block(Player &player);
        void tax();
        string role();
        ~Duke();
    };
}