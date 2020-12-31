#include <cstdint>
#include <cstdio>

#include "life.h"

char state[8][8] = {{0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0}};

char nextState[8][8];

int main()
{
    for(uint64_t i=0; i<0xffffffffffffffff; i++){
        printf("%llu\n", i);
        printUint64_t(findStillLife());
        printf("\n");
    }
}
