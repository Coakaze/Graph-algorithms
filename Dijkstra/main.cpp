#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pi;

vector<pi> graph[50005];
set<pi> s;
int d[50005];

int main()
{
    ifstream f("dijkstra.in");
    ofstream g("dijkstra.out");
    int n, m;
    f>>n>>m;
    int x, y, z;
    for(int i=0; i<m; i++)
    {
        f>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
    }
    for(int i=2; i<=n; i++)
        d[i] = INF;
    s.insert(make_pair(0,1));
    while(!s.empty())
    {
        int k = s.begin()->second;
        s.erase(s.begin());
        for(auto edge : graph[k])
        {
            int newDist = d[k] + edge.second;
            if(newDist < d[edge.first])
            {
                if(d[edge.first] != INF)
                    s.erase(s.find(make_pair(d[edge.first], edge.first)));
                d[edge.first] = newDist;
                s.insert(make_pair(newDist, edge.first));
            }
        }
    }
    for(int i=2; i<=n; i++)
        if(d[i] == INF)
            g<<0<<" ";
        else
            g<<d[i]<<" ";
    g<<"\n";
    return 0;
}
/*
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int NMAX = 50005;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> G[NMAX];

int dist[NMAX];

int main() {
    ifstream fin("dijkstra.in");
    ofstream fout("dijkstra.out");

    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        fin >> from >> to >> cost;
        G[from].push_back(make_pair(to, cost));
    }

    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    set<pair<int, int>> h;
    h.insert(make_pair(0, 1));
    while (!h.empty()) {
        int node = h.begin()->second;
        int d = h.begin()->first;
        h.erase(h.begin());

        for (vector<pair<int, int>>::iterator it = G[node].begin(); it != G[node].end(); ++it) {
            int to = it->first;
            int cost = it->second;
            if (dist[to] > dist[node] + cost) {
                if (dist[to] != INF) {
                    h.erase(h.find(make_pair(dist[to], to)));
                }
                dist[to] = dist[node] + cost;
                h.insert(make_pair(dist[to], to));
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (dist[i] == INF) {
            dist[i] = 0;
        }
        fout << dist[i] << ' ';
    }
    fout << '\n';

    fin.close();
    fout.close();
}*/
