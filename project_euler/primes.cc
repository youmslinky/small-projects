#include <vector>
#include <math.h>
#include "primes.h"
using namespace std;

bool isPrime(long long n){
    for(long long i=n/2;i>1;i--){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

vector<bool> sieve(long long max){
    vector<bool> out;
    for(long long i=2;i<=max;i++){
        out.push_back(true);
    }
    
    for(long long i=2;i<=(long long)sqrt(max);i++){
        if(out[i-2]){
            long long i2 = i*i;
            for(long long j=i2;j<=max;j+=i){
                out[j-2] = false;
            }
        }
    }
    return out;
}
