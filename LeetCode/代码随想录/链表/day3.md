
---
title: 7-23 代码随想录之链表

date: 2025-07-23

categories: 算法刷题

---
# [203. 移除链表元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-linked-list-elements/description/)
链表的题我个人还是喜欢有一个虚拟的头节点更好。这样便于操作和处理边界情况

在这个题里，维护一个当前节点和当前节点的前一个节点，当前节点值为val时，只需要把前一个节点的next指向当前节点的next即可。

**最后返回虚拟头节点的next是因为当链表内全为对应val时，原head节点将被删除**

代码如下：
```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* dumhead = pre;
        ListNode* cur = head;
        while(cur != NULL){
            if(cur->val == val){
                ListNode* tmp = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete tmp;
                continue;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return dumhead->next;
    }
};
```
# [206. 反转链表 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-linked-list/description/)
循环的做法比较简单，不赘述

对于递归，考虑设计一个函数，每次翻转两个节点间的指向关系即可。最后的那个节点就是头节点

代码如下：
```cpp
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == nullptr){
            return pre;
        }
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
```
# [24. 两两交换链表中的节点 - 力扣（LeetCode）](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)
依然设置一个虚拟头节点，current指针的下一个节点是需要临时保存的；因为是两两交换  

还有循环停止的条件是current节点和下个节点不能为空

代码如下：
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL){
            ListNode* temp = cur->next; 
            cur->next = temp->next
            temp->next = cur;
            pre->next = temp;
            pre = cur;
            cur = cur->next;

        }
        return dummyhead->next;
    }
};
```
