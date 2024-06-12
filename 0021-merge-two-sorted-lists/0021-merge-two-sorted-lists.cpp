/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy, *curr;
        dummy = new ListNode(-1);
        curr = dummy;
        
        ListNode* left, *right;
        left = list1, right = list2;
        
        while(left && right) {
            if(left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        while (left) {
            curr->next = left;
            curr = curr->next;
            left = left->next;
        }
        
        while (right) {
            curr->next = right;
            curr = curr->next;
            right = right->next;
        }
        return dummy->next;
    }
};