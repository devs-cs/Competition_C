#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>


std::vector<int> fibDp;
//vector named fibDp of type int
int exp(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * exp(a, b - 1);
}



int fib(int a, int b)
{
    if (fibDp.size() == 0)
    {
        fibDp.push_back(0);
        fibDp.push_back(1);
    }
    if (b < fibDp.size())
        return fibDp[b];
    else
    {
        int res = fib(a, b - 1) + fib(a, b - 2);
        fibDp.push_back(res);
        return res;
    }
}

int main()
{
// timer
    auto start = std::chrono::high_resolution_clock::now();
// compute first 100 fibonacci numbers
    for (int i = 0; i < 100; i++)
    {
        std::cout << fib(0, i) << std::endl;
    } 
    // display elapsed time in a GUI

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}