#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "time.h"

using namespace std;

class Player
{
    public:
        Player(string);
        void addLog(string);
        string getName();
        void draw(ofstream *);
        void setBin();
    private:
        string name;
        bool bin;
        vector<Time*> logs;
};

#endif // PLAYER_H
