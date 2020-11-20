#pragma once

/**
 * @copyright 2020 YelloSoft
 * @mainpage
 *
 * @ref beats converts the given time to the Swatch beat count.
 *
 * @ref swatch_now presents the current Internet time.
 *
 * @ref swatch_time formats the given time as Internet time.
 */

#include <ctime>
#include <string>

using std::string;

/**
 * beats counts out Swatch beats.
 *
 * @param t time
 * @returns Swatch beat count
 */
double beats(struct tm *t);

/**
 * swatch_now formats the current Internet time.
 *
 * @returns Internet time
 */
string swatch_now();

/**
 * swatch_time formats a given time as Internet time.
 *
 * @param t time
 * @returns Internet time
 */
string swatch_time(struct tm *t);
