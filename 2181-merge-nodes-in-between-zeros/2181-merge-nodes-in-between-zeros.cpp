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
        ListNode*dummy, *it, *curr;
        dummy = it = new ListNode(-1);
        curr = head;
        int sum = 0;
        while(curr->next) {
            sum += curr->val;
            if (curr->next->val == 0) {
                it->next = new ListNode(sum);
                it = it->next;
                sum = 0;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};