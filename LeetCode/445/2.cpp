#include <bits/stdc++.h>
using namespace std;


// 给你一个整数数组 nums。在一次操作中，你可以选择一个子数组，并将其替换为一个等于该子数组 最大值 的单个元素。

// 返回经过零次或多次操作后，数组仍为 非递减 的情况下，数组 可能的最大长度。

// 子数组 是数组中一个连续、非空 的元素序列。
class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;
            vector<int> dp(n, 1);
            int maxLength = 1;
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[j] <= nums[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
            
            return maxLength;
        }
};


int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.maximumPossibleSize(nums) << endl;
    return 0;

}