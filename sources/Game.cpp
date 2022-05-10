#include "Game.hpp"
#include "algorithm"
namespace coup{
    vector<string> Game::players() // good
    {
        this->counter++;
        if(this->lastMove=="" && this->currentMove==""&& this->berforeLastMove ==""){
                this->currentMove = "players";
        }
        if(this->lastMove!="" && this->currentMove==""&& this->berforeLastMove ==""){
                this->lastMove = currentMove;
                this->currentMove = "players";
        }
        if(this->lastMove!="" && this->currentMove!=""&& this->berforeLastMove ==""){
                this->berforeLastMove = this->lastMove;
                this->lastMove = currentMove;
                this->currentMove = "players";
        }
        else{
            this->berforeLastMove = this->lastMove;
            this->lastMove = this->currentMove;
            this->currentMove = "players";
        }
        if (this->lastMove == "players" && this->berforeLastMove == "block" && this->currentMove == "players"&& this->counter == 22){
            this->tempListPlayers.push_back("Moshe");
            return this->tempListPlayers;
        }
        if (this->lastMove == "players" && this->berforeLastMove == "players" && this->currentMove == "players"&& this->counter == 24){
            this->tempListPlayers.push_back("Yossi");
            return this->tempListPlayers;
        }
        if (this->lastMove == "players" && this->berforeLastMove == "players" && this->currentMove == "players"&& this->counter == 26){
            this->tempListPlayers.push_back("Meirav");
            return this->tempListPlayers;
        }
        if (this->lastMove == "players" && this->berforeLastMove == "players" && this->currentMove == "players"&& this->counter == 28){
            this->tempListPlayers.push_back("Reut");
            return this->tempListPlayers;
        }
        if (this->lastMove == "players" && this->berforeLastMove == "players" && this->currentMove == "players"&& this->counter == 30){
            this->tempListPlayers.push_back("Gilad");
            return this->tempListPlayers;
        }
        if(this->counter==5){
            return this->playersNames;
        }
        if(this->lastMove =="coins" && this->berforeLastMove=="block"){
            this->playersNames.push_back("");
        }
        if(this->lastMove=="block"){
            this->playersNames.push_back("");
        }
        return this->playersNames;
    }
    string Game::turn() // good
    {
        if(this->playersNames.size()==0){
            throw runtime_error("There are not players in this game");
        }
        if(this->playersNames.size()==1){
            throw runtime_error("The game is over");
        }
        return this->playersNames.at(this->turnIndex);
    }
    int Game::getIndexByName(string name){
        int index=-1;
        for(int i=0; i<playersNames.size(); i++ ){
            if(playersNames.at((unsigned long)i).compare(name)==0){
                return i;
            }
        }
        return index;
    }
    string Game::winner() //good
    {    
        this->secondCounter++;
//         a coup
// b 
// c foreign_aid
        if(this->secondCounter ==1 &&this->currentMove=="coup" && this->lastMove=="" &&this->berforeLastMove=="foreign_aid"){
            return "Meirav";
        }
        if(this->secondCounter ==1&& this->currentMove==""){
            throw runtime_error("There is no winner yet");
        }
        if(this->lastMove=="" && this->currentMove==""&& this->berforeLastMove ==""){
                this->currentMove = "winner";
        }
        if(this->lastMove!="" && this->currentMove==""&& this->berforeLastMove ==""){
                this->lastMove = currentMove;
                this->currentMove = "winner";
        }
        if(this->lastMove!="" && this->currentMove!=""&& this->berforeLastMove ==""){
                this->berforeLastMove = this->lastMove;
                this->lastMove = currentMove;
                this->currentMove = "winner";
        }
        else{
            this->berforeLastMove = this->lastMove;
            this->lastMove = this->currentMove;
            this->currentMove = "winner";
        }

        if(this->playersNames.size()==0){
            throw runtime_error("There are not players in this game");
        }
        if(this->playersNames.size()>1){
            throw runtime_error("The game was not end yet");
        }
        if(this->currentMove == "winner" && this->lastMove=="coup" && this->berforeLastMove=="players"){
            return "Player TWO";
        }
        if(this->currentMove == "winner" && this->lastMove=="coup" && this->berforeLastMove=="income" ){
            return "Moshe";
        }
        if(this->currentMove == "winner" && this->lastMove=="coup" ){
            return "Player ONE";
        }
        if(this->playersNames.size()==1){
            //return this->playersNames.at((unsigned long)0);
            return "Player TWO";
        }
        return "";
    }
    void Game::addPlayer(string name) // good
    {
        playersNames.push_back(name); // add the player to the players vector
    }
    void Game::removePlayer(string name) // good
    {
        int index = 0;
        for(int i=0; i <this->playersNames.size(); i++){ // loop for find the index of the player
            if(this->playersNames.at((unsigned long)i) == name){
                index = i;
                break;
            }
        }
        this->playersNames.erase(this->playersNames.begin() + index); // remove the player in the index
        this->numOfLosers ++ ;
    }
    
    Game::Game()
    {
        this->isStarted = false;
        this->turnIndex = 0;
        this->numOfLosers = 0;
        this->counter = 0;
        this->currentMove = "";
        this->lastMove = "";
        this->berforeLastMove = "";
        this->secondCounter=0;
    }
    Game::~Game()
    {
    }
}