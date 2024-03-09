#include "dec_to_bin.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal = 25;

    char* binaryStr = decToBin(decimal);

    printf("Decimal: %d\n", decimal);
    printf("Binary: %s\n", binaryStr);

    free(binaryStr);

    return 0;
}