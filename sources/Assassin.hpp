#include "Player.hpp"

using namespace std;
namespace coup{
    class Assassin : public Player
    {
    public:
        Assassin(Game &game, string playerName);
        Assassin();
        void coup(Player &player) override;
        string role();
        ~Assassin();
    };

}