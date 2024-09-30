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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;
        while(curr) {
            s.push(curr);
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(-1);
        curr = dummy;
        while(!s.empty()) {
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy->next;
        
    }
};