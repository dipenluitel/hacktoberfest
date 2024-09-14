#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<ll> topo(int vertices, vector<ll> adj[])
{
    queue<ll> q;
    vector<ll> indegree(vertices, 0);
    for (int i = 0; i < vertices; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<ll> topo;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

void solve()
{
    ll vertices, edges;
    cin >> vertices >> edges;
    vector<ll> adj[vertices + 1];
    for (int i = 0; i < edges; i++)
    {
        ll node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }
    vector<ll> ans = topo(vertices, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
