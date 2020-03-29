#include <iostream>
#include <vector>
#include <cstdint>

const uint64_t fac[10]= {
    1,1,2,6,24,120,720,5040,40320,362880
};

std::vector<uint64_t> getDigits(uint64_t n)
{
    std::vector<uint64_t> ret_vec;
    while(n > 0)
    {
        ret_vec.push_back(n % 10);
        n /= 10;
    }
    return ret_vec;
}

uint64_t facSum(std::vector<uint64_t> v)
{
    uint64_t sum = 0;
    for (auto i : v) {
        sum += fac[i];
    }
    return sum;
}

int main(int argc, char *argv[])
{
    uint64_t total_sum = 0;
    for(uint64_t i = 3; i<1000*1000*10; ++i)
    {
        std::vector<uint64_t> v = getDigits(i);
        uint64_t sum = facSum(v);
        if(sum == i)
        {
            std::cout << facSum(v) << std::endl;
            total_sum += i;
        }
    }
    std::cout << "summed together: " << total_sum << std::endl;
    return 0;
}
