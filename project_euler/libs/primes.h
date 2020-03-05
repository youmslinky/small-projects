#ifndef _primes_H
#define _primes_H

#include <vector>
#include <math.h>
#include <cstdint>

bool isPrime(uint64_t);
std::vector<bool> bool_sieve(uint64_t);
std::vector<uint64_t> int_sieve(uint64_t);

#endif
