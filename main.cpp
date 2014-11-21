#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "player.h"
#include <map>
#include <set>
#include <ctime>

using namespace std;

void draw(int len, ofstream * nlog, map<string, Player*>* p, set<string>* n){
    len++;
    string def = " ";
    string pr = " |00:00|01:00|02:00|03:00|04:00|05:00|06:00|07:00|08:00|09:00|10:00|11:00|12:00|13:00|14:00|15:00|16:00|17:00|18:00|19:00|20:00|21:00|22:00|23:00|";
    for(int i = 0; i <len; i++)
        def += " ";
    *nlog << endl << def << pr << endl;

    set<string>::iterator ni = n->begin();
    for(unsigned int i = 0; i < n->size(); i++, ni++) {
        for(unsigned int i = 0; i<len-ni->size(); i++) {
            *nlog << " ";
    }
        *nlog << *ni << " |";
        p->at(*ni)->draw(nlog);
    }


}

int main(int argc, char* argv[])
{
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int i = 1;
    string tme = to_string(now->tm_year+1900) + "-" + to_string(now->tm_mon) + "-" + to_string(now->tm_mday-1) + "-" + to_string(i) + ".log";
	if(argc==2)
		tme = argv[1];

	else if(argc==1) {
        //combine logs
		tme = tme;
	}
	else {
		tme = "nope.txt";
		cout << "invalid input, too many arguments" << endl;
        return 0;
	}
	ifstream log(tme);
    cout << tme << endl;
	if(log.peek() == EOF) {
        cout << "specified log does not exist, or is empty" << endl;
        return 0;
	}
    ofstream nlog(tme[0, tme.length()-4] + "-logs" + ".log");

    map<string, Player*> players;
    set<string> names;
    unsigned int len = 0;
    string c, d, time, type, type2, type3, player, thing, UUID;
    stringstream ss(c);

    while(getline(log, c)) {
        c += " å";
        ss.str(c);
        ss >> time >> type >> type2;
        if(type == "[Server" && player[0] != '?') {
            ss >> player >> thing;
            ss << " å";
                if(thing == "joined" || thing == "left") {
                    nlog << time << " " << player << " " << thing;
                    if(thing == "joined")
                        nlog << " UUID: " << UUID;
                    nlog << endl;

                    player[0] = toupper(player[0]);
                    if(names.find(player) == names.end())
                        names.insert(player);

                    if(players.find(player) == players.end()){
                        players[player] = new Player(player);
                        if(thing == "left")
                            players[player]->setBin();
                    }
                    players[player]->addLog(time);

                    if(player.length() > len)
                        len = player.length();
                }
        }
        if(type == "[User")
            ss >> type3 >> thing >> thing >> thing >> player >> thing >> UUID;
    }
    draw(len, &nlog, &players, &names);
    return 0;
}
