# [209. 长度最小的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)
双指针维护子数组的左边界和右边界，一个变量记录和。

**注意：当和大于等于target时，需要循环减去左边界，因为当新加入的数特别大时，只减一次是不够的**

代码如下：
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0;
        int f = 0;
        int sum = nums[0];
        while(f < nums.size()){
            if(sum >= target){
                while(sum >= target){
                    ans = min(ans, f - s + 1);
                    sum -= nums[s];
                    s++;
                }
            }
            if(sum < target){
                f++;
                if(f < nums.size()) {
                    sum += nums[f];
                }
            }
        }
        return ans == INT_MAX?0:ans;
    }
};
```
# [58. 区间和（第九期模拟笔试）](https://kamacoder.com/problempage.php?pid=1070)
可以暴力，但是太慢了。

这里引入前缀和。前缀和可以简单理解为「数列的前n项的和」，是一种重要的预处理方式，能大大降低查询的时间复杂度。

在这道题目中，计算的是区间内的和(设区间为a、b)，则该区间内的和就是前b项的和减去前a项的和。

代码如下：
```cpp
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
```
# [44. 开发商购买土地（第五期模拟笔试）](https://kamacoder.com/problempage.php?pid=1044)
其实还是用前缀和的思想，但是这里最好是把整个二维数组观想成一维一维的数组（无论行列）。然后将每一维当作一个元素，去求整体的前缀和。

因为无论怎么分，都是以一行或者一列为单位的，那么这里面所有的元素都会划在同一个区域

代码如下：
```cpp
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
            sum += vec[i][j];//计算所有元素的和，因为只有两个区域
        }
    }
    int result = INT_MAX;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            count += vec[i][j];
            if (j == m - 1) result = min (result, abs(sum - count - count));
            //每经过一行，计算所有元素的和，然后计算result
        }
    }
  
    count = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0 ; i < n; i++) {
            count += vec[i][j];
            if (i == n - 1) result = min (result, abs(sum - count - count));
			//同样作用在列上
        }
    }
    cout << result << endl;
    return 0;
}
```
