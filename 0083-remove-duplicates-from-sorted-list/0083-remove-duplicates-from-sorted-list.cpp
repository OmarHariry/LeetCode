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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr, *prev;
        prev = NULL;
        curr = head;
        while(curr) {
            ListNode* next = curr->next;
            if (prev && prev->val == curr->val) {
                prev->next = next;
                curr = next;
            } else {
                prev = curr;
                curr = next;
            }
        }
        return head;
    }
};