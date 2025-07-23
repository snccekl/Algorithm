#include <bits/stdc++.h>
using namespace std;

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

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int target = 11;
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}