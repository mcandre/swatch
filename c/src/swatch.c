/**
 * @copyright 2020 YelloSoft
 */

#include "swatch/swatch.h"

double beats(struct tm *t) {
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;
    int utc = hour * 3600 + min * 60 + sec;
    int bmt = (utc + 3600) % (24 * 3600);
    double beat = bmt / 86.4;
    return beat;
}

void swatch_now(char *result) {
    time_t timer = time(NULL);
    struct tm tbuf;
    struct tm *t = gmtime_r(&timer, &tbuf);
    swatch_time(t, result);
}

void swatch_time(struct tm *t, char *result) {
    (void) snprintf(result, sizeof(result), "@%06.2f", beats(t));
}
