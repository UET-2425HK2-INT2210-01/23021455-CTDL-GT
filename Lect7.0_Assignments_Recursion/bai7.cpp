#include <iostream>
using namespace std;
int daonguocso(int n, int daoso = 0){
	if(n == 0)
	return daoso;
	return daonguocso(n / 10, daoso * 10 + n % 10);
}
int main(){
	int n;
	cin >> n;
	cout <<daonguocso(n)<< endl;
	return 0;
}
