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
        ListNode* curr1, *curr2, *it;
        curr1 = list1, curr2 = list2;
        
        ListNode* dummy = new ListNode(-1);
        it = dummy;
        while(curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                it->next = curr1;
                it = it->next;
                curr1 = curr1->next;
            } else {
                it->next = curr2;
                it = it->next;
                curr2 = curr2->next;
            }
        }
        while(curr1) {
            it->next = curr1;
            it = it->next;
            curr1 = curr1->next;
        }
        while(curr2) {
            it->next = curr2;
            it = it->next;
            curr2 = curr2->next;
        }
        it->next = nullptr;
        return dummy->next;
    }
};