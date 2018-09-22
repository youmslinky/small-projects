#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    int i=0;
    int sleepBalance = 1000; // increase this to reduce the CPU load
    int computeBalance = 1000; // increase this to increase the CPU load
    cout << "input sleep balance: ";
    cin >> sleepBalance;
    cout << "input compute balance: ";
    cin >> computeBalance;
    while(true)
    {
       for (int i=0; i<computeBalance; i++)
       {
         /* both volatiles are important to prevent compiler */
         /* optimizing out the function */
         volatile int n = 30;
         volatile int pretendWeNeedTheResult = n*n*n*n+n+n+100;
       }
       usleep(sleepBalance);
    }
    return 0;
}

