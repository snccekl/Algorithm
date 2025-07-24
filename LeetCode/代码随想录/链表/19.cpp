#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int n = 2; // Remove the 2nd node from the end
    ListNode* result = sol.removeNthFromEnd(head, n);

    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;

}