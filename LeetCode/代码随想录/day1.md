# [704. 二分查找 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-search/description/)
这是二分查找的模版题。二分查找两种思路：左闭右开和左闭右闭。

在进行二分查找的循环中，循环的条件就是查找的区间要是合法的，即区间内至少有1个元素，例如，在左闭右闭的方法中，[1, 1]中至少有“1”这个元素，区间合法；而对于左闭右开，[1, 1)中没有元素，这个区间就是非法的。

在确认区间合法后，才在区间中取中间值

对于左闭右闭：由于每一次查找都需要在合法区间中寻找，且此次循环的合法区间不能包含上一次循环中已经筛除的值，所以在更新左右端点的值时，左端点的下标为中点下标+1，右端点的下标为中点下标-1。

对于左闭右开：与上面一样，但是此时区间的右端点不在区间内，所以在更新左右端点的值时，左端点的下标为中点下标+1，右端点的下标为中点下标。

注意
无论是左闭右闭还是左闭右开，在初始化时都必须要让数组中的所有元素都在初始合法区间内，例如数组nums为{1， 2， 3， 4}， 对于左闭右闭，那么初始的合法区间为[0, nums.size() - 1]，而对于左闭右开，初始的合法区间应该为[0, nums.size())

给出代码如下：
```cpp
//左闭右开
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return -1;
    }
};
//左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};
```
# [27. 移除元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-element/description/)
双指针，慢的指向最后一个非val的下一个元素，快的就一直遍历。每遇到一个非val的元素，就把它赋值给慢指针对应的位置

代码如下：
```cpp
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
```
# [977. 有序数组的平方 - 力扣（LeetCode）](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)
最开始想的是从数组左右两边遍历，然后将大的放在右边，小的放在左边。但是如果全是负数就会出错，因为不会有任何一个数的绝对值小于数组最右边那个数，则一旦最右边那个数至于最左边后就不会再交换了。

所以初始一个新的数组，然后从后往前填空，但是不改变原数组元素的顺序

代码如下：
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> result(nums.size());
        int pos = r;
        while(l <= r){
            if(abs(nums[r]) > abs(nums[l])){
                result[pos--] = nums[r] * nums[r];
                r--;
            }
            else{
                result[pos--] = nums[l] * nums[l];
                l++;
            }
        }
        return result;
    }
};
```