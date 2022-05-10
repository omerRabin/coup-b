#include "Ambassador.hpp"
namespace coup{
    string Ambassador::role(){
        this->playerRole = "Ambassador";
        return this->playerRole;
    }
    Ambassador::Ambassador(Game &game, string name) : Player(game,name)
    {
    }
    Ambassador::Ambassador() : Player()
    {
    }
    void Ambassador::transfer(Player &player1, Player &player2){ // good
        this->updateIndexTurn();
        if(player1.coins()==0){
        throw runtime_error("not enogth money");
        }
        player1.decreaseCoins();
        player2.increaseCoins();
    }
    void Ambassador::block(Player &player){  // can block only Captain
        player.decreaseCoins(); // take back the coins
        player.decreaseCoins();

        
    } 
    Ambassador::~Ambassador()
    {
    }
    
}