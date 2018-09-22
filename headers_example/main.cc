#include <iostream>
#include <vector>
#include <math.h>
#include "primes.h"

using namespace std;

int main(){
    cout << "max number to sieve: ";
    int max;
    cin >> max;
    vector<bool> primes = sieve(max);
    for(unsigned i;i<primes.size();i++){
        if(primes[i]){
            cout << i+2 << ' ';
        }
    }
    cout << endl;
    return 0;
}
