#ifndef TIME_H
#define TIME_H


class Time
{
    public:
        Time(int, int, int);
        int Second();
        int Minute();
        int Hour();
        int Pos();
    private:
        int hour;
        int minute;
        int second;
        int pos;
};

#endif // TIME_H
