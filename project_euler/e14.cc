#include <iostream>
#include <vector>

using namespace std;

vector<long> collatz(long n){
    vector<long> out;
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

int main(){
    vector<long> longest;
    long i=13;
    while(i<1000000){
        vector<long> can = collatz(i);
        if(can.size() > longest.size()){
            longest = can;
            cout << i << " len: " << longest.size();
            cout << endl;
        }
        i++;
    }

    for(unsigned long i=0;i<longest.size();i++){
        cout << longest[i] << ' ';
    }
	cout << endl;

    return 0;
}
