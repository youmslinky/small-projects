#include "util.h"
uint64_t array_to_uint64(char array[8][8])
{
    int shift = 0;
    uint64_t num = 0;
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            num |= (uint64_t)state[c][r]<<shift;
            shift++;
        }
    }
    return num;
}

void set_state_to_uint64(uint64_t num)
{
    int shift = 0;
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            state[c][r] = (num>>shift) & 1;
            shift++;
        }
    }
}

void printUint64_t(uint64_t num)
{
    int shift = 0;
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            if((num>>shift) & 0b1)
                printf("0");
            else
                printf(".");
            shift++;
        }
        printf("\n");
    }
}
