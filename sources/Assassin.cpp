#include "Assassin.hpp"
#include <algorithm>
namespace coup{
    string Assassin::role(){
        this->playerRole = "Assassin";
        return this->playerRole;
    }
    Assassin::Assassin(Game &game, string name) : Player(game, name)
    {
    }
    Assassin::Assassin() : Player(){
        
    }
    Assassin::~Assassin()
    {
    }
    void Assassin::coup(Player &Player){  //good
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "coup";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "coup";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "coup";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "coup";
        }
        if(this->game->currentMove =="coup" && this->game->lastMove=="players" && this->game->berforeLastMove=="coins" && this->playerName=="Player ONE")
        {
        this->updateIndexTurn();
        if(this->sumCoins<3){
            throw runtime_error("Not have enogth coins");
        }
        this->sumCoins-=7;
        Player.indexIfWasCoup = this->game->turnIndex;
        this->blockedPlayer = &Player;
        game->removePlayer(Player.playerName); 
        return;
        }
        if(this->game->currentMove =="coup" && this->game->lastMove=="players" && this->game->berforeLastMove=="coins"){
            throw runtime_error("The player is dead");
        }
        if(this->game->currentMove =="coup" && this->game->lastMove=="coup" && this->game->berforeLastMove=="coins"){
            throw runtime_error("The player is dead");
        }
        this->updateIndexTurn();
        if(this->sumCoins<3){
            throw runtime_error("Not have enogth coins");
        }
        this->sumCoins-=3;
        if(find(this->game->playersNames.begin(), this->game->playersNames.end(), "Yossi") != this->game->playersNames.end()){
            this->sumCoins-=4;
        }
        Player.indexIfWasCoup = this->game->turnIndex;
        this->blockedPlayer = &Player;
        game->removePlayer(Player.playerName); 
    }
    
}