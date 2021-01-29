#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> gr[100005];
int s[100005];

void f_union(int u, int v)
{
    if(s[u] < s[v])
    {
        s[u] += s[v];
        s[v] = u;
    }
    else
    {
        s[v] += s[u];
        s[u] = v;
    }
}

int f_find(int u)
{
    int x = u;
    while(s[x] > 0)
    {
        x = s[x];
    }
    return x;
}

int main()
{
    ifstream f("disjoint.in");
    ofstream g("disjoint.out");
    int n, m;
    f>>n>>m;
    int op, x, y;
    for(int i=1; i<=n; i++)
        s[i] = -1;
    for(int i=0; i<m; i++)
    {
        f>>op>>x>>y;
        int a = f_find(x);
        int b = f_find(y);
        if(op == 1)
        {
            gr[x].push_back(y);
            gr[y].push_back(x);
            if(a != b)
                f_union(a, b);
        }
        else
        {
            if(a != b)
                g<<"NU"<<"\n";
            else
                g<<"DA"<<"\n";
        }
    }
    return 0;
}
