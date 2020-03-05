#include <iostream>
#include <vector>
#include <cstdint>

#ifndef LENGTH
#define LENGTH 1000000
#endif

using namespace std;

vector<uint64_t> collatz(uint64_t n){
    vector<uint64_t> out;
    while(n>1){
        out.push_back(n);
        if(n%2==0){
            n /= 2;
        } else {
            n = 3*n+1;
        }
    }
    out.push_back(1);
    return out;
}

uint64_t collatzLength(uint64_t n){
	if(n==0 || n==1){
		return 1;
	}
	if(n%2==0){
		return 1+collatzLength(n/2);
	} else {
		return 1+collatzLength(3*n+1);
	}
}

int main(){
	uint64_t i = 0;
	uint64_t longest_i = 1;
	uint64_t longest_length = 1;
	while(i++<LENGTH){
		uint64_t len = collatzLength(i);
		if(len > longest_length){
			longest_i = i;
			longest_length = len;
            cout << i << " len: " << longest_length << endl;
		}
	}
    vector<uint64_t> longest = collatz(longest_i);
    for(uint64_t i=0;i<longest.size();i++){
        cout << longest[i] << ' ';
    }
	cout << endl;

	return 0;
}

