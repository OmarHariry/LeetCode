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
class comp {
public:
    bool operator()(ListNode* a, ListNode*b) {
        return a->val > b->val;
    }    
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* curr = list1;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }
        curr = list2;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(-1);
        curr = dummy;
        while(!pq.empty()) {
            curr->next= pq.top();
            pq.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy->next;
    }
};