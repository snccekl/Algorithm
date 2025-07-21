#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            if(nums[r] == val){
                r++;
            }
            else{
                nums[l] = nums[r];
                l++;
                r++;
            }
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int newLength = sol.removeElement(nums, val);
    
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for(int i = 0; i < newLength; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;

}