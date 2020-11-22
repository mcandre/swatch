/**
 * @copyright 2020 YelloSoft
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swatch/swatch.h"

int main() {
    char buf[8];

    if (swatch_now(buf) < 0) {
        fprintf(stderr, "error writing to buffer\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", buf);
    return EXIT_SUCCESS;
}
