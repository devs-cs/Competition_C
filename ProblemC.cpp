#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
bool matrixCount[200000][26];

void constructSeg()
{
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < 26; j++)
            matrixCount[i][j] = matrixCount[2*i][j] || matrixCount[2*i+1][j];   
    }
}

void addToTree(int pos, char val)
{
    pos +=n;
    for(int i = 0; i < 26; i++)
        matrixCount[pos][i] = false;
    matrixCount[pos][val - 'a'] = true;
    while(pos > 0)
    {
     pos/=2;
     for(int j = 0; j < 26; j++)
            matrixCount[pos][j] = matrixCount[2*pos][j] || matrixCount[2*pos+1][j];   
    }
}

int rangeComp(int a, int b)
{
    bool arr[26] = {};// this  guy will disappear
    a+=n; 
    b+=n;
    while(a <= b)
    {
        if(a%2==1){
            for(int i = 0; i < 26; i++)
                arr[i] = arr[i] || matrixCount[a][i];
            a++;
        }
        if(b%2 == 0){
            for(int i = 0; i < 26; i++)
                arr[i] = arr[i] || matrixCount[b][i];
            b--;  
        } 
        a/=2; b/=2;
    }
    int count = 0;
    for(int i = 0; i < 26; i++)
        count+=arr[i];
    return count;   
}


int main()
{
    string s;
    cin >> s;
    n = s.size();
    for(int i =0; i < n; i++)
    { 
        matrixCount[i+n][s[i]-'a'] = true;
    }
    constructSeg();
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int quer;
        cin >> quer;
        int pos, end;
        char val;
        cin  >> pos;
        if(quer == 2){
            cin >> end;
            cout << rangeComp(pos-1,end-1)  <<endl;
        }
        else if (quer == 1){
            cin >> val;
            addToTree(pos-1, val);
        }
    }
    return 0;
}