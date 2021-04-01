#include<bits/stdc++.h>
using namespace std;
      struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
   };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr, * prev, * next;
        curr = head;
        prev = next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return false;
        ListNode* slow, * fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverseList(slow);
        while (temp && head) {
            if (head->val != temp->val)
                return false;
            temp = temp->next; head = head->next;
        }
        return true;
    }
    
};

int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(1);
    first->next = second;
    second->next = third;
    third->next = fourth;
    Solution obj;
    cout << obj.isPalindrome(first);


}