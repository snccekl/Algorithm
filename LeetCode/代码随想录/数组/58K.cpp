#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,a,b;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> prefix(n + 1, 0);
    prefix[0] = nums[0];
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + nums[i];
    }
    while (~scanf("%d%d", &a, &b)){
        if (a > b) swap(a, b);
        if(a == 0) {
            printf("%d\n", prefix[b]);
            continue;
        }
        int ans = prefix[b] - prefix[a - 1];
        printf("%d\n", ans);
    }
    return 0;
}