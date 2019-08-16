/*************************************************************************
       File: implement_trie.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-16 11:11:59

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.


************************************************************************/
#include "tools.h"

class Trie {
private:
    struct TrieNode {
        char val;
        map<char, TrieNode*> nodes;
        TrieNode(char ch): val(ch) {}
    } *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *parent = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode *node = parent->nodes[word[i]];
            
            if (NULL == node) {
                node = new TrieNode(word[i]);
                parent->nodes[word[i]] = node;
            }
            
            parent = node;
        }
        
        if (parent->nodes.find('\0') == parent->nodes.end()) {
            parent->nodes['\0'] = new TrieNode('\0');
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *parent = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode *node = parent->nodes[word[i]];
            
            if (NULL == node) {
                return false;
            }
            
            parent = node;
        }
        
        return parent->nodes.find('\0') != parent->nodes.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *parent = root;
        for (int i = 0; i < prefix.size(); i++) {
            TrieNode *node = parent->nodes[prefix[i]];
            
            if (NULL == node) {
                return false;
            }
            
            parent = node;
        }
        
        return true;
    }
    
    ~Trie() {
        for (auto iter = root->nodes.begin(); iter != root->nodes.end(); iter++) {
            delete iter->second;
        }
        
        delete root;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout<<trie.search("apple")<<endl;   // returns true
    cout<<trie.search("app")<<endl;     // returns false
    cout<<trie.startsWith("app")<<endl; // returns true
    trie.insert("app");   
    cout<<trie.search("app")<<endl;     // returns true
}
