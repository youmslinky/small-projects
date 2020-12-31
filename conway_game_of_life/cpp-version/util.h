#pragma once
#include <cstdint>
#include <cstdio>
extern char state[8][8];

void set_state_to_uint64(uint64_t num);
uint64_t lfsr_next();
uint64_t array_to_uint64(char array[8][8]);
void printUint64_t(uint64_t num);
