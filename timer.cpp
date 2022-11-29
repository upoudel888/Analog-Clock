#include "timer.h"

timer::timer()
{
    now = time(NULL);
    newLocal = *localtime(&now);
}

void timer::updateLocalTime(){
    now = time(NULL);
    newLocal = *localtime(&now);
}

int timer::getHourAngle(){
    int hour = newLocal.tm_hour % 12;
    int val = hour * 30 + (newLocal.tm_min * 0.5); // 360/12 = 30 hour ticks
    return val;
}

int timer::getMinuteAngle(){
    int minute = newLocal.tm_min;
    return minute * 6;  //every minute corresponds to 6 degrees i.e. 360 deg / 60 ticks
}

int timer::getSecondAngle(){
    int second = newLocal.tm_sec;
    return second * 6;  //every second corresponds to 6 degrees

}

timer::~timer()
{
    //dtor
}
