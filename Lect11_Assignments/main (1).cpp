#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, s, e;

vector<tuple<int, int, int>> edges;

pair<int, vector<int>> bellmanFord(int s, int e) {
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    vector<int> path;
    if (dist[e] == INF) return {INF, path};

    for (int cur = e; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    return {dist[e], path};
}

vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (auto [u, v, w] : edges) {
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
}

int main() {
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    auto [dirty_level, path] = bellmanFord(s, e);
    if (dirty_level == INF) {
        cout << "INF\n";
    } else {
        cout << dirty_level << "\n";
        for (int city : path) cout << city << " ";
        cout << "\n";
    }

    auto matrix = floydWarshall();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
