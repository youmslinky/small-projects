#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>


using namespace std;

mutex mu;

void shared_print(string msg, int id)
{
	mu.lock();
	cout << msg << id << endl;
	mu.unlock();
}

void a_function()
{
	for(int i=0;i>-200;i--)
		shared_print("From t1: ",i);
	int blah;
	cin >> blah; 
}

int main(){
	thread t1(a_function);

	for(int i=0;i<200;i++)
		shared_print("From main: ",i);

	//t1.detach();
	t1.join();
	cout << "joined with thread" << endl;
	int blah;
	cin >> blah; 
	cout << "end of program here" << endl;
	return 0;
}
