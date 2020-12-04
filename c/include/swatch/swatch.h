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

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief beats counts out Swatch beats.
 *
 * @param t UTC
 * @returns Swatch beat count
 */
double beats(struct tm *t);

/**
 * @brief swatch_now formats the current Internet time.
 *
 * @param result buffer (8 bytes)
 */
void swatch_now(char *result);

/**
 * @brief swatch_time formats a given time as Internet time.
 *
 * @param result buffer (8 bytes)
 * @param t UTC
 */
void swatch_time(char *result, struct tm *t);
