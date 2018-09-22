#include <iostream>

using namespace std;

template <class T>
T returnArg(T in){
	return in;
}

int main(){
	cout << returnArg(69) << endl;
	cout << returnArg('w') << endl;
	cout << returnArg("hello") << endl;

	return 0;
}