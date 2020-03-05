#include "primes.h"

#include <math.h>
#include <algorithm>
#include <iostream>

bool isPrime(uint64_t n){
    for(uint64_t i=n/2;i>1;i--){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

std::vector<bool> bool_sieve(uint64_t max){
    std::vector<bool> out(max,true);

    for(uint64_t i=2;i<=(uint64_t)sqrt(max);i++){
        if(out[i-2]){
            uint64_t i2 = i*i;
            for(uint64_t j=i2;j<=max;j+=i){
                out[j-2] = false;
            }
        }
    }
    return out;
}

std::vector<uint64_t> int_sieve(uint64_t max){
	std::vector<bool> b_sieve = bool_sieve(max);
	std::vector<uint64_t> out = {1};
	for(uint64_t i=0; i<b_sieve.size()-1; ++i){
		if(b_sieve[i]){
			out.push_back(i+2);
		}
	}
	return out;
}

Sieve::Sieve(uint64_t max_prime){
	generatePrimes(max_prime);
}

Sieve::~Sieve(){
}

void Sieve::generatePrimes(uint64_t max_prime){
	intSieve = int_sieve(max_prime);
	maxPrime = intSieve.back();
}

bool Sieve::isPrime(uint64_t n){
	// if(n>maxPrime){
	// 	std::cout << "**** " << n << " is larger than largest prime calculated ****" << std::endl;
	// 	std::cout << "maxPrime: " << maxPrime << std::endl;
	// }
	return std::binary_search(intSieve.begin(), intSieve.end(), n);
}

uint64_t Sieve::max_prime(){
	return maxPrime;
}
