#include <iostream>

using namespace std;
int main()
{
    int fib1 = 1;
    int fib2 = 1;
    int counter = 2;
    while((fib1 + fib2) % 289 != 0)
    {
        int temp = fib2;
        fib2 = fib1;
        fib1 = (temp + fib1)% 289;
        counter++;
        if(fib1 % 17 ==0 )
            cout<<counter << " " << fib1/17 << " " << counter/9 << endl;
    } 
    counter++;
    cout << counter <<  " " << (fib1 + fib2)/17 << " " << counter/9 << endl;
}

