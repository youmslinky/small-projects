#include <iostream>
#include <thread>
#include <unistd.h>
//#include <exception>

using namespace std;

void a_function()
{
	usleep(1000000);
	cout << "hello from child!" << endl;
}

int main(){
	thread t1(a_function);
	cout << "hello from the parent thread!" << endl;
	// t1.detach();
	t1.join();
	cout << "end of program here" << endl;
	return 0;
}
