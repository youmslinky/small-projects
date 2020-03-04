#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

std::unordered_map<uint64_t, uint64_t> umap; 
// umap stores the length of n
// so like umap[1] = 1 because 1 has a length of 1
// umap[2] = 2


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
	if(umap.count(n) == 0){
		// cout << n << " is NOT in the map" << endl;
        if(n%2==0){
			umap[n] = 1+collatzLength(n/2);
        } else {
			umap[n] = 1+collatzLength(3*n+1);
        }
	} else {
		// cout << n << " IS in the map" << endl;
	}
	return umap[n];
}

int main(){
	uint64_t i = 0;
	uint64_t longest_i = 1;
	uint64_t longest_length = 1;
	while(i++<1000000){
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

