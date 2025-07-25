
---
title: 7-24 代码随想录之链表

date: 2025-07-24

categories: 算法刷题

---
# [19. 删除链表的倒数第 N 个结点 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)
先让cur节点往后跑n-1个，然后一起后移cur和pre。

这样当cur是最后一个节点时，pre就指向的是倒数第n个节点的前一个节点了

代码如下：
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* pre = dummynode;
        ListNode* cur = head;
        while(n > 1){
            cur = cur->next;
            n--;

        }
        while(cur->next != nullptr){
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return dummynode->next;
    }
};
```
# [面试题 02.07. 链表相交 - 力扣（LeetCode）](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/)
设「第一个公共节点」为 node ，「链表 headA」的节点数量为 a ，「链表 headB」的节点数量为 b ，「两链表的公共尾部」的节点数量为 c ，则有：

头节点 headA 到 node 前，共有 a−c 个节点；
头节点 headB 到 node 前，共有 b−c 个节点；

那么让两个链表头先遍历完本身，再去从对方的头开始遍历，直到到达公共节点时指针 A , B 重合（如下所示）：
$a+(b−c)=b+(a−c)$

并有两种情况：
- 若两链表 有 公共尾部 (即 c>0 ) ：指针 A , B 同时指向「第一个公共节点」node 。
- 若两链表 无 公共尾部 (即 c=0 ) ：指针 A , B 同时指向 null 。
此时返回A、B均可
```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        while(A != B){
            A = A != NULL? A->next : headB;
            B = B != NULL? B->next : headA;
        }
        return A;
    }
};
```
# [142. 环形链表 II - 力扣（LeetCode）](https://leetcode.cn/problems/linked-list-cycle-ii/description/)
能想到用快慢指针，快指针走2n步，慢指针走n步，通过是否碰撞来检测环的存在。

但是第一次确实没想到要怎么判断环的入口在哪里

借一下灵神的图吧
![[LT142.png]]

> [!NOTE] 链接
> [142. 环形链表 II - 力扣（LeetCode）](https://leetcode.cn/problems/linked-list-cycle-ii/solutions/1999271/mei-xiang-ming-bai-yi-ge-shi-pin-jiang-t-nvsq/)

代码如下：
```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while (slow != head) {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```
