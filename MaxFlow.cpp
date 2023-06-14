#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <algorithm>


using namespace std;
vector<vector<int>> adjList;
map<pair<int, int>, int> weight;
map<pair<int, int>, int> flow;

int maxFlow();
int path(int a, int b);


int main()
{
    
    int v,e;
    cin >> v;
    cin >> e;
    adjList.resize(v);
    for(int i = 0; i < e; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(weight[{a,b}] == 0) //is this right?
        {
            weight[{a,b}] = 1;
            weight[{b,a}] = 1;
            flow[{a,b}] = 0;
            flow[{b,a}] = 0;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        else
        {
            weight[{a,b}]++;
            weight[{b,a}]++;
        }   
    }
    int resp = maxFlow();
    cout << resp << endl;
    return 0;
}

int maxFlow()
{
    int n = adjList.size();
    int maxFlow = 0;
    while(true)
    {
        int flow = path(0, n-1);
        if(flow == 0)
            break;
        maxFlow += flow;
    }
    return maxFlow;
}

int path(int s, int t)
{
    deque<int> queue;
    vector<int> prior(adjList.size(),-1);
    queue.push_back(s);
    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();
        for(int i = 0; i < adjList[node].size(); i++)
        {
            int next = adjList[node][i];
            if(prior[next] == -1 && 
                flow[{node, next}] < weight[{node, next}]) //direction of flow matters
            {
                prior[next] = node;
                queue.push_back(next);
                if(next == t)
                    break;
            }
        }
    }
    // for(int i = 0; i < )
    if(prior[t] == -1)
            return 0;
    
    // cout << "traverse" << endl;
    int curFlow = INT_MAX;
    int trav = t;
    while(trav != s)
    {
        int prev = prior[trav];
        curFlow = min(curFlow, weight[{prev,trav}] - flow[{prev,trav}]);
        trav = prev;
    }
    // cout << curFlow << endl;
    trav = t;
    while(trav != s)
    {
        // cout << s << endl;
        int prev = prior[trav];
        flow[{prev,trav}] += curFlow;
        int minimum = min(flow[{prev,trav}], flow[{trav, prev}]);
        flow[{prev,trav}] -= minimum;
        flow[{trav, prev}] -= minimum;
        trav = prev;
    }
    return curFlow;
}
