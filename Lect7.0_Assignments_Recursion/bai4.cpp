#include <iostream>
using namespace std;

int luythua(int x, int n){
	if (n == 0)
	return 1;
	else 
	return x * luythua(x, n - 1);
}
int main(){
	int x = 2, n = 3;
	cout <<luythua(x, n)<<endl;
	return 0;
}
