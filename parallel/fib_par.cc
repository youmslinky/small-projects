#include <iostream>
#include <unistd.h>

using namespace std;


int main()
{
	int* point = new int;

	*point = 112;

	int pid = fork();

	if(pid == 0)
	{
		//child process
		*point = 888;
	}
	else
	{
		*point = 555;
	}

	

	cout << "value of point: " << point << endl;
	cout << "value of point: " << *point << endl;

	return 0;
}