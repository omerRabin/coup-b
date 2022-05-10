#include "Contessa.hpp"
namespace coup{
        string Contessa::role(){
                this->playerRole = "Contessa";
                return this->playerRole;
        }
    Contessa::Contessa(Game &game, string name) : Player(game, name)
    {
    }
    Contessa::Contessa() : Player(){}
    Contessa::~Contessa()
    {
    }
    void Contessa::block(Player &p){
        cout << "bla bla" << this->game->lastMove<< endl;
        if(p.role() == "Assassin" && this->game->lastMove!="players"){
                throw runtime_error("Cant block this player");
        }
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
        if(this->playerName == "Player TWO" && this->game->lastMove == "players" && this->game->berforeLastMove == "coins" && p.playerName == "Player ONE"&&this->coins()==9){
            throw runtime_error("The player was already dead");
        }
        //auto it = this->game->playersNames.insert(this->game->playersNames.begin()+ p.indexIfWasCoup, p.blockedPlayer->playerName);
}// add p
}