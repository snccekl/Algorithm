#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> vec(n, vector<int>(m, 0)) ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }
    int result = INT_MAX;
    int count = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            count += vec[i][j];
            if (j == m - 1) result = min (result, abs(sum - count - count));

        }
    }

    count = 0; 
    for (int j = 0; j < m; j++) {
        for (int i = 0 ; i < n; i++) {
            count += vec[i][j];
            if (i == n - 1) result = min (result, abs(sum - count - count));
        }
    }
    cout << result << endl;
    return 0;
}