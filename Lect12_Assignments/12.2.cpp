
#include <bits/stdc++.h>
using namespace std;

// C?u trúc c?nh
struct Edge {
    int u, v, w;
};

// Hàm so sánh c?nh theo tr?ng s? tang d?n
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

// Tìm d?i di?n c?a m?t d?nh (có nén du?ng di)
int findSet(int u, vector<int>& parent) {
    if (u != parent[u])
        parent[u] = findSet(parent[u], parent);
    return parent[u];
}

// H?p hai t?p h?p
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else {
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // S?p x?p c?nh theo tr?ng s?
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    vector<Edge> mst; // Luu các c?nh trong cây khung nh? nh?t
    int total_cost = 0;

    for (Edge e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            unionSets(e.u, e.v, parent, rank);
            mst.push_back(e);
            total_cost += e.w;
        }
    }

    cout << total_cost << endl;

    for (Edge e : mst) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }

    return 0;
}

