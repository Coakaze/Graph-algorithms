#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

#define NMAX 100005

vector<int> graph[NMAX];
char viz[NMAX];
int n, m, answer;

void dfs(int node)
{
    if(viz[node])
        return ;
    viz[node] = 1;
    for(auto vecin : graph[node])
    {
        dfs(vecin);
    }
}

int main()
{
    int a, b;

    ifstream f("dfs.in");
    ofstream g("dfs.out");

    f>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        f>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!viz[i])
        {
            dfs(i);
            answer++;
        }
    }

    cout<<answer;

    return 0;
}
