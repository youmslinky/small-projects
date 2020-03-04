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
    cout << "enter max number: ";
    //cin >> i;
    int max=1000000;
    vector<bool> p = sieve(max);
    vector<int> pri;
    //pri has the actual integer values, not just boolean
    for(unsigned long i=0;i<p.size();i++){
        if(p[i]){
            pri.push_back(i+2);
        }
    }
    vector<int> longest;
    vector<int> can;
    int highest = 0;
    for(unsigned long i=0;i<12;i++){
        cout << "i: " << i << endl;
        int j=0;
        for(int sum=0;sum<max && i+j<pri.size();sum+=pri[i+j]){
            can.push_back(pri[i+j]);
            if(isPrime(sum) && can.size()>longest.size()){
                highest = sum;
                longest = can;
                cout << "longest so far: " << highest << endl;
            }
            j++;
        }
        j=0;
        can.clear();
    }
    for(unsigned long i=0;i<longest.size();i++){
        cout << longest[i] << ' ';
    }
    cout << endl;
    cout << highest << endl;
}
