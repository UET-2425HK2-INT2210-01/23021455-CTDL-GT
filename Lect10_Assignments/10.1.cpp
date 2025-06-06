#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001]; // luu danh sach ke
bool visited[1001]; // Mang xem dinh da duoc tham hay chua

void dfs(int u){    // Thuat toan dfs
	visited[u] = true;
	for (int x : adj[u]){
		if (!visited[x] dfs(x));
	}
}
void connectedComponent(){   //Ham kiem tra do thi co bao nhieu thanh phan lien thong
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++){           // Duyet dinh
		if (!visited[i]){
			++ans;    // Tang so thanh phan lien thong
			dfs(i);   
		}
	}
	cout << ans << endl;  // So thanh phan lien thong cua do thi
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	connectedComponent();
	return 0;
}