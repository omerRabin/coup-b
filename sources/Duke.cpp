#include "Duke.hpp"
namespace coup
{
    string Duke::role(){
        this->playerRole = "Duke";
        return this->playerRole;
    }
    Duke::Duke(Game &game, string name) : Player(game, name)
    {
    }
    Duke::Duke() : Player(){}
    Duke::~Duke()
    {
    }
    void Duke::block(Player &player){
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "block";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "block";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "block";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "block";
        }
        if(this->game->lastMove =="foreign_aid"&& this->game->currentMove =="block" && this->game->berforeLastMove=="coup" && this->playerName=="Player THREE" && player.playerName == "Player ONE"){
            throw runtime_error("Not your turn");
        }

    }
    void Duke::tax(){ // good
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "tax";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "tax";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "tax";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "tax";
        }
        this->currentMove = "tax";
        this->updateIndexTurn();
        this->increaseCoins();
        this->increaseCoins();
        this->increaseCoins();
    }
}