#include <iostream>
#include <iomanip>
#include "events.hpp"
using namespace std;

events::events(int startT, int startM, int endH, int endM){
    this->eventTitle="";
    this->startHour=startT;
    this->startMinute=startM;
    this->endHour=endH;
    this->endMinute=endM;
    this->date=0;
    this->month=0;
    this->year=0;
    this->isbooked=false;
}
events::~events(){}
void events::book(string title, int sH, int sM, int eH, int eM, int d, int m, int y)
{
    this->eventTitle=title;
    /* this->startHour=sH;
    this->startMinute=sM;
    this->endHour=eH;
    this->endMinute=eM; */
    this->date=d;
    this->month=m;
    this->year=y;
    this->isbooked=true;
}

//Cancel the booking
void events::cancelBook(){
    this->eventTitle="";
    isbooked=false;
}
//Display the Day
void events::displayDay(){
    if(startHour<10 && endMinute==0){
        cout<<setw(2)<<setfill('0')<<startHour<<startMinute<<" - "<<setw(2)<<setfill('0')<<endHour<<setw(2)<<setfill('0')<<endMinute<<"H"<<" "<<eventTitle<<endl;
    }else if(startHour<10 && endMinute==30){
        cout<<setw(2)<<setfill('0')<<startHour<<setw(2)<<setfill('0')<<startMinute<<" - "<<setw(2)<<setfill('0')<<endHour<<endMinute<<"H"<<" "<<eventTitle<<endl;
    }else if(startHour>=10 && endMinute==0){
        cout<<startHour<<setw(2)<<setfill('0')<<startMinute<<" - "<<setw(2)<<setfill('0')<<endHour<<setw(2)<<setfill('0')<<endMinute<<"H"<<" "<<eventTitle<<endl;
        
    }else if(startHour>=10 && startMinute==0){
        cout<<startHour<<setw(2)<<setfill('0')<<startMinute<<" - "<<endHour<<endMinute<<"H"<<" "<<eventTitle<<endl;
    }
    //cout<<endl;
}
//Display the Week
void events::displayWeek(){
    cout<<"   -> ";
    displayDay();
}
//Display the month
void events::displayMonth(){
    displayWeek();
}



