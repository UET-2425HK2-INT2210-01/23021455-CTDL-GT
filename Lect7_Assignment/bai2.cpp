#include <bits/stdc++.h>
using namespace std;

int kadane(const vector<int>& arr, int& start, int& end){
    int maxsum = INT_MIN, sum = 0;
    int localstart = 0;
    start = end = -1;

    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if (sum < arr[i]){
            sum = arr[i];
            localstart = i;
        }
        if (sum > maxsum){
            maxsum = sum;
            start = localstart;
            end = i;
        }
    }
    return maxsum;
}

int main(){
    ifstream fin("matrix.txt");
    ofstream fout("matrix.out");

    int m, n;
    fin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> matrix[i][j];

    int maxsum = INT_MIN;
    int finalleft = 0, finalright = 0, finaltop = 0, finalbottom = 0;

    for (int left = 0; left < n; ++left){
        vector<int> tmp(m, 0);
        for (int right = left; right < n; ++right){
            for (int i = 0; i < m; ++i)
                tmp[i] += matrix[i][right];

            int startrow, endrow;
            int sum = kadane(tmp, startrow, endrow);

            if (sum > maxsum){
                maxsum = sum;
                finalleft = left;
                finalright = right;
                finaltop = startrow;
                finalbottom = endrow;
            }
        }
    }

    fout << finaltop + 1 << " " << finalleft + 1 << " "
         << finalbottom + 1 << " " << finalright + 1 << " "
         << maxsum << endl;

    fin.close();
    fout.close();
    return 0;
}

