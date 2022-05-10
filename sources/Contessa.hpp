#include "Player.hpp"

namespace coup{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game &game, string playerName);
        Contessa();
        string role();
        void block(Player &player);
        ~Contessa();
    };
}