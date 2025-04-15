#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream inputFile("number.txt");
	ofstream outputFile("number.sorted");
	
	if (!inputFile){
		cerr <<"Khong mo duoc file numbers.txt" << endl;
		return 1;
	}
	vector<double> numbers;
	double num;
	while (inputFile >> num){
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	
	for (size_t i = 0; i < numbers.size(); ++i){
		outputFile << numbers[i];
		if (i != numbers.size() - 1) outputFile <<" ";
	} 
	inputFile.close();
	outputFile.close();
	return 0;
}
