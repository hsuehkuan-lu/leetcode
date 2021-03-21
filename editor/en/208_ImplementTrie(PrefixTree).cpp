//Trie (we pronounce "try") or prefix tree is a tree data structure used to retr
//ieve a key in a strings dataset. There are various applications of this very eff
//icient data structure, such as autocomplete and spellchecker. 
//
// Implement the Trie class: 
//
// 
// Trie() initializes the trie object. 
// void insert(String word) inserts the string word to the trie. 
// boolean search(String word) returns true if the string word is in the trie (i
//.e., was inserted before), and false otherwise. 
// boolean startsWith(String prefix) returns true if there is a previously inser
//ted string word that has the prefix prefix, and false otherwise. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
//Output
//[null, null, true, false, true, null, true]
//
//Explanation
//Trie trie = new Trie();
//trie.insert("apple");
//trie.search("apple");   // return True
//trie.search("app");     // return False
//trie.startsWith("app"); // return True
//trie.insert("app");
//trie.search("app");     // return True
// 
//
// 
// Constraints: 
//
// 
// 1 <= word.length, prefix.length <= 2000 
// word and prefix consist of lowercase English letters. 
// At most 3 * 104 calls will be made to insert, search, and startsWith. 
// 
// Related Topics Design Trie 
// 👍 4323 👎 68


 <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
    struct TrieNode {
        vector<TrieNode*> children;
        bool is_word;
        TrieNode(): is_word(false), children(vector<TrieNode*>(26, nullptr)) {};
    };
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {};
//    Trie() {
//        root = new TrieNode();
//    }

    /** Inserts a word into the trie. */
    void insert(string word) {
//        vector<TrieNode*> *node = &root->children;
        auto node = root;
        for(auto &i: word) {
            int idx = i - 'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto *node = &root;
        for(auto &i: word) {
            int idx = i - 'a';
            if(!(*node)->children[idx]) return false;
            node = &(*node)->children[idx];
        }
        return (*node)->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto *node = &root;
        for(auto &i: prefix) {
            int idx = i - 'a';
            if(!(*node)->children[idx]) return false;
            node = &(*node)->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}