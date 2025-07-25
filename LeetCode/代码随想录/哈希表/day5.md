
---
title: 7-25 代码随想录之哈希表

date: 2025-07-25

categories: 算法刷题

---
# [242. 有效的字母异位词 - 力扣（LeetCode）](https://leetcode.cn/problems/valid-anagram/description/)
可以用哈希，也可以直接大小为26的数组。如果是unicode字符，那就必须用哈希了

代码如下：
```cpp
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
```
# [349. 两个数组的交集 - 力扣（LeetCode）](https://leetcode.cn/problems/intersection-of-two-arrays/description/)
维护一个set。前面插入，后面删除。如果删除成功（即之前加入了），就加入结果集
```cpp
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
```
# [202. 快乐数 - 力扣（LeetCode）](https://leetcode.cn/problems/happy-number/description/)
既然有可能无限循环，那就说明会遇到重复的数。

简单计算一下，即使是9999计算后也只是324,。因此一个set是够存放的
```cpp
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
```