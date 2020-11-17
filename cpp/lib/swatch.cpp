/*
    Andrew Pennebaker (andrew.pennebaker@gmail.com)
    Copyright 2007 Andrew Pennebaker

    Credits:

    http://www.krugle.com/files/cvs/cvs.jabberstudio.org/neutron/plugins/time_plugin.py
    For the basic conversion method.

    http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.15.html
    Thanks for actual working example of C's time and date libraries.
*/

#include "swatch.hh"

#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using std::endl;

double beats() {
    auto timer = time(nullptr);
    struct tm tbuf;
    auto g = gmtime_r(&timer, &tbuf);
    auto hour = g->tm_hour, min = g->tm_min, sec = g->tm_sec;
    auto utc = hour * 3600 + min * 60 + sec;
    auto bmt = (utc + 3600) % (24 * 3600);
    auto beat = bmt / 86.4;
    return beat;
}

string swatch() {
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
    std::cout << swatch() << endl;
    return EXIT_SUCCESS;
}
