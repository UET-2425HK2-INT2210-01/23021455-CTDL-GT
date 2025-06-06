#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Tạo danh sách kề để lưu đồ thị (dạng hướng)
    vector<vector<int>> graph(n + 1);

    // Mảng lưu bậc vào (số công việc cần làm trước công việc i)
    vector<int> in_degree(n + 1, 0);

    // Nhập m ràng buộc công việc: công việc u phải làm trước v
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // u -> v
        in_degree[v]++;        // tăng bậc vào của v
    }

    // Hàng đợi chứa các công việc chưa có công việc nào phải làm trước
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i); // Có thể làm ngay
        }
    }

    // Vector lưu kết quả thứ tự thực hiện công việc
    vector<int> result;

    // Thuật toán sắp xếp tô-pô (Kahn's algorithm)
    while (!q.empty()) {
        int u = q.front(); // Lấy công việc đầu hàng đợi
        q.pop();
        result.push_back(u); // Thêm vào kết quả

        // Duyệt tất cả các công việc phụ thuộc vào u
        for (int v : graph[u]) {
            in_degree[v]--; // Giảm bậc vào
            if (in_degree[v] == 0) {
                q.push(v); // Nếu không còn phụ thuộc thì thêm vào hàng đợi
            }
        }
    }

  
    for (int job : result) {
        cout << job << " ";
    }

    return 0;
}
