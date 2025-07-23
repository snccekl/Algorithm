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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            pre->next = temp;
            pre = cur;
            cur = cur->next;
        }
        return dummyhead->next;
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    ListNode* result = sol.swapPairs(head);

    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;

}