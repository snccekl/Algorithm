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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        while(cur != NULL){
            if(cur->val == val){
                pre->next = cur->next;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;
    ListNode* result = sol.removeElements(head, val);

    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;

}