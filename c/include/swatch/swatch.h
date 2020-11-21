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
 * @param t UTC
 * @returns Swatch beat count
 */
double beats(struct tm *t);

/**
 * swatch_now formats the current Internet time.
 *
 * @param result buffer
 * @param result_size buffer size (bytes)
 *
 * @returns bytes written. A value outside [0, result_size] indicates error.
 */
int swatch_now(char *result, size_t result_size);

/**
 * swatch_time formats a given time as Internet time.
 *
 * @param result buffer
 * @param result_size buffer size (bytes)
 * @param t UTC
 *
 * @returns bytes written. A value outside [0, result_size] indicates error.
 */
int swatch_time(char *result, size_t result_size, struct tm *t);
