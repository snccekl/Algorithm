#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SumSquare(int n){
        int ans = 0;
        while(n != 0){
            int a = n % 10;
            n = n / 10;
            ans = ans + (a * a);
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int> s;
        while(1){
            int sum = SumSquare(n);
            if(sum == 1){
                return true;
            }
            if (s.find(sum) != s.end()) {
                return false;
            } else {
                s.insert(sum);
            }
            n = sum;
        }
        
    }
};

int main(){
    Solution sol;
    cout << sol.isHappy(19) << endl;  // Output: 1 (true)
    cout << sol.isHappy(2) << endl;   // Output: 0 (false)
    return 0;
}