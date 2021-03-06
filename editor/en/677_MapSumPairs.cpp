//Implement the MapSum class: 
//
// 
// MapSum() Initializes the MapSum object. 
// void insert(String key, int val) Inserts the key-val pair into the map. If th
//e key already existed, the original key-value pair will be overridden to the new
// one. 
// int sum(string prefix) Returns the sum of all the pairs' value whose key star
//ts with the prefix. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["MapSum", "insert", "sum", "insert", "sum"]
//[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
//Output
//[null, null, 3, null, 5]
//
//Explanation
//MapSum mapSum = new MapSum();
//mapSum.insert("apple", 3);  
//mapSum.sum("ap");           // return 3 (apple = 3)
//mapSum.insert("app", 2);    
//mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
// 
//
// 
// Constraints: 
//
// 
// 1 <= key.length, prefix.length <= 50 
// key and prefix consist of only lowercase English letters. 
// 1 <= val <= 1000 
// At most 50 calls will be made to insert and sum. 
// 
// Related Topics Hash Table String Design Trie 
// 👍 926 👎 107


#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class MapSum {
    struct Trie{
        int val;
        unordered_map<char, Trie*> mp;
        Trie(): val(0){}
    };
    Trie *graph;
    unordered_map<string, int> prev;
public:
    /** Initialize your data structure here. */
    MapSum() {
        graph = new Trie();
    }

    void insert(string key, int val) {
        if(prev.count(key)) {
            int prev_val = prev[key];
            auto trie = graph;
            for(auto ch: key) {
                trie = trie->mp[ch];
                trie->val -= prev_val;
            }
        }
        prev[key] = val;
        auto trie = graph;
        for(auto ch: key) {
            if(!trie->mp.count(ch)) {
                trie->mp[ch] = new Trie();
            }
            trie = trie->mp[ch];
            trie->val += val;
        }
    }

    int sum(string prefix) {
        auto trie = graph;
        int val = 0;
        for(auto ch: prefix) {
            if(!trie->mp.count(ch)) return 0;
            trie = trie->mp[ch];
            val = trie->val;
        }
        return val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}