#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int total = 1 << n;
	for (int i = 0; i < total; i++){
		bitset<32> bin(i);
		string s = bin.to_string().substr(32 - n);
		cout << s << endl;
	}
	return 0;
}

