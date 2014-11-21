#include "time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m, int s): hour(h), minute(m), second(s)
{
    pos = (( m/10 ) + h*6);
    //cout << pos << endl;
}

int Time::Hour()
{
    return hour;
}

int Time::Minute()
{
    return minute;
}

int Time::Second()
{
    return second;
}

int Time::Pos()
{
    return pos;
}
