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
    ListNode* reverse(ListNode*head){
        ListNode*curr,*next,*prev;
        curr = head;
        next = prev = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*slow,*fast;
        slow = fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode*first = head;
        ListNode*second = slow->next;
        slow->next = NULL;
        second = reverse(second);
        
        
        while(first && second){
            ListNode*next1,*next2;
            next1 = first->next;next2=second->next;
            
            first->next = second;
            second->next = next1;
            
            first = next1;
            second = next2;
        }
    }
};