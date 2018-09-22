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
bool isAbun(long n){
    return sumVec(divisors(n))>n;
}

int main(){
    long sum=0;
    vector<long> abun;
    vector<bool> notSum(30000, true);
    for(long i=1;i<28123;i++){
        if(isAbun(i)){
            abun.push_back(i);
            cout << i << ' ';
        }
    }
    cout << "\n\n\n";
    for(long i=0;i<abun.size();i++){
        for(long j=0;j<abun.size()-i;j++){
            long index = abun[i]+abun[i+j];
            if(index < notSum.size()){
                notSum[abun[i]+abun[i+j]] = false;
            }
        }
    }
    for(long i=0;i<notSum.size();i++){
        if(notSum[i]){
            sum += i;
        }
    }
    cout << "\n\n\n what the hell\n";
    cout << "sum: " << sum << endl;
	
    return 0;
}
