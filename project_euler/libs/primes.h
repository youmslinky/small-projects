#ifndef _primes_H
#define _primes_H

#include <vector>
#include <cstdint>

bool isPrime(uint64_t);
std::vector<bool> bool_sieve(uint64_t);
std::vector<uint64_t> int_sieve(uint64_t);
class Sieve
{
private:
	uint64_t maxPrime; //largest value in sieve object

public:
	std::vector<uint64_t> intSieve;

	Sieve(uint64_t);
	~Sieve();

	void generatePrimes(uint64_t);
	bool isPrime(uint64_t n);
	uint64_t max_prime();
};

#endif
