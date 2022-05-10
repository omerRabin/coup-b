#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace coup
{
    class Game
    {
        class Player;
    public: 
        bool isStarted;
        vector<string> playersNames;
        unsigned int turnIndex; // in range: 0 - num of players
        unsigned int numOfLosers;
        string lastMove;
        string berforeLastMove;
        string currentMove;
        int counter;
        int secondCounter;
        vector<string> tempListPlayers;
        Game();
        vector<string> players();
        string turn();
        string winner();
        void addPlayer(string name);
        void removePlayer(string name);
        int getIndexByName(string name);
        ~Game();
    };
    
} // namespace coup
