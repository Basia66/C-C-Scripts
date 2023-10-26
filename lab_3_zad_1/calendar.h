//
// Created by Barbara Adamczyk on 05.12.2018.
//

#ifndef LAB4_CALENDAR_H
#define LAB4_CALENDAR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Time
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
};
typedef struct Time Time;
Time *makeTime (int day, int month, int year, int hour, int minute, int second);
struct Event
{
    Time *eventStart;
    Time *eventEnd;

};
typedef struct Event Event;

Event *makeEvent ( Time *eventStart, Time *eventEnd);
struct Calendar
{
    Event **events;
    size_t count;
};
typedef struct Calendar Calendar;
Calendar *makeCalendar();
size_t addCalendar (Calendar *add,Event *e);
void printCalendar (Calendar *cal);
void freeCalendar (Calendar *cal);
double searchDate(Calendar *cal, long int DATE, size_t COUNT);
#endif //LAB4_CALENDAR_H
