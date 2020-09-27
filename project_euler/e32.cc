#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <vector>
#include "./libs/primes.h"

using namespace std;

bool is_pandigital(string s){
    sort(s.begin(), s.end());

    for(size_t i=0; i<s.size(); ++i) {
        if((size_t)(s[i]-'0') != i+1){
            return false;
        }
    }
    return true;
}

int main(){
    // auto primes = int_sieve(987654321);
    // cout << "prime sieve is done" << endl;
    // for (auto it : primes) {
    //     if(is_pandigital(it)){
    //         cout << it << " is pandigital*********" << endl;
    //     }
    // }
    for(uint32_t i = 1; i<100000; ++i)
    {
        for(uint32_t j = 1; j<100000; ++j)
        {
            if(i*j >= 987654321)
            {
                cout << '\t' << i << "x" << j << "=" << i*j << endl;
                j = 99999999;
                i = 99999999;
            }
        }
    }
    for(uint32_t i = 1; i<9877; ++i)
    {
        string s1 = to_string(i);
        for(uint32_t j = 1; j<99996; ++j)
        {
            uint32_t ij = i*j;
            string s = s1 + to_string(j) + to_string(ij);
            if(is_pandigital(s))
            {
                cout << '\t' << i << "x" << j << "=" << i*j << endl;
            }
            // if((i+j) % 100000 == 0)
            // {
            //     cout << i << "x" << j << "=" << i*j << endl;
            // }
        }
    }
    return 0;
}
