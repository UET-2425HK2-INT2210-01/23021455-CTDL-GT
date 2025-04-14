#include <iostream>
using namespace std;

int tinhtong(int n){
	if (n == 1)
	return 1;
	else 
	return n + tinhtong( n - 1);
}
int main(){
	int n = 5;
	cout <<"Tong tu 1 den" << n <<"la: " << tinhtong(n) << endl;
	return 0;
}
