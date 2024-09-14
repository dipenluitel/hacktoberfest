/*Problem Description:
You are given a graph with N nodes and M directed edges, where each edge has a non-negative weight. Implement Dijkstra's algorithm to find the shortest path from a given source node to all other nodes in the graph.

Input:
N (the number of nodes in the graph)
M (the number of directed edges in the graph)
M lines, each containing three integers u, v, and w, denoting a directed edge from node u to node v with weight w.
Source node s from which the shortest paths are to be calculated.

Output:
N integers representing the shortest distances from the source node s to all other nodes. If a node is not reachable from the source, output -1 for that node.*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Dijkstra's algorithm to find shortest path from source node to all nodes
void dijkstra(int source, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u]) {
            continue;
        }

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cout << "Enter the number of nodes and edges: ";
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1); // Graph represented as an adjacency list
    vector<int> dist(N + 1, INF); // Vector to store shortest distances, initialized to infinity

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight}); // Directed edge from u to v with given weight
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(source, graph, dist);

    cout << "Shortest distances from node " << source << " to all other nodes:" << endl;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": Not reachable" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
