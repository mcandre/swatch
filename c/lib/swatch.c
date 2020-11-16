/*
    Andrew Pennebaker (andrew.pennebaker@gmail.com)
    Copyright 2007 Andrew Pennebaker

    Credits:

    http://www.krugle.com/files/cvs/cvs.jabberstudio.org/neutron/plugins/time_plugin.py
    For the basic conversion method.

    http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.15.html
    Thanks for actual working example of C's time and date libraries.
*/

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double beats(void) {
    time_t timer = time(NULL);
    struct tm tbuf;
    struct tm *g = gmtime_r(&timer, &tbuf);

    int hour = g->tm_hour;
    int min = g->tm_min;
    int sec = g->tm_sec;
    int utc = hour * 3600 + min * 60 + sec;
    int bmt = (utc + 3600) % (24 * 3600);
    double beat = bmt / 86.4;
    return beat;
}

static void swatch(char *result) {
    (void) snprintf(result, sizeof(result), "@%06.2f", beats());
}

int main() {
    char result[8];
    memset(result, 0, sizeof(result));
    swatch(result);
    printf("%s\n", result);
    return EXIT_SUCCESS;
}
