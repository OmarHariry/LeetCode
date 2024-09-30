/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1, *curr2;
        curr1 = headA, curr2 = headB;
        int n1,n2;
        n1 = 0, n2 = 0;
        while(curr1) {
            ++n1;
            curr1 = curr1->next;
        }
        while(curr2) {
            ++n2;
            curr2 = curr2->next;
        }
        curr1 = headA, curr2 = headB;
        while(n1 > n2) {
            curr1 = curr1->next;
            --n1;
        }
        while(n2 > n1) {
            curr2 = curr2->next;
            --n2;
        }
        while(curr1 && curr2) {
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
        
    }
};