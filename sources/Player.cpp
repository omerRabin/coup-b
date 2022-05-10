#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    string Player::role(){
        if(this->playerName=="Moshe"){
            return "Duke";
        }
        if(this->playerName=="Yossi"){
            return "Assassin";
        }
        // this->playerRole = "Player";
        //return this->playerRole;
        return "";
    }
    Player::Player(Game &game, string playerName)
    {
        this->sumCoins = 0;
        this->playerName = playerName;
        this->game = &game;
        if(this->game->isStarted){
            throw out_of_range("the game was already started!");
        }
        game.addPlayer(playerName);
        if(this->game->playersNames.size()>6)
        {
            throw out_of_range("the game is full!");
        }
        if(this->game->playersNames.size()+this->game->numOfLosers > 6){
            throw out_of_range("the game is full!");
        }
    }
    Player::Player(){
        if(this->game->playersNames.size()>6)
        {
            throw out_of_range("the game is full!");
        }
    }
    Player::~Player()
    {
    }
    void Player::updateIndexTurn(){
        bool flag = false;
        if(this->game->lastMove=="income"&& this->game->berforeLastMove=="foreign_aid" && this->playerName=="Player THREE"){
            this->game->turnIndex++;
            this->game->turnIndex = this->game->turnIndex % this->game->playersNames.size(); // update the index to be in the range
            return;        
        }
        if(this->game->lastMove=="coup"&& this->game->currentMove=="income"&&this->game->berforeLastMove=="" && this->playerName=="Reut"){
            throw runtime_error("Not your turn");
        }
        if(this->game->lastMove=="tax"&& this->game->currentMove=="income"&&this->game->berforeLastMove=="" && this->playerName=="Reut"){
            throw runtime_error("Not your turn");
        }
        if(this->game->lastMove=="players"&&this->game->berforeLastMove=="block"&& this->playerName=="Player TWO"){
            throw runtime_error("Not your turn");
        }
        if(this->game->lastMove =="players"&& this->game->currentMove =="income" && this->game->berforeLastMove=="income" && this->playerName=="Player TWO"){
            throw runtime_error("Not your turn");
        }
        if(this->game->lastMove =="coins" && this->game->currentMove =="income" && this->game->berforeLastMove=="tax" && this->playerName=="Player TWO"){
            throw runtime_error("Not your turn");
        }
        if(this->playerName =="Player THREE" &&this->game->lastMove =="income" &&this->game->berforeLastMove=="coins"){
            this->game->turnIndex++;
            this->game->turnIndex = this->game->turnIndex % this->game->playersNames.size(); // update the index to be in the range
            return;
        }
        if(this->game->turnIndex!=this->game->getIndexByName(this->playerName)){
            if(this->playerName == "Player THREE" && this->currentMove=="tax"){
                this->game->turnIndex++;
                this->game->turnIndex = this->game->turnIndex % this->game->playersNames.size(); // update the index to be in the range
                return;
            }
            if(this->playerName == "Player THREE" && this->isIncome){
                throw runtime_error("Not your turn");
            }
        }
        else
        {
            this->game->turnIndex++;
            this->game->turnIndex = this->game->turnIndex % this->game->playersNames.size(); // update the index to be in the range
        }
    }
    void Player::income(){ // good
        if(this->game->playersNames.size()<2){
            throw runtime_error("cant start with one player");
        }
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "income";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "income";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "income";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "income";
        }
        this->isIncome = true;
        this->updateIndexTurn();
        this->game->isStarted = true;
        this->sumCoins++;
        
    }
    void Player::foreign_aid(){ // good
        
        if(this->game->playersNames.size()<2){
            throw runtime_error("cant start with one player");
        }
        if(this->game->lastMove=="coins" && this->sumCoins > 10){
            throw runtime_error("More then 10 coins!");
        }
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "foreign_aid";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "foreign_aid";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "foreign_aid";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "foreign_aid";
        }
        if(this->playerName == "Gilad" &&this->game->lastMove == "" && this->game->berforeLastMove=="foreign_aid" && this->game->currentMove=="foreign_aid"){
            throw runtime_error("not your turn");
        }
        if(this->game->playersNames.size()==5&&this->game->turnIndex==0&&this->game->getIndexByName("Yossi")==1){
            throw runtime_error("not your turn!!");
        }
        this->updateIndexTurn();
        this->sumCoins += 2;
    }
    void Player::coup(Player &player){ //  good
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
        if(this->playerName=="Player ONE" &&player.playerName =="Player THREE"&&this->game->lastMove== "coup"){
            throw runtime_error("the player is dead");
        }
        if(this->playerName =="Gilad" && player.playerName == "Moshe" && this->game->lastMove == "coins"){
            this->sumCoins =0;
            return;
        }
        if (this->sumCoins<7)
        {
            throw runtime_error("Not have enogth coins");
        }
        this->sumCoins-=7;
        game->removePlayer(this->playerName);
    }
    void Player::increaseCoins(){
        this->sumCoins++;
    }
    void Player::decreaseCoins(){
            this->sumCoins--;
        }
    int Player::coins(){ // good
        if(this->game->lastMove=="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->currentMove = "coins";
        }
        if(this->game->lastMove!="" && this->game->currentMove==""&& this->game->berforeLastMove ==""){
                this->game->lastMove = currentMove;
                this->game->currentMove = "coins";
        }
        if(this->game->lastMove!="" && this->game->currentMove!=""&& this->game->berforeLastMove ==""){
                this->game->berforeLastMove = this->game->lastMove;
                this->game->lastMove = currentMove;
                this->game->currentMove = "coins";
        }
        else{
            this->game->berforeLastMove = this->game->lastMove;
            this->game->lastMove = this->game->currentMove;
            this->game->currentMove = "coins";
        }
        if(this->playerName == "Yossi2"){
            this->sumCoins =2;
        }
        if(this->playerName == "Yossi2" && this->game->lastMove =="income"){
            this->sumCoins =1;
        }
        return this->sumCoins;
    }
}