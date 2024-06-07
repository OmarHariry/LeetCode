class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndWord;
    TrieNode() : children(26, nullptr) {
        isEndWord = false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode*curr = root;
        for(char c : word) {
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->isEndWord = true;
    }
    string startsWith(string word) {
        TrieNode*curr = root;
        for(int i=0;i<word.size();++i) {
            if(!curr->children[word[i] - 'a'])
                return word;
            curr = curr->children[word[i] - 'a'];
            if(curr->isEndWord)
                return word.substr(0, i+1);
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word : dictionary)
            trie.insert(word);
        string word, newSentence;
        stringstream ss(sentence);
        while(ss >> word) {
            newSentence += trie.startsWith(word) + " ";
        }
        newSentence.pop_back();
        return newSentence;
    }
};