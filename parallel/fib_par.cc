#include <iostream>
#include <unistd.h>
#include <thread>
#include <unordered_map>
#include <chrono>

/*
   this demonstrates a straight recursive and memoized version of fibonacci
   using threads

   These are not very good, because a thread is spawned for every calculation
   that has to be done, which causes problems at bigger magnitudes of fibonacci
   calls
*/

void fib_par(long &n) {
    if (n < 2) {
        return;
    } else {
        long a = n-1;
        long b = n-2;
        std::thread ta(fib_par,std::ref(a));
        std::thread tb(fib_par,std::ref(b));
        ta.join();
        tb.join();
        n = a + b;
    }
}

void fib_par_memo(long &n) {
    long orig_n = n;
    static std::unordered_map<long, long> fibs; 
    if (n < 2) {
        return;
    }
    else if(fibs.count(n) != 0){
        n = fibs[orig_n];
        return;
    } else {
        long a = n-1;
        long b = n-2;
        std::thread ta(fib_par,std::ref(a));
        std::thread tb(fib_par,std::ref(b));
        ta.join();
        tb.join();
        n = a + b;
        fibs[orig_n] = n;
    }
}

int main()
{
    long MAX = 20;

    auto start = std::chrono::steady_clock::now();
    for(long i=0; i<MAX; ++i)
    {
        long n = i;
        fib_par(n);
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    auto finish = std::chrono::steady_clock::now();

    auto start_memo = std::chrono::steady_clock::now();
    std::cout << std::endl;
    for(long i=0; i<MAX; ++i)
    {
        long n = i;
        fib_par_memo(n);
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    auto finish_memo = std::chrono::steady_clock::now();
    double elapsed_seconds = std::chrono::duration_cast<
        std::chrono::duration<double> >(finish - start).count();
    double elapsed_seconds_memo = std::chrono::duration_cast<
        std::chrono::duration<double> >(finish_memo - start_memo).count();
    std::cout << "time elapsed:      " << elapsed_seconds << " seconds" << std::endl;
    std::cout << "time elapsed memo: " << elapsed_seconds_memo << " seconds" << std::endl;
    return 0;
}