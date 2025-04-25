#include <bits/stdc++.h>
using namespace std;

// Hàm Kadane 1 chiều để tìm đoạn con liên tiếp có tổng lớn nhất trong mảng
int kadane(const vector<int>& arr, int& start, int& end) {
    int maxsum = INT_MIN, sum = 0;
    int localstart = 0;
    start = end = -1;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Nếu tổng hiện tại nhỏ hơn chính phần tử đang xét, bắt đầu lại từ phần tử này
        if (sum < arr[i]) {
            sum = arr[i];
            localstart = i;
        }

        // Cập nhật tổng lớn nhất nếu cần
        if (sum > maxsum) {
            maxsum = sum;
            start = localstart;
            end = i;
        }
    }
    return maxsum;
}

int main() {
    ifstream fin("matrix.txt");   // Mở file đầu vào
    ofstream fout("matrix.out");  // Mở file đầu ra

    int m, n;
    fin >> m >> n; // Đọc kích thước ma trận m dòng, n cột

    vector<vector<int>> matrix(m, vector<int>(n));
    // Đọc ma trận từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> matrix[i][j];

    int maxsum = INT_MIN;
    int finalleft = 0, finalright = 0, finaltop = 0, finalbottom = 0;

    // Duyệt từng cặp cột trái - phải
    for (int left = 0; left < n; ++left) {
        vector<int> tmp(m, 0); // Mảng tạm để gom tổng theo từng dòng giữa hai cột

        for (int right = left; right < n; ++right) {
            // Cộng dồn giá trị từng hàng giữa 2 cột
            for (int i = 0; i < m; ++i)
                tmp[i] += matrix[i][right];

            // Áp dụng Kadane 1D trên cột dồn thành hàng
            int startrow, endrow;
            int sum = kadane(tmp, startrow, endrow);

            // Nếu tìm được tổng lớn hơn, lưu lại tọa độ
            if (sum > maxsum) {
                maxsum = sum;
                finalleft = left;
                finalright = right;
                finaltop = startrow;
                finalbottom = endrow;
            }
        }
    }

    // Ghi kết quả ra file (chuyển về chỉ số bắt đầu từ 1 cho dễ đọc)
    fout << finaltop + 1 << " " << finalleft + 1 << " "
         << finalbottom + 1 << " " << finalright + 1 << " "
         << maxsum << endl;

    // Đóng file
    fin.close();
    fout.close();
    return 0;
}
