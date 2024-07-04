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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*curr, *start;
        curr = start = head->next;
        
        while(curr) {
            int sum = 0;
            while(curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }
            start->val = sum;
            curr = curr->next;
            start->next = curr;
            start = start->next;
        }
        
        return head->next;
    }
};