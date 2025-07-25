#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        for(char c : s){
            hash[c]++;
        }
        for(char c : t){
            hash[c]--;
        }
        for(auto it : hash){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;  // Output: 1 (true)
    cout << sol.isAnagram("rat", "car") << endl;          // Output: 0 (false)
    return 0;
}