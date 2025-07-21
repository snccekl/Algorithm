#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isNonDecreasing(vector<long long>& arr) {
            for (long long i = 1; i < arr.size(); ++i) {
                if (arr[i] < arr[i - 1]) {
                    return false;
                }
            }
            return true;
        }
    
        long long findMergePos(vector<long long>& arr) {
            long long minSum = LLONG_MAX;
            long long pos = -1;
            for (long long i = 0; i < arr.size() - 1; ++i) {
                long long sum = arr[i] + arr[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    pos = i;
                }
            }
            return pos;
        }
        long long minimumPairRemoval(vector<long long>& nums) {
            long long ops = 0;
            vector<long long> arr = nums;
            while (true) {
                if (isNonDecreasing(arr)) {
                    return ops;
                }
                long long pos = findMergePos(arr);
                vector<long long> newArr;
                newArr.reserve(arr.size() - 1);
                for (long long i = 0; i < pos; ++i) {
                    newArr.push_back(arr[i]);
                }
                newArr.push_back(arr[pos] + arr[pos + 1]);
                for (long long i = pos + 2; i < arr.size(); ++i) {
                    newArr.push_back(arr[i]);
                }
                arr = newArr;
                ops++;
            }
        }
    };