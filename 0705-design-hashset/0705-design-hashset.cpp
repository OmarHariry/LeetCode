
class MyHashSet {
private:
    ListNode* head; // Dummy head node for easier management

public:
    MyHashSet() {
        head = new ListNode(-1); // Create a dummy head
    }
    
    void add(int key) {
        if (contains(key)) return;
        ListNode *node = new ListNode(key);
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }
    
    void remove(int key) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val == key) {
                prev->next = curr->next; // Remove the node
                delete curr; // Free memory
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val == key)
                return true;
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */