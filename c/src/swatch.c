/**
 * @copyright 2020 YelloSoft
 */

#include "swatch/swatch.h"

double beats(struct tm *t) {
    int utc = t->tm_hour * 3600 +
        t->tm_min * 60 +
        t->tm_sec;
    int bmt = (utc + 3600) % 86400;
    return (double) bmt * 1000.0 / 86400.0;
}

void swatch_now(char *result) {
    time_t epoch = time(NULL);
    struct tm tbuf;
    struct tm *t = gmtime_r(&epoch, &tbuf);
    swatch_time(result, t);
}

void swatch_time(char *result, struct tm *t) {
    (void) snprintf(result, sizeof(result), "@%06.2f", beats(t));
}
