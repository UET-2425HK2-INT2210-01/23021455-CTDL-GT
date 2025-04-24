#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<double>& arr, int left, int right) {
    int i = left, j = right;
    double pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    int n;
    cin >> n;
    vector<double> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    quickSort(numbers, 0, n - 1);

    // Output sorted numbers
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << fixed << setprecision(6) << numbers[i] << (i < n - 1 ? " " : "\n");
    }
    return 0;
}
