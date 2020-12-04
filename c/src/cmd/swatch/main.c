/**
 * @copyright 2020 YelloSoft
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swatch/swatch.h"

int main() {
    char buf[8];
    swatch_now(buf);
    printf("%s\n", buf);
    return EXIT_SUCCESS;
}
