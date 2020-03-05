#include "primes.h"

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
    // for(uint64_t i=2;i<=max;i++){
    //     out.push_back(true);
    // }
    
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
	std::vector<uint64_t> out;
	for(uint64_t i=0; i<b_sieve.size()-1; ++i){
		if(b_sieve[i]){
			out.push_back(i+2);
		}
	}
	return out;
}
