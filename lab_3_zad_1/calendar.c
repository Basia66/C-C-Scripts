//
// Created by Barbara Adamczyk on 05.12.2018.
//

#include "calendar.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Time *makeTime (int day, int month, int year, int hour, int minute, int second)
{
    Time *time = (Time *) malloc (sizeof(Time));
    if (day>31 || day<1)
    {
        return NULL;
    }
    time ->day = day;

    if (month>12 || month<1)
    {
        return NULL;
    }
    time ->month = month;
    if (year>9999 || year<0)
    {
        return NULL;
    }
    time ->year = year;

    if (hour>23 || hour<0)
    {
        return NULL;
    }
    time ->hour = hour;

    if (minute>59 || minute<0)
    {
        return NULL;
    }
    time ->minute = minute;

    if (second>59 || second<0)
    {
        return NULL;
    }
    time ->second = second;
    return time;
}
Event *makeEvent ( Time *eventStart, Time *eventEnd)
{
    Event *makeEvent = (Event *) malloc (sizeof(Event));
    makeEvent ->eventStart = eventStart;
    makeEvent ->eventEnd = eventEnd;
    return makeEvent;
}
Calendar *makeCalendar()
{
    Calendar *calendar =malloc (sizeof(Calendar));
    calendar->events=NULL;
    calendar->count=0;
    return calendar;
}

size_t addCalendar (Calendar *add,Event *e)
{
    //printf("Jestem w add");
    if (add->events==NULL && add->count==0) {
        add->events = (Event **) malloc(sizeof(Event **));
        add->events[0] = (Event *) malloc(sizeof(Event *));
        add->events[0] = e;
        add->count++;
    }
    else
    {
        add->events[add->count]=(Event*)malloc(sizeof(Event*));
        add->events[add->count] =e;
        add->count++;
    }
    return add->count;
}

void printCalendar (Calendar *cal)
{
    for (size_t i = 0; i<cal->count; i++)
    {
        printf("%02d-", cal->events[i]->eventStart->day);
        printf("%02d-", cal->events[i]->eventStart->month);
        printf("%04d ", cal->events[i]->eventStart->year);
        printf("%02d:", cal->events[i]->eventStart->hour);
        printf("%02d:", cal->events[i]->eventStart->minute);
        printf("%02d-", cal->events[i]->eventStart->second);
        printf("%02d-", cal->events[i]->eventEnd->day);
        printf("%02d-", cal->events[i]->eventEnd->month);
        printf("%04d ", cal->events[i]->eventEnd->year);
        printf("%02d:", cal->events[i]->eventEnd->hour);
        printf("%02d:", cal->events[i]->eventEnd->minute);
        printf("%02d\n", cal->events[i]->eventEnd->second);
    }
}
void freeCalendar (Calendar *cal)
{
    for (size_t i = 0; i<cal->count; i++)
    {
        free(cal->events[i]);
    }
    free(cal->events);
    free (cal);
}

double searchDate(Calendar *cal, long int DATE, size_t COUNT)
{
    double SEC=0; // przechowuje sumę zajętych sekund eventów
    long int DATESTART;
    long int DATEEND;
    for (size_t i = 0; i<COUNT; i++)
    {
        DATESTART=cal->events[i]->eventStart->year*10000+cal->events[i]->eventStart->month*100+cal->events[i]->eventStart->day;
        DATEEND=cal->events[i]->eventEnd->year*10000+cal->events[i]->eventEnd->month*100+cal->events[i]->eventEnd->day;
        if (DATESTART<=DATE && DATE<=DATEEND)
        {
            if (DATESTART<DATE && DATE<DATEEND)
            {
                return 24;
            }
            else if (DATESTART==DATE && DATE<DATEEND)
            {
                SEC=SEC + (24*3600 -(cal->events[i]->eventStart->hour*3600+cal->events[i]->eventStart->minute*60+cal->events[i]->eventStart->second));
            }
            else if (DATESTART<DATE && DATE==DATEEND)
            {
                SEC=SEC+ (cal->events[i]->eventEnd->hour*3600+cal->events[i]->eventEnd->minute*60+cal->events[i]->eventEnd->second);
            }
            else
            {
                SEC=SEC+((cal->events[i]->eventEnd->hour*3600+cal->events[i]->eventEnd->minute*60+cal->events[i]->eventEnd->second) -
                         (cal->events[i]->eventStart->hour*3600+cal->events[i]->eventStart->minute*60+cal->events[i]->eventStart->second));
            }
        }
    }
    if (SEC>0)
    {
        SEC = 24 - (SEC/3600);
        return SEC;
    }
    return 24;
}