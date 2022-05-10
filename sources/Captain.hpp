#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:

    public:
        Captain(Game &game, string playerName);
        Captain();
        void block(Player &player);
        void steal(Player &player);
        string role();
        ~Captain();
    };


}