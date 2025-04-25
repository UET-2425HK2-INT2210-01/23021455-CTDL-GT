#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> nums; // Vector để chứa các phần tử từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i); // Thêm các số từ 1 đến n vào vector
    }

    sort(nums.begin(), nums.end()); // Sắp xếp vector nums để chuẩn bị cho việc sinh hoán vị

    // Sinh và in tất cả các hoán vị của dãy số
    do {
        for (int i = 0; i < n; ++i) {
            cout << nums[i]; // In ra hoán vị hiện tại
        }
        cout << endl; 
    } while (next_permutation(nums.begin(), nums.end())); // Tiến tới hoán vị tiếp theo

    return 0; 
}
