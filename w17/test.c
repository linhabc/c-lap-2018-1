#include <stdio.h>
int main() {
    unsigned long temp  = 0x123058746;
    unsigned long mask = 0xF;
    temp = temp >> 8;
    temp = temp & mask;
    printf("%lu", temp);
    return 0;
}