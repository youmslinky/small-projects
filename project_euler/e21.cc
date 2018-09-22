#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long> divisors(long n){
    vector<long> out;
    out.push_back(1);
    long i=2;
    while(i<=sqrt(n)){
        if(n%i==0){
            out.push_back(i);
            if(i!=(n/i)){
                out.push_back(n/i);
            }
        }
        i++;
    }
    return out;
}
long sumVec(vector<long> v){
    long out=0;
    for(int i=0;i<v.size();i++){
        out+=v[i];
    }
    return out;
}

int main(){
    long sum=0;
    for(long i=1;i<10000;i++){
        long can = sumVec(divisors(i));
        long can2 = sumVec(divisors(can));
        if(i == can2 && can != can2){
            sum += i;
            cout << i << endl;
        }
    }
    cout << sum << endl;
	
    return 0;
}
