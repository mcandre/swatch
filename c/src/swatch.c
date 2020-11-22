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

int swatch_now(char *result) {
    time_t epoch = time(NULL);
    struct tm tbuf;
    struct tm *t = gmtime_r(&epoch, &tbuf);
    return swatch_time(result, t);
}

int swatch_time(char *result, struct tm *t) {
    size_t sz = 8;
    int bytes_written = snprintf(result, sz, "@%06.2f", beats(t));

    if (bytes_written < 0 || (size_t) bytes_written > sz) {
        return -1;
    }

    return 0;
}
