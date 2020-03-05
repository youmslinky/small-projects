#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include "./libs/primes.h"

using namespace std;

vector<uint64_t> primes;

#define LENGTH 100000000
uint64_t prime_len(int64_t a,int64_t b){
	int64_t n=0;
	while(binary_search(primes.begin(), primes.end(), n*n+a*n+b)){
		if(n*n+a*n+b > LENGTH) cout << "need higher primes" << endl;
		n++;
	}
	return n;
}

int main(){
	primes = int_sieve(LENGTH);
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
