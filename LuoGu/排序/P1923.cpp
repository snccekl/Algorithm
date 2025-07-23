#include <bits/stdc++.h>
using namespace std;

const int INF = 5000000;
vector<int> vec(INF, 0);
template <typename T>
int get_nth_k(vector<T>& arr, int left, int right,int pos) {
    if (left > right) return -1;
    if (left == right) return arr[left];
    T pivot = arr[(right-left) / 2 + left];
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
    if(pos < j - left) {
        return get_nth_k(arr, left, j-1, pos);
    } else if(pos > k - left) {
        return get_nth_k(arr, k+1, right, pos- (k - left + 1));
    } 
    return pivot;
}
int main(){
    int n,k;
    cin >> n >> k;
    srand(time(0));
    for(int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
    }
    printf("%d\n", get_nth_k(vec, 0,n-1, k));
    return 0;
}