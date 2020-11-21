/**
 * @copyright 2020 YelloSoft
 */

#include "swatch/swatch.h"

double beats(time_t t) {
    int bmt = (t + 3600) % 86400;
    return (double) bmt / 86.4;
}

void swatch_now(char *result) {
    swatch_time(time(NULL), result);
}

void swatch_time(time_t t, char *result) {
    (void) snprintf(result, sizeof(result), "@%06.2f", beats(t));
}
