/*
    Andrew Pennebaker (andrew.pennebaker@gmail.com)
    Copyright 2007 Andrew Pennebaker

    Credits:

    http://www.krugle.com/files/cvs/cvs.jabberstudio.org/neutron/plugins/time_plugin.py
    For the basic conversion method.

    http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.15.html
    Thanks for actual working example of C's time and date libraries.
*/

#include <cfloat>
#include <cmath>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::endl;
using std::string;

static double beats(void) {
    auto timer = time(nullptr);
    struct tm *g = gmtime(&timer);

    if (g == nullptr) {
        std::cerr << "gmtime returned NULL!" << endl;
        return -1.0;
    }

    auto hour = g->tm_hour, min = g->tm_min, sec = g->tm_sec;
    auto utc = hour * 3600 + min * 60 + sec; // Greenwich, England
    auto bmt = (utc + 3600) % (24 * 3600); // Biel, Switzerland
    auto beat = bmt / 86.4;
    return beat;
}

static string swatch() {
    auto b = beats();

    if (fabs(b - -1) < DBL_EPSILON) {
        return "";
    }

    std::stringstream result;
    result << "@";
    result.setf(std::ios::fixed, std::ios::floatfield);
    result.width(6);
    result.precision(2);
    result.fill('0');
    result << beats();
    return result.str();
}

int main() {
    auto s = swatch();

    if (s == "") {
        return 1;
    }

    std::cout << s << endl;
    return 0;
}
