#include "Player.hpp"

using namespace std;
namespace coup{
    class Ambassador : public Player
    {        
    public:
        Ambassador();
        Ambassador(Game &gameName, string playerName);
        void transfer(Player &p1, Player &p2);
        void block(Player &p1);
        string role();
        ~Ambassador();
        
    };
    
    
    


}