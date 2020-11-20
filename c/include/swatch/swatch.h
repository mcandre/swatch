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
 * beats counts out Swatch beats.
 *
 * @param t time
 * @returns Swatch beat count
 */
double beats(struct tm *t);

/**
 * swatch_now formats the current Internet time.
 *
 * @param result answer buffer
 */
void swatch_now(char *result);

/**
 * swatch_time formats a given time as Internet time.
 *
 * @param t time
 * @param result answer buffer
 */
void swatch_time(struct tm *t, char *result);
