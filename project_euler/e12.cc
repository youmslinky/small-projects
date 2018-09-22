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
    out.push_back(n);
    return out;
}

int main(){
    //for(long i=1;i<100;i++){
    //    vector<long> divs = divisors(i);
    //    cout << i << endl;
    //    for(int j=0;j<divs.size();j++){
    //        cout << divs[j] << ' ';
    //    }
    //    cout << endl;
    //}
    long tri=1;
    long i=2;
    vector<long> longest;
    long mostFac=0;
    long lenLongest=longest.size();
    while(lenLongest < 1000){
        vector<long> can = divisors(tri);
        if(can.size()>lenLongest){
            longest = can;
            lenLongest=longest.size();
            mostFac = tri;
            cout << "length: " << lenLongest << " n: " << mostFac << endl;
        }
        tri+=i;
        i++;
    }
    return 0;
}
