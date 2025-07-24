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

int main(){
    Solution sol;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    ListNode *result = sol.detectCycle(head);
    if(result != NULL){
        cout << "Cycle detected at node with value: " << result->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    
    return 0;

}