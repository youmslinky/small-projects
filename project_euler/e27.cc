#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include "./libs/primes.h"

using namespace std;

uint64_t LENGTH = 100*100+1000*100+1000;

Sieve sieve(LENGTH);

uint64_t prime_len(int64_t a,int64_t b){
	int64_t n=0;

	while(sieve.isPrime(n*n+a*n+b)){
		n++;
	}
	return n;
}

int main(){
	uint64_t longest = 0;
	for(int64_t a=-1000; a<1000; ++a){
		for(int64_t b=-1000; b<1000; ++b){
			uint64_t can_len = prime_len(a,b);
			if(can_len > longest){
				cout << "a: " << a << " b: " << b << " prime len: " << prime_len(a,b) << endl;
				for(uint64_t n=0;n<can_len;++n){
					cout << n*n+a*n+b << ' ';
				}
				cout << endl <<endl;
				longest = can_len;
			}
		}
	}
	return 0;
}
