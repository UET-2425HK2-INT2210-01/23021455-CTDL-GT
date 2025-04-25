#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Mở file đầu vào "number.txt" để đọc và file đầu ra "number.sorted" để ghi
    ifstream inputFile("number.txt");
    ofstream outputFile("number.sorted");

    // Kiểm tra nếu không mở được file đầu vào thì báo lỗi và thoát
    if (!inputFile) {
        cerr << "Khong mo duoc file number.txt" << endl;
        return 1;
    }

    vector<double> numbers; // Mảng để lưu các số thực từ file
    double num;

    // Đọc từng số từ file và thêm vào vector
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    // Sắp xếp các số theo thứ tự tăng dần
    sort(numbers.begin(), numbers.end());

    // Ghi các số đã sắp xếp ra file, cách nhau bằng dấu cách
    for (size_t i = 0; i < numbers.size(); ++i) {
        outputFile << numbers[i];
        if (i != numbers.size() - 1) outputFile << " ";
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
