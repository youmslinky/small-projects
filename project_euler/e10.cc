#include <iostream>
#include <vector>
#include <math.h>

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

int main(){
    long long i;
    cout << "enter max number to sum primes to: ";
    cin >> i;
    vector<bool> p = sieve(i);
    long long sum=0;
    for(int i=0;i<p.size();i++){
        if(p[i]){
            //cout << i+2 << ' ';
            sum += i+2;
        }
    }
    cout << endl << "sum of primes: " << sum << endl;
}
