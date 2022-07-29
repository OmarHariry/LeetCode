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
        ListNode*dummy = new ListNode(-1);
        ListNode*it = dummy;
        
        stack<int>myStack;
        while(head){
            myStack.push(head->val);
            head = head->next;
        }
        
        while(!myStack.empty()){
            int top = myStack.top();
            myStack.pop();
            ListNode*temp = new ListNode(top);
            it -> next = temp;
            it = it->next;
        }
        
        return dummy->next;
        
        
    }
};