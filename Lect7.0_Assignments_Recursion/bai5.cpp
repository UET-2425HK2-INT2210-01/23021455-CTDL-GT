 #include <iostream>
 using namespace std;
 int demsochuso(int n){
 	if (n < 10)
 	return 1;
 	return 1 + demsochuso(n / 10);
 }
 int main(){
 	int n = 12345;
 	cout << demsochuso(n) << endl;
 	return 0;
 }
