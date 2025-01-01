#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;


int distance(vector<vector<int> >& adj, int s, int t) {
    //write your code here
    vector<int> dis(adj.size());
    queue<int> q;
    int v;

    q.push(s);

    for (size_t i = 0; i < dis.size(); i++)
    {
        dis[i] = -1;
    }
    dis[s] = 0;

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (size_t i = 0; i < adj[v].size(); i++)
        {
            if (dis[adj[v][i]] == -1)
            {
                q.push(adj[v][i]);
                // cout << adj[v][i] << endl;
                dis[adj[v][i]] = dis[v] + 1;
            }
        }


    }

    return dis[t];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
