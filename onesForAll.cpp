#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <tgmath.h>
using namespace std;
int dp[100010] = {0};
bool used[100010] = {false};


int forAll(int n)
{
    // cout << "run " << n << endl;
    if(used[n])
        return dp[n];
    if(n == 1)
        return 1;
    string num = to_string(n);
    int minVal = n;
    // cout << "num length is " << num.length() << endl;
    for(int i = 1; i < num.length(); i++)
    {
        string first = num.substr(0, i);
        string second = num.substr(i);
        if (second[0] != '0')
            minVal = min(minVal, forAll(stoi(first)) + forAll(stoi(second)));
    }
    for(int i = 1; i < n/2; i++)
    {
        minVal = min(minVal,forAll(n-i) + forAll(i));
    }

    for(int i = 2; i < int(sqrt(n)); i++)
           minVal = min(minVal,forAll(n/i) + forAll(i));
    used[n] = true;
    dp[n] = minVal;
    // cout << "minVal" << minVal << endl;
    return minVal;
}
int main(void)
{
    int n;
    cin >> n;
    int val = forAll(n);
    cout << val << endl;
    return 0;
}