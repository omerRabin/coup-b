#pragma once
#include "Game.hpp"
#include <string>
using namespace std;
namespace coup{
    class Player
    {
    public:
        // string role(){
        //     this->playerRole = "Player";
        // }
        Player * blockedPlayer;
        bool isIncome = false;
        unsigned int indexIfWasCoup;
        string currentMove;
        string playerName;
        int sumCoins;
        Game *game;
        string playerRole;
        Player(Game& game, string playerName);
        Player();
        void income();
        string role();
        void foreign_aid();
        virtual void coup(Player &p);
        void decreaseCoins();
        void increaseCoins();
        void updateIndexTurn();
        int coins();
        ~Player();
    };
    
}