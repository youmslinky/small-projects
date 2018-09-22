#include <iostream>
using namespace std;
string return_string(){
	return "what";
}
string eoo(int n){
	if(n&1) return "Odd";
	return "Even";

}

int main(){

	while(true){
		int n;
		cout << "n: ";
		cin >> n;
		cout << eoo(n) << endl;
	}

	return 0;
}

