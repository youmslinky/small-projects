#include <iostream>
using namespace std;

int main(){

    string str = "0005700900";
    //str.erase(0, str.find_first_not_of('0'));
    //str.erase(str.find_last_not_of('0'), 100);
    //cout << str << endl;
    //cout << "helloasdf" << endl;
	cout << "original string: " << str << endl;
	cout << "find_first_not_of('0'): " << str.find_first_not_of('0') << endl;
	cout << "find_last_not_of('0'): " << str.find_last_not_of('0') << endl;
	str.erase(str.find_last_not_of('0')+1,100);
	str.erase(0,str.find_first_not_of('0'));
	cout << "string after erase: " << str << endl;
	return 0;
}

