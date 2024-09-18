#ifndef EVENTS_H
#define EVENTS_H
#include <string>
using namespace std;

class events{
private:
    //string eventTitle;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    //bool isbooked;
    int date;
    int month;
    int year;

public:
    string eventTitle;
    bool isbooked;
    events(int startT, int startM, int endH, int endM);
    ~events();
    void book(string title, int sH, int sM, int eH, int eM, int d, int m, int y);
    void cancelBook();
    void displayDay();
    void displayWeek();
    void displayMonth();
    
};
#endif