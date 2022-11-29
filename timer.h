#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <ctime>

class timer
{
    time_t now;
    public:
    struct tm newLocal;
        timer();
        void updateLocalTime();
        int getMinuteAngle();
        int getHourAngle();
        int getSecondAngle();
        virtual ~timer();

    protected:

    private:
};


#endif // TIMER_H_INCLUDED
