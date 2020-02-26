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
#include <time.h>

static double beats(void) {
    time_t timer = time(NULL);
    struct tm *g = gmtime(&timer);

    if (g == NULL) {
        fprintf(stderr, "gmtime returned NULL!\n");
        return -1.0;
    }

    int hour = g->tm_hour;
    int min = g->tm_min;
    int sec = g->tm_sec;
    int utc = hour * 3600 + min * 60 + sec; // Greenwich, England
    int bmt = (utc + 3600) % (24 * 3600); // Biel, Switzerland
    double beat = bmt / 86.4;
    return beat;
}

static /*@null@*/ char *swatch() {
    char *result = (char *) malloc(sizeof(char) * 8);

    if (result == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return NULL;
    }

    double b = beats();

    if (fabs(b - -1.0) <= DBL_EPSILON) {
        return result;
    }

    (void) snprintf(result, 8, "@%06.2f", b);
    return result;
}

int main() {
    char *s = swatch();

    if (s == NULL) {
        free(s);
        return 1;
    }

    printf("%s\n", s);
    free(s);
    return 0;
}
