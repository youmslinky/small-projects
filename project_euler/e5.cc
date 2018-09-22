#include <iostream>

using namespace std;

bool is_div(long long unsigned n){
    for(int i=2;i<=20;i++){
	if(n%i!=0){
	    return false;
	}
    }
    return true;
}
int main(){
    long long unsigned n=10;
    while (!is_div(n)){
	if(n%10000==0){
            cout << n << endl;
        }
	n++;
    }
    cout << "found it: " << n << endl;

    return 0;
}
