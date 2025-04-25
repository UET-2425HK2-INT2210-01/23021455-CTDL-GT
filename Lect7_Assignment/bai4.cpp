#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n; 

    int total = 1 << n; // Tính tổng số dãy nhị phân có n bit, bằng 2^n

    // Duyệt qua tất cả các số từ 0 đến 2^n - 1
    for (int i = 0; i < total; i++) {
        bitset<32> bin(i); // Biến i thành số nhị phân 32 bit
        string s = bin.to_string().substr(32 - n); // Lấy n bit cuối cùng (sử dụng substring để cắt bớt phần thừa)
        cout << s << endl; 
    }

    return 0; 
}
