#include "time.h"
#include <iostream>

using namespace std;

time::time(int h, int m, int s): hour(h), minute(m), second(s)
{
    pos = (( m/10 ) + h*6);
    cout << pos << endl;
}

int time::Hour()
{
    return hour;
}

int time::Minute()
{
    return minute;
}

int time::Second()
{
    return second;
}

int time::Pos()
{
    return pos;
}
