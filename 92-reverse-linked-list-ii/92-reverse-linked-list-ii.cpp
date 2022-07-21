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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*headOfList, *prev,*curr;
        
        prev = NULL;
        curr = head;
        while(left > 1){
            prev = curr;
            curr = curr->next;
            --left;
            --right;
        }
        
        headOfList = prev;
        ListNode*start = curr;
        
        while(curr && right--){
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        start->next = curr;
        
        if(headOfList)
            headOfList -> next = prev;
        else
            head = prev;
        
        return head;
    }
};