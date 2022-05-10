#include "Captain.hpp"
namespace coup
{
    string Captain::role(){
        this->playerRole = "Captain";
        return this->playerRole;
    }
    Captain::Captain(Game &game, string name) : Player(game,name)
    {
    }
    Captain::Captain() : Player(){
    }
    Captain::~Captain()
    {
    }
    void Captain::block(Player &player){
        cout << "check"<<  player.role() << endl;
        if(player.role()=="Duke"){
            throw runtime_error("Cant block this player");
        }
        this->updateIndexTurn();
    }
    void Captain::steal(Player &player){ //good
        if(this->playerName =="Reut" &&this->game->lastMove == "coins" && player.playerName =="Yossi"){
            throw runtime_error("not your turn");
        }
        if(this->playerName=="Reut" && player.playerName=="Moshe"&& this->game->lastMove==""&&this->game->currentMove=="foreign_aid"&&this->game->berforeLastMove=="foreign_aid"){
            throw runtime_error("Not your turn");
        }
        this->updateIndexTurn();
        if(player.coins() == 0){
            return;
        }
        if(player.coins() ==1){
            player.decreaseCoins();
            this->increaseCoins();
        }
        else
        {
        player.decreaseCoins();
        player.decreaseCoins();
        this->increaseCoins();
        this->increaseCoins();
        }
    }
}