#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // Đại diện cho vô cùng
int n, m, s, e;       // Số đỉnh, số cạnh, điểm bắt đầu, điểm kết thúc

vector<tuple<int, int, int>> edges; // Danh sách cạnh dạng (u, v, d)

// Hàm tìm đường đi ngắn nhất từ s đến e dùng Bellman-Ford
pair<int, vector<int>> bellmanFord(int s, int e) {
    vector<int> dist(n + 1, INF);    // Khoảng cách từ s tới các đỉnh
    vector<int> parent(n + 1, -1);   // Mảng lưu đường đi
    dist[s] = 0;

    // Lặp n-1 lần để cập nhật khoảng cách
    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Truy vết đường đi từ e về s
    vector<int> path;
    if (dist[e] == INF) return { INF, path }; // Không có đường đi

    for (int cur = e; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    return { dist[e], path };
}

// Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Khởi tạo đường chéo bằng 0
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    // Gán trọng số các cạnh
    for (auto [u, v, w] : edges) {
        dist[u][v] = min(dist[u][v], w); // Nếu có nhiều cạnh giữa u-v, lấy nhỏ nhất
    }

    // Cập nhật khoảng cách
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Không thể mở file\n";
        return 1;
    }

    fin >> n >> m >> s >> e;

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({ u, v, d });
    }

    // a) Bellman-Ford từ s đến e
    auto [dirty_level, path] = bellmanFord(s, e);
    if (dirty_level == INF) {
        fout << "INF\n";  // Không có đường đi
    }
    else {
        fout << dirty_level << "\n";
        for (int city : path) fout << city << " ";
        fout << "\n";
    }

    // b) Floyd-Warshall cho mọi cặp đỉnh
    auto matrix = floydWarshall();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[i][j] == INF)
                fout << "INF ";
            else
                fout << matrix[i][j] << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
