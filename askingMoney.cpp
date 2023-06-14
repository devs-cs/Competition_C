#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> adjList;
    vector<vector<int>> adjRev;
    //you can only lose money if you are the last person
    //so, is there a way B can  always lose money?

    //dfs reverse from b, see if you can hit everything
    //see if anything points to b
    cin >> n;
    for(int i = 0; i < 2n; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        adjList[a].push_back(b);
        adjRev[b].push_back(a); 
    }



/* we want to see if b can be put last in a search
so question can be formulated, if we remove b's edges what happens, issue
is we don't know where to start. Need to see if there's one edge that

Actually can we just reverse the edges and search

*/
    return 0;
}