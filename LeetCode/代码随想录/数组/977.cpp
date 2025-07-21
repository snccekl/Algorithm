#include <bits/stdc++.h>
using namespace std;    

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int l = 0;
//         int r = nums.size() - 1;
//         vector<int> result(nums.size());
//         int pos = r;
//         while(l <= r){
//             if(abs(nums[r]) > abs(nums[l])){
//                 result[pos--] = nums[r] * nums[r];
//                 r--;
//             }
//             else{
//                 result[pos--] = nums[l] * nums[l];
//                 l++;
//             }
//         }
//         return result;
//     } 
// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            if(abs(nums[r]) > abs(nums[l])){
                nums[r] = nums[r] * nums[r];
                r--;
            }
            else{
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp * temp;
                r--;
            }
        }
        return nums;
    } 
};
int main() {
    Solution sol;
    vector<int> nums = {-5,-3,-2,-1};
    vector<int> result = sol.sortedSquares(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}