#include <bits/stdc++.h>
using namespace std;

vector<int> arr(1001);
int n;
vector<int> vec(10000);
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for(int i = 0; i < n-1; i++) {
        if(abs(vec[i] - vec[i+1]) < 1000)
            arr[abs(vec[i] - vec[i+1])] = 1;
        else
            arr[1000] = 1; // Handle case where difference exceeds 999
    }
    for(int i = 1; i < n; i++) {
        if(arr[i] != 1) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}