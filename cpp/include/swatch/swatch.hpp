#pragma once

/**
 * @copyright 2020 YelloSoft
 * @mainpage
 *
 * @ref swatch processes Internet time.
 */

#include <ctime>
#include <string>

/** swatch processes Internet time. */
namespace swatch {
    /**
     * Beats counts out Swatch beats.
     *
     * @param t time
     * @returns Swatch beat count
     */
    double Beats(time_t t);

    /**
     * SwatchNow formats the current Internet time.
     *
     * @returns Internet time
     */
    std::string SwatchNow();

    /**
     * SwatchTime formats a given time as Internet time.
     *
     * @param t time
     * @returns Internet time
     */
    std::string SwatchTime(time_t t);
}
