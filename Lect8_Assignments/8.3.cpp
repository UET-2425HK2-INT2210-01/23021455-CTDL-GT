#include <iostream>
#include <vector>

using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = values.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = capacity; w >= weights[i]; --w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    int max_value = knapsack(weights, values, X);
    cout << max_value << endl;
    return 0;
}
