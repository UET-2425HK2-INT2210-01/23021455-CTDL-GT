#include <bits/stdc++.h>
using namespace std;

int n, m, X, Y;
vector<int> adj[1001]; // Danh sach ke
int dist[1001];        // dist[i] la so canh ngan nhat tu X den i
bool visited[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> X >> Y;
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y); // Do thi co huong
    }

    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist)); // -1 de danh dau chua duoc cap nhat

    bfs(X);

    if (visited[Y])
        cout << dist[Y] << endl;
    else
        cout << -1 << endl; //Neu khong co duong di tu X den Y
    return 0;
}

