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

int swatch_now(char *result, size_t result_size) {
    time_t epoch = time(NULL);
    struct tm tbuf;
    struct tm *t = gmtime_r(&epoch, &tbuf);
    return swatch_time(result, result_size, t);
}

int swatch_time(char *result, size_t result_size, struct tm *t) {
    if (result_size < 7) {
        return -1;
    }

    return snprintf(result, result_size, "@%06.2f", beats(t));
}
