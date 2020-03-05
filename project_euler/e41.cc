#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include "./libs/primes.h"

using namespace std;

bool is_pandigital(uint64_t n){
	string s = to_string(n);
	sort(s.begin(), s.end());

	for(size_t i=0; i<s.size(); ++i) {
		if((size_t)(s[i]-'0') != i+1){
			return false;
		}
	}
	return true;
}

int main(){
	auto primes = int_sieve(987654321);
	for (auto it : primes) {
		if(is_pandigital(it)){
			cout << it << " is pandigital*********" << endl;
		}
	}
	cout << endl;
	return 0;
}
