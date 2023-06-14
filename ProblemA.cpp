#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int segmentTree[200000];

void constructSeg()
{
    for(int i = n-1; i >= 0; i--)
    {
        segmentTree[i] = segmentTree[2*i] ^ segmentTree[2*i+1];
    }
}

void addToTree(int pos, int val)
{
    pos +=n;
    segmentTree[pos] = val;
    while(pos > 0)
    {
     pos/=2;
     segmentTree[pos] = segmentTree[2*pos] ^ segmentTree[2*pos+1];   
    }
}

int rangeComp(int a, int b)
{
    int result = 0;
    a+=n; 
    b+=n;
    while(a <= b)
    {
        if(a%2==1) result ^= segmentTree[a++];
        if(b%2 == 0) result^= segmentTree[b--];
        a/=2; b/=2;
    }
    return result;   
}


int main()
{
    int q;
    cin >> n;
    cin >> q;
    for(int i =0; i < n; i++)
    {
        cin >> segmentTree[i+n];
    }
    constructSeg();
    for(int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        int a,b;
        cin  >> a;
        cin >> b;
        if(s == "XOR")
            cout << rangeComp(a-1,b-1)  <<endl;
        else if (s == "NEW")
            addToTree(a-1, b);
    }
    return 0;
}