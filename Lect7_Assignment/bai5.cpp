#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 1; i <= n; ++i){
		nums.push_back(i);
	}
	sort(nums.begin(), nums.end());
	
	do{
		for (int i = 0; i < n; ++i){
			cout << nums[i];
		}
		cout << endl;
	}while (next_permutation(nums.begin(), nums.end()));
	return 0;
}
