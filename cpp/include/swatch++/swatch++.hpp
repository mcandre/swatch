#pragma once

/**
 * @copyright 2020 YelloSoft
 * @mainpage
 *
 * @ref swatch processes Internet time.
 */

#include <ctime>
#include <string>

/** @brief swatch processes Internet time. */
namespace swatch {
    /**
     * Beats counts out Swatch beats.
     *
     * @param t UTC
     * @returns Swatch beat count
     */
    double Beats(struct tm *t);

    /**
     * @brief SwatchNow formats the current Internet time.
     *
     * @returns Internet time
     */
    std::string SwatchNow();

    /**
     * @brief SwatchTime formats a given time as Internet time.
     *
     * @param t UTC
     * @returns Internet time
     */
    std::string SwatchTime(struct tm *t);
}
