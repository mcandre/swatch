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

double swatch::Beats(time_t t) {
    auto bmt = (t + 3600) % 86400;
    return double(bmt) / 86.4;
}

std::string swatch::SwatchNow() {
    return swatch::SwatchTime(time(nullptr));
}

std::string swatch::SwatchTime(time_t t) {
    std::stringstream result;
    result << "@";
    result.setf(std::ios::fixed, std::ios::floatfield);
    result.width(6);
    result.precision(2);
    result.fill('0');
    result << swatch::Beats(t);
    return result.str();
}
