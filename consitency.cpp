#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int i = 0;
    char c;
    int curLen = 0;
    int maxLen = 0;
    while(cin.get(c) && i <= n)
    {
        // c = getchar();
        // cout << (int)c << endl;
        if(c == '1')
            curLen++;
        else
        {
            if(curLen > maxLen)
                maxLen = curLen;
            curLen = 0;
        }
        i++;
    }
    if (curLen > maxLen)
        maxLen = curLen;
    cout << maxLen << endl;
    return 0;
}