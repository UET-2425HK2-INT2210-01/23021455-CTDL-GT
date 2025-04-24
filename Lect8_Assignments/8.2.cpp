#include <bits/stdc++.h>
using namespace std;

bool subsetSum(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int t = target; t >= num; --t) {
            dp[t] = dp[t] || dp[t - num];
        }
    }
    return dp[target];
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> ages(n);

    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    cout << (subsetSum(ages, X) ? "YES" : "NO") << endl;
    return 0;
}
