//
// Created by Lenovo on 2025/3/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0;i<n-2;i++){
         if(a[i] == a[i+1] && a[i+1] == a[i+2]){
             cout << "Yes" << endl;
             return 0;
         }
    }
    cout << "No" << endl;
    return 0;
}