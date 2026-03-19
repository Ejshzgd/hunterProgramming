/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-17
Updated:     2026-3-17
Description: Define a function: int minutesSinceMidnight(Time time);
                -Return the number of minutes from 0:00AM until time
             Define a function: int minutesUntil(Time earlier, Time later);
                -Receive two Time arguments earlier and later 
                -Report how many minutes separate the two moments
             Define a function: Time addMinutes(Time time0, int min);
                -Create and return a new moment of time that is min minutes after time0
             Define a function: TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
                -Return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot ts
             Define a function: bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
                -Return true if the two time slots overlap, otherwise return false
*/

//--Libraries
#include <iostream>
#include <string>

//--Namespaces
using namespace std;

//Enums
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

//---Classes ---
class Time{ 
public:
    int h;
    int m;
};

class Movie{ 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot{ 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


//--- Function prototype ---
void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);

void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 


int main(){

    //--Task A
    Time a,b;
    int hours,minutes;

    cout << "Enter first time: ";
    cin >> hours;
    cin >> minutes;
    a = {hours, minutes};


    cout << "Enter second time: ";
    cin >> hours;
    cin >> minutes;
    b = {hours, minutes};

    cout << "These moments of time are " << minutesSinceMidnight(a) << " and " 
                        << minutesSinceMidnight(b) << " minutes after midnight."
                        <<"\nThe interval between them is " << minutesUntil(a,b) << " minutes.";

    
    //--Task C
    TimeSlot ts = {{"Back to the Future", COMEDY, 116}, {9, 15}}; 
    cout << '\n';
    printTimeSlot(ts);

    return 0;
}


void printTime(Time time){
    cout << time.h << ":" << time.m;
}


int minutesSinceMidnight(Time time){
    return (time.h*60 + time.m);
}


int minutesUntil(Time earlier, Time later){
    int diffMinutes = 60 - earlier.m;
    int diffHours = later.h - (earlier.h + 1);

    return (diffHours*60) + (diffMinutes + later.m);
}


Time addMinutes(Time time0, int min){
    Time* time1 = new Time;
    *time1 = {0,0};

    int total = time0.h*60 + time0.m + min;

    time1->h = total/60;
    time1->m = total%60;
    
    return *time1;
}


void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}


void printTimeSlot(TimeSlot ts){
    Time* endTime = new Time;
    *endTime = addMinutes(ts.startTime, ts.movie.duration);
    

    printMovie(ts.movie);
    cout << ' ' << "[starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    printTime(*endTime);
    cout << "]";
}


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot* updatedTimeSlot = new TimeSlot;

    Time* updatedStartTime = new Time;
    *updatedStartTime = addMinutes(ts.startTime, ts.movie.duration);

    updatedTimeSlot->movie = nextMovie;
    updatedTimeSlot->startTime = *updatedStartTime;

    return *updatedTimeSlot;
}


bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    return (minutesUntil(ts1.startTime, ts2.startTime) < ts1.movie.duration) &&
           (minutesUntil(ts2.startTime, ts1.startTime) < ts2.movie.duration);
}
