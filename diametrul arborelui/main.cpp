#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> gr[200005];
int viz[200005], d[200005];
int n, d_max, maxim;

void dfs(int node)
{
    if(viz[node])
        return ;
    viz[node] = 1;
    for(auto v : gr[node])
    {
        if(!viz[v])
        {
            d[v] = 1 + d[node];
            if(d[v] > d[d_max])
            {
                d_max = v;
                maxim = d[d_max] + 1;
            }
            dfs(v);
        }
    }
}

void reset()
{
    for(int i = 1; i <= n; i++)
    {
        viz[i] = 0;
        d[i] = 0;
    }
}

int main()
{
    ifstream f("darb.in");
    ofstream g("darb.out");
    f>>n;
    int x, y;
    for(int i = 0; i < n - 1; i++)
    {
        f>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);
    reset();
    dfs(d_max);
    g<<maxim;

    return 0;
}
