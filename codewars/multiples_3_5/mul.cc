#include <iostream>

using namespace std;

int solution(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i%3==0 || i%5==0){ sum += i;
			cout << i << " ";
		}
	}
	return sum;
}

int main(){
	while(1){
		int n;
		cout << "n: ";
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}