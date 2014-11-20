#include "player.h"
#include <sstream>
Player::Player(string n): name(n), bin(false)
{
    logs.push_back(new time(0, 0, 0));
}

void Player::addLog(string t)
{
    int h, m, s;
    stringstream ss;

    t.erase(0,1);
    t.replace(2,1, " ");
    t.replace(5,1, " ");
    t.erase(8);
    ss.str(t);
    ss >> h >> m >> s;
    //cout << "added log for " << name << " at " << h << " " << m << " " << s << endl;
    logs.push_back(new time(h ,m, s));
}

string Player::getName()
{
    return name;
}

void Player::setBin()
{
    bin = true;
}

void Player::draw(ofstream * nlog)
{
    unsigned int i = 0;
    int w = 0;
    int k = 0;
    int f = 0;

    for(i = 0; i<logs.size()-1; i++, bin = !bin){
        if((bin)&&(f==logs[i]->Pos()||f<logs[i+1]->Pos())){
            *nlog << (i/2)+1;
            f++;
            if(((i/2)+1)>=10)
                f++;
        }
        for(f=f; f<logs[i+1]->Pos(); f++) {
            if(bin)
                *nlog << "-";
            else
                *nlog << " ";
        }
    }
    for(f; f<144; f++)
        if(bin)
            *nlog << "-";
        else
            *nlog << " ";
    *nlog << "|" << endl;
}
