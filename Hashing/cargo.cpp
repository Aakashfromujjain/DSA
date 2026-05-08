#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Helper function to run BFS and return shortest distances from a start node
vector<int> bfs(int start, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n, INF);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Bidirectional route
    }
    
    int hub1, hub2, destinationHub;
    cin >> hub1 >> hub2 >> destinationHub;
    
    // Run BFS from the 3 critical nodes
    vector<int> dist1 = bfs(hub1, n, adj);
    vector<int> dist2 = bfs(hub2, n, adj);
    vector<int> distDest = bfs(destinationHub, n, adj);
    
    int min_hours = INF;
    
    // Check every hub to act as the potential consolidation hub
    for (int i = 0; i < n; ++i) {
        if (dist1[i] != INF && dist2[i] != INF && distDest[i] != INF) {
            min_hours = min(min_hours, dist1[i] + dist2[i] + distDest[i]);
        }
    }
    
    // Output result based on reachability
    if (min_hours == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_hours << "\n";
    }
    
    return 0;
}
