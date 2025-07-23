#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+7;
vector<int> vec(INF, 0);
template <typename T>
void quickSort(vector<T>& arr, int left, int right) {
    if (left >= right) return;
    T pivot = arr[rand() % (right - left + 1) + left];
    int i = left, j = left, k = right;
    while (i <= k) {
        if (arr[i] < pivot) {
            swap(arr[i++], arr[j++]);
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[k--]);
        } else {
            i++;
        }
    }
    quickSort(arr, left, j - 1);
    quickSort(arr, k + 1, right);
}


int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin>> vec[i];
    }
    quickSort(vec, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
