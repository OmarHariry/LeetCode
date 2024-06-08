class TrieNode {
public:
    TrieNode* children[26];
    bool isEndWord;
    TrieNode() {
        isEndWord = false;
        for(auto &child : children)
            child = nullptr;
    }
};
class WordDictionary {
TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();++i) {
            if(!curr->children[word[i] - 'a'])
                curr->children[word[i] -'a'] = new TrieNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->isEndWord = true;
    }
    bool searchInNodes(string word, TrieNode* node) {
        for(int i=0;i<word.size();++i) {
            if(word[i] == '.') {
                for(auto child : node->children) {
                    if (child != nullptr) 
                        if(searchInNodes(word.substr(i+1), child))
                           return true;
                } 
                return false;
            } else {
                if (!node->children[word[i] - 'a'])
                    return false;
            }
            node = node->children[word[i] - 'a'];
        }
       return node->isEndWord;
    }
    bool search(string word) {
        return searchInNodes(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */