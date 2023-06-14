#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> weights;
    vector<int> edges[1000];
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        weights.push_back(a);
    }
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[b].push_back(a);
    }
    vector<int> ends;
    for(int i = 0; i < n; i++)
    {
        if(edges[i].size() == 0)
            ends.push_back(i);
    }

    vector<int> vals;

    for(int i = 0; i < (int) ends.size(); i++)
    {
        for(int k = i+1; k < int(ends.size()); k++)
        {
            queue<int> q;
            int size = 0;
            q.push(ends[i]);
            q.push(ends[k]);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                size += weights[node];
                for(int j = 0; j < edges[node].size(); j++)
                    q.push(edges[node][j]);
            }
            vals.push_back(size);
        }
    }
    int minVal = vals[0];
    for(int i = 1; i < int(ends.size()); i++)
        minVal = min(minVal, ends[i]);
    cout << minVal << endl;
    return 0;
}