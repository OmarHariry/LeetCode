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
        ListNode*first,*second,*it,*output;
        
        output = new ListNode(-1);
        it = output;
        first = list1,second = list2;
        
        while(first && second){
            if(first->val < second->val){
                it->next = first;
                it = it->next;
                first = first->next;
            }else{
                it->next = second;
                it = it->next;
                second = second->next;
            }
        }
        
        while(first){
            it->next = first;
            it = it->next;
            first = first->next;
        }
        
        while(second){
            it->next = second;
            it = it->next;
            second = second->next;
        }
        
        return output->next;
    }
};