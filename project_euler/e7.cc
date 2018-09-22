#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long n){
    for(long long i=n/2;i>1;i--){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    long long n = 2;
    int i= 0;
    while(i<10001){
        if(isPrime(n)){
            i++;
        } 
        n++;
    }
    cout << n-1 << endl;
    return 0;

}
