#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	string str2;
	cout << "enter 2 strings: ";
	cin >> str1 >> str2;
	if(str1 > str2)
	{
		cout << str1 << " is more than " << str2 << endl;
	}
	if(str1 < str2)
	{
		cout << str1 << " is less than " << str2 << endl;
	}
	return 0;
}