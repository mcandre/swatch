/**
 * @copyright 2020 YelloSoft
 */

#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <sstream>

#include "swatch/swatch.hpp"

double beats(struct tm *t) {
    auto hour = t->tm_hour, min = t->tm_min, sec = t->tm_sec;
    auto utc = hour * 3600 + min * 60 + sec;
    auto bmt = (utc + 3600) % (24 * 3600);
    auto beat = bmt / 86.4;
    return beat;
}

string swatch_now() {
    auto timer = time(nullptr);
    struct tm tbuf;
    auto t = gmtime_r(&timer, &tbuf);
    return swatch_time(t);
}

string swatch_time(struct tm *t) {
    std::stringstream result;
    result << "@";
    result.setf(std::ios::fixed, std::ios::floatfield);
    result.width(6);
    result.precision(2);
    result.fill('0');
    result << beats(t);
    return result.str();
}
