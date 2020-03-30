#include <iostream>

using namespace std;

int main(void)
{
    long sum = 1;
    long val = 1;
    for(long sideLen = 3; sideLen <= 1001; sideLen += 2)
    {
        // cout << sideLen-1 << endl;
        for(int i =0; i<4; ++i)
        {
            val += sideLen-1;
            sum += val;
            // cout << val << ' ';
        }
        // cout << endl;
        // cout << "current sum = " << sum << endl;
    }
    cout << sum << endl;
    return 0;
}
