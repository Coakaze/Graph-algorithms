#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> gr[100005];
vector<int> ordering;
int viz[100005], n, m, k;

void dfs(int node)
{
    if(viz[node])
        return ;
    viz[node] = 1;
    for(auto v : gr[node])
        dfs(v);
    ordering.push_back(node);
}

int main()
{
    ifstream f("sortaret.in");
    ofstream g("sortaret.out");
    f>>n>>m;
    k = n - 1;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        f>>x>>y;
        gr[x].push_back(y);
    }
    for(int i = 1; i <= n; i++)
        if(!viz[i])
        {
            dfs(i);
        }
    for(int i = n - 1; i >= 0; i--)
        cout<<ordering[i]<<" ";
    return 0;
}
