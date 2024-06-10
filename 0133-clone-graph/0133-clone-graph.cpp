/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp){ 
        Node *clone = new Node(node->val);
        mp[node] = clone;
        vector<Node*> neighbors;
        for(auto neighbor : node->neighbors) {
            if (mp.find(neighbor) != mp.end()) 
                neighbors.push_back(mp[neighbor]);
            else
                neighbors.push_back(dfs(neighbor, mp));
        }
        clone->neighbors = neighbors;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        if (node->neighbors.size() == 0) {
            Node*clone = new Node(node->val);
            return clone;
        }
        
        unordered_map<Node*, Node*>mp;
        return dfs(node, mp);
    }
};