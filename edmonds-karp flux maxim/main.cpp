#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f

int c[1005][1005];
int f[1005][1005], t[1005];
vector<int> gr[1005];
int n, m, viz[1005];
int fmin, flow = 0;
queue<int> q;

int bfs()
{
    q.push(1);
    viz[1] = 1;
    memset(viz, 0, sizeof(viz));
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto v: gr[node])
        {
            if(c[node][v] != f[node][v] && !viz[v])
            {
                viz[v] = 1;
                if(v != n)
                {
                    q.push(v);
                    t[v] = node;
                }
            }
        }
    }
    if(!viz[n])
        return 0;
    for(int i = 0; i < gr[n].size(); i++)
    {
        int v = gr[n][i];
        t[n] = v;
        fmin = INF;
        int node;
        for(node = n; node != 1; node = t[node])
            fmin = min(fmin, c[t[node]][node] - f[t[node]][node]);
        for(node = n; node != 1; node = t[node])
        {
            f[t[node]][node] += fmin;
            f[node][t[node]] -= fmin;
        }
        flow += fmin;
    }
    return 1;
}

int main()
{
    ifstream fin("maxflow.in");
    ofstream fout("maxflow.out");
    int x, y, z;
    fin>>n>>m;
    for(int i=0; i<m; i++)
    {
        fin>>x>>y>>z;
        c[x][y] = z;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    while(bfs());
    fout<<flow;
    return 0;
}
