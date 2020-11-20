/**
 * @copyright 2020 YelloSoft
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swatch/swatch.h"

int main() {
    char result[8];
    memset(result, 0, sizeof(result));
    swatch_now(result);
    printf("%s\n", result);
    return EXIT_SUCCESS;
}
