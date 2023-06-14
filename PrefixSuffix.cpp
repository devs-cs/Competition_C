#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) 
    {
        x = i; y = i+z[i]; z[i]++;
    }
    }
    return z;
}

int main()
{
    string s;
    cin >> s;
    vector<int> prefix = z(s);
    vector<int> matches;
    for(int i = size(s)-1; i>=0; i--)
        if(i + prefix[i] == size(s))
            matches.push_back(prefix[i]);
    matches.push_back(size(s));
    int count[10001] = {0};
    for(int i: prefix)
        count[i]++;

    for(int i = 1; i < 10; i++)
        cout << count[i] << " ";
    count[size(s)]++;
    cout <<"NEXT" << endl;
    for(int i = 10000; i >= 1; i--)
    {
        count[prefix[i-1]]+=count[i];
    }
       
    for(int i: matches)
    {
        cout << i << " " << count[i] << endl;
    }

}
