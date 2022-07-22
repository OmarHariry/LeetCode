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
    ListNode* partition(ListNode* head, int x) {
        ListNode*smaller,*smallerHead,*greater,*greaterHead;
        
        smallerHead = new ListNode(-1);
        greaterHead = new ListNode(-1);
        
        smaller = smallerHead;
        greater = greaterHead;
        
        ListNode*curr = head;
        while(curr){
            if(curr->val < x){
                smaller->next = curr;
                smaller = smaller->next;
            }
            else{
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }
        
        greater->next = NULL;
        smaller->next = greaterHead->next;
        
        return smallerHead->next;
    }
};