#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calendar.h"

int main() {
    Calendar *allCalendar;
    allCalendar=makeCalendar();
    char linia[42];
    char p;
    fgets(linia, sizeof linia, stdin);
    puts(linia);
    long long int date1,date2,start,end;


    while (strchr(linia, 113) == NULL && strchr(linia, 81) == NULL)
    {
        p = linia[0];
            switch (p)
            {
                case 'F':
                case 'f':
                    {

                        if (allCalendar->count>0)
                        {
                            if (linia[1] == 32 && linia[4] == 45 && linia[7] == 45)
                            {
                                int day1 = 0, month1 = 0, year1 = 0;
                                day1 = atoi(&linia[2]);
                                month1 = atoi(&linia[5]);
                                year1 = atoi(&linia[8]);

                                if (!((day1 > 31 || day1 < 1) && (month1 > 12 || month1 < 1) &&
                                      (year1 > 9999 || year1 < 0)))
                                    {
                                        double HOURS = searchDate(allCalendar, year1 * 10000 + month1 * 100 + day1, allCalendar->count);
                                        printf("\n%.2lf h", HOURS);
                                    }
                            }
                        }
                        else
                        {
                            printf("24.00h");
                        }
                        break;
                    }
                case 'S':
                case 's':
                    {
                        //printf("%zu",allCalendar->count);
                        printCalendar(allCalendar);
                        printf("\n");
                        break;
                    }
                case 'A':
                case 'a': {
                    //printf("%zu",allCalendar->count);
                    int day1 = 0, month1 = 0, year1 = 0, hour1 = 0, minute1 = 0, second1 = 0;
                    int day2 = 0, month2 = 0, year2 = 0, hour2 = 0, minute2 = 0, second2 = 0;
                    Time *t1, *t2;
                    if (linia[1] == 32 && linia[4] == 45 && linia[7] == 45 && linia[12] == 32 && linia[15] == 58 &&
                        linia[18] == 58 &&
                        linia[21] == 45
                        && linia[24] == 45 && linia[27] == 45 && linia[32] == 32 && linia[35] == 58 &&
                        linia[38] == 58) {
                        day1 = atoi(&linia[2]);
                        month1 = atoi(&linia[5]);
                        year1 = atoi(&linia[8]);
                        hour1 = atoi(&linia[13]);
                        minute1 = atoi(&linia[16]);
                        second1 = atoi(&linia[19]);

                        day2 = atoi(&linia[22]);
                        month2 = atoi(&linia[25]);
                        year2 = atoi(&linia[28]);
                        hour2 = atoi(&linia[33]);
                        minute2 = atoi(&linia[36]);
                        second2 = atoi(&linia[39]);

                        t1 = makeTime(day1, month1, year1, hour1, minute1, second1);

                        t2 = makeTime(day2, month2, year2, hour2, minute2, second2);

                        //sprawdzenie czy pierwsza data jest wcześniejsza od drugiej//
                        int ok = 1;
                        if (year1 > year2) ok = 0;
                        else if (year1 == year2 && month1 > month2) ok = 0;
                        else if (year1 == year2 && month1 == month2 && day1 > day2) ok = 0;
                        else if (year1 == year2 && month1 == month2 && day1 == day2 && hour1 > hour2) ok = 0;
                        else if (year1 == year2 && month1 == month2 && day1 == day2 && hour1 == hour2 &&
                                 minute1 > minute2)
                            ok = 0;
                        else if (year1 == year2 && month1 == month2 && day1 == day2 && hour1 == hour2 &&
                                 minute1 == minute2 && second1 >= second2)
                            ok = 0;

                        //sprawdzenie czy daty nie pokrywają się z tymi w kalendarzu//

                        date1 = year1 * 10000000000 + month1 * 100000000 + day1 * 1000000 + hour1 * 10000 +
                                minute1 * 100 + second1;
                        date2 = year2 * 10000000000 + month2 * 100000000 + day2 * 1000000 + hour2 * 10000 +
                                minute2 * 100 + second2;
                        start = 0;
                        end = 0;
                        //printf("%zu",allCalendar->count);
                        for (size_t i = 0; i < allCalendar->count; i++) {
                            start = start + allCalendar->events[i]->eventStart->year * 10000000000 +
                                    allCalendar->events[i]->eventStart->month * 100000000 +
                                    allCalendar->events[i]->eventStart->day * 1000000 +
                                    allCalendar->events[i]->eventStart->hour * 10000 +
                                    allCalendar->events[i]->eventStart->minute * 100 +
                                    allCalendar->events[i]->eventStart->second;

                            end = end + allCalendar->events[i]->eventEnd->year * 10000000000 +
                                  allCalendar->events[i]->eventEnd->month * 100000000 +
                                  allCalendar->events[i]->eventEnd->day * 1000000 +
                                  allCalendar->events[i]->eventEnd->hour * 10000 +
                                  allCalendar->events[i]->eventEnd->minute * 100 +
                                  allCalendar->events[i]->eventEnd->second;


                            if ((date1 > start && date1 > end) || (date2 < start && date2 < end)) {
                                ok = 1;
                            } else {
                                ok = 0;
                                i = allCalendar->count;
                            }

                            start = 0;
                            end = 0;
                        }

                        if (t1 != NULL && t2 != NULL && ok == 1) {
                            printf("%02d-%02d-%04d %02d:%02d:%02d", day1, month1, year1, hour1, minute1, second1);
                            printf("-");
                            printf("%02d-%02d-%04d %02d:%02d:%02d", day2, month2, year2, hour2, minute2, second2);

                            Event *e1 = makeEvent(t1, t2);
                            allCalendar->count = addCalendar(allCalendar, e1);
                        }
                    }
                    break;
                }
                    default:
                        {
                            break;
                        }
            }
        printf("\n");
        fgets(linia, sizeof linia, stdin);
    }

    freeCalendar(allCalendar);
}
