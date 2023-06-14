#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    long cp = 0, cm = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]=='+')
            cp++;
        else cm++;
    }
    // cout << cp << endl;
    // cout << cm << endl;
    for(int c = 0; c < q; c++)
    {
        long long int v1, v2;
        cin >> v1;
        cin >> v2;
        if(v2 == v1 && cp == cm)
            cout << "YES" << endl;
        else if (v2 == v1)
            cout << "NO" << endl;
        else
        {
            // cout << (v1 - v2) << endl;
            // cout << v2 * (cp - cm) << endl;
            // cout << (v2 * (cp - cm)) / (v1 - v2) << endl;
            // cout << (int)((v2 * (cp - cm)) / (v1 - v2) >= -1*cm) << endl;
            // cout << (int)(cp >=(v2 * (cp - cm)) / (v1 - v2)) << endl;
            if((v2 * (cp - cm)) % (v1 - v2) == 0 && cm >= (v2 * (cp - cm)) / (v1 - v2) && (v2 * (cp - cm)) / (v1 - v2) >= -1*cp)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}