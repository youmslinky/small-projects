#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

// #define SHARED
//this demonstrates a race condition with printing using std::cout

//if SHARED is defined, it will use a mutex regulated print

//if SHARED is not defined, when running the program, there will be random
//cases where cout didn't finish from main, or from the thread 
//basically, the main program and thread will stomp on each other's print statements

using namespace std;

mutex mu;

void shared_print(string msg, int id)
{
    mu.lock();
    cout << msg << id << endl;
    mu.unlock();
}

void non_shared_print(string msg, int id)
{
    cout << msg << id << endl;
}

void a_function()
{
    for(int i=0;i>-200;i--)
#ifdef SHARED
        shared_print("From t1: ",i);
#endif
#ifndef SHARED
        non_shared_print("From t1: ",i);
#endif
}

int main(){
    thread t1(a_function);
    // t1.detach();

    for(int i=0;i<200;i++)
#ifdef SHARED
        shared_print("From Main: ",i);
#endif
#ifndef SHARED
        non_shared_print("From Main: ",i);
#endif

    t1.join();
    return 0;
}
