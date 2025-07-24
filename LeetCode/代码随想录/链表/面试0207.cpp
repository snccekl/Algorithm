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

int main(){
    Solution sol;
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next; // Intersection at node
    ListNode *result = sol.getIntersectionNode(headA, headB);
    if(result != NULL){
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }
    return 0;

}