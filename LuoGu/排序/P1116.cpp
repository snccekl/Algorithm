#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool flag = true;
    int sum = 0;
    while(flag) {
        flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sum++;
                flag = true;
            }
        }
        n--;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = bubbleSort(arr);
    cout << result << endl;

    return 0;

}