#include <bits/stdc++.h> 
using namespace std;

// Hàm tính ước chung lớn nhất (GCD) của hai số x và y bằng thuật toán Euclid
int gcd(int x, int y) {
    if (y == 0) // Nếu y = 0 thì ước chung lớn nhất là x
        return x;
    return gcd(y, x % y); // Đệ quy gọi lại với x = y và y = x % y
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl; 
    return 0;
}
