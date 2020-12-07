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

#include "swatch++/swatch++.hpp"

double swatch::Beats(struct tm *t) {
    auto utc = t->tm_hour * 3600 +
        t->tm_min * 60 +
        t->tm_sec;
    auto bmt = (utc + 3600) % 86400;
    return double(bmt) * 1000.0 / 86400.0;
}

std::string swatch::SwatchNow() {
    auto epoch = time(nullptr);
    struct tm tbuf;
    auto t = gmtime_r(&epoch, &tbuf);
    return swatch::SwatchTime(t);
}

std::string swatch::SwatchTime(struct tm *t) {
    std::stringstream result;
    result << "@";
    result.setf(std::ios::fixed, std::ios::floatfield);
    result.width(6);
    result.precision(2);
    result.fill('0');
    result << swatch::Beats(t);
    return result.str();
}
