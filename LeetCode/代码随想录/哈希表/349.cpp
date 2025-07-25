#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1;
        vector<int> ans;
        for(int a : nums1){
            n1.insert(a);
        }
        for(int b : nums2){
            if(n1.erase(b)){
                ans.push_back(b);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = sol.intersection(nums1, nums2);
    
    cout << "Intersection: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl; // Output: Intersection: 2 

    return 0;

}