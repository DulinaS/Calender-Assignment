#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "days.hpp"
//#include "events.hpp"
using namespace std;

//initializing Array
days::days(string name , int d){
    this->dayName=name;
    this->dayDate=d;
    slotSize=48;
    eventArray=new events*[slotSize];
    int endHour=0;
    for(int i=0 ; i<slotSize ; i++){
        int startHour = i/2;
        int startMinute= (i % 2)*30;
        int  endMinute=0;
        if(startMinute >0){
            endHour++;
        }else{
            endMinute=30;
        }
        eventArray[i]= new events(startHour,startMinute, endHour, endMinute);
    }
}

days::~days(){
    for(int i=0 ; i<slotSize ; i++){
        delete eventArray[i];
        eventArray=NULL;
    }
}
//Get Day name
string days::getDayName(){
    return dayName;
}
//get day 
int days::getDate(){
    return dayDate;
}
string days::getEventName(int date){

    return eventArray[date-1]->eventTitle;
}

// Book Event
void days::bookEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year){
    int start= startHour*2 + startMinute/30;
    int end= endHour*2 + endMinute/30;
    int slots=end-start;
    for(int i=start ; i<start+slots ; i++){
         eventArray[i]->book(eventName, startHour, startMinute, endHour, endMinute, date, month, year);
    }
}

//Check whether the timeslots are booked or not for deleting
bool days::checkEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute){
    int start= startHour*2 + startMinute/30;
    int end= endHour*2 + endMinute/30;
    int slots=end-start;
    int ctrue=0, cfalse=0;
    vector<bool> boolVect;
    
    for(int i=start ; i<start+slots ; i++){
        boolVect.push_back(eventArray[i]->isbooked && (eventArray[i]->eventTitle == eventName));
    }

    for(bool b : boolVect){
        if(b==true)
            ctrue++;
        if(b==false)
            cfalse++;
    }
    if((ctrue > 0 && cfalse == 0) || (ctrue > 0 && cfalse > 0)){
        return true;
    }else if(cfalse>0 && ctrue==0){
        return false;
    }

}

//Check whether the timeslots are already booked or not for booking
bool days::checkEventforBooking(int startHour, int startMinute, int endHour, int endMinute){
   
    int start= startHour*2 + startMinute/30;
    int end= endHour*2 + endMinute/30;
    int slots=end-start;
    int ctrue=0, cfalse=0;
    vector<bool> boolVect;

    for(int i=start ; i<start+slots ; i++){
        boolVect.push_back(eventArray[i]->isbooked);
    }
 
    for(bool b : boolVect){
        if(b==true){
            ctrue++;
        }     
        if(b==false){
            cfalse++;
        }     
    }

    if((ctrue > 0 && cfalse == 0) || (ctrue > 0 && cfalse > 0)){
        return true;
    }else if(cfalse>0 && ctrue==0){
        return false;
    }

}

//Delete Event
void days::deleteEvent(string eventName, int startHour, int startMinute, int endHour, int endMinute, int date, int month, int year){
    int hour=endHour - startHour;
    int minutes=(endMinute-startMinute)/60;
    int numberOfSlots=(hour+minutes)*2;

    if(startMinute % 2 == 0){
        int startIndex= 2*startHour;
        for(int i=startIndex ; i<startIndex + numberOfSlots ; i++){
            eventArray[i]->cancelBook();
        }
    }else if(startMinute > 0){
        int startIndex= 2*startHour +1;
        for(int i=startIndex ; i<startIndex + numberOfSlots ; i++){
            eventArray[i]->cancelBook();
        }
    }
}

void days::viewAllEvents(int date){
    cout<<"Schedule For a Day:"<<endl;
    cout<<date<<" July 2024"<<endl;
    for(int i=0 ; i<slotSize ; i++){
        eventArray[i]->displayDay();
    }
}

void days::viewWeek(){
    cout<<dayDate<<" July "<<"("<<dayName<<")"<<endl;
    for(int i=0 ; i<slotSize ; i++){
        if(eventArray[i]->isbooked){
            eventArray[i]->displayWeek();
        }  
    }
}

bool days::viewMonth(){
    vector<int> position;
    for(int i=0 ; i<slotSize ; i++){
        if(eventArray[i]->isbooked){
            position.push_back(i);
        }  
    }
    if(position.size()==1){
        cout<<dayDate<<" July "<<"("<<dayName<<")"<<endl;
        eventArray[position[0]]->displayWeek();
    }else if(position.size()>1){
        cout<<dayDate<<" July "<<"("<<dayName<<")"<<endl;
        for(int i : position){
            eventArray[i]->displayWeek();
        }
    }else if(position.empty()){
        return false;
    }
    return true;
}
