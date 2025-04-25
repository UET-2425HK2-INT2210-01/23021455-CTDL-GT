#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các số từ 1 đến n
int tinhtong(int n) {
    if (n == 1)
        return 1;                 // Trường hợp cơ bản: tổng từ 1 đến 1 là 1
    else
        return n + tinhtong(n - 1); // Gọi lại chính nó với n - 1 và cộng thêm n
}

int main() {
    int n;
    cin >> n;
    // In ra tổng từ 1 đến n bằng cách gọi hàm tinhtong
    cout << "Tong tu 1 den " << n << " la: " << tinhtong(n) << endl;
    return 0;
}
