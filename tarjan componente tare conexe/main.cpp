#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int n, m, id, sccCount;
int ids[100005], low[100005], onStack[100005], viz[100005];
stack<int> q;
vector<int> gr[200005];

void dfs(int node)
{
    q.push(node);
    onStack[node] = 1;
    ids[node] = low[node] = id++;
    for(auto vecin : gr[node])
    {
        if(ids[vecin] == -1)
            dfs(vecin);
        if(onStack[vecin])
            low[node] = min(low[node], low[vecin]);
    }
    if(ids[node] == low[node])
    {
        while(!q.empty())
        {
            int nodeD = q.top();
            onStack[nodeD] = 0;
            low[nodeD] = ids[node];
            q.pop();
            if(nodeD == node)
                break;
        }
        sccCount++;
    }
}

int main()
{
    ifstream f("ctc.in");
    ofstream g("ctc.out");
    f>>n>>m;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        f>>x>>y;
        gr[x].push_back(y);
    }
    for(int i = 1; i <= n; i++)
        ids[i] = -1;
    for(int i = 1; i <= n; i++)
        if(ids[i] == -1)
            dfs(i);
    g<<sccCount;
    g<<endl;
    for(int i = 1; i < n; i++)
    {
        int ok = 0;
        if(!viz[i])
        {
            g<<i<<" ";
            viz[i] = 1;
            for(int j = i + 1; j <= n; j++)
            {
                if(low[i] == low[j])
                {
                    g<<j<<" ";
                    viz[j] = 1;
                    ok = 1;
                }
            }
        }
        if(ok == 1)
            g<<"\n";
    }

    return 0;
}
