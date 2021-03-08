//Design a data structure that follows the constraints of a Least Recently Used 
//(LRU) cache. 
//
// Implement the LRUCache class: 
//
// 
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity. 
//
// int get(int key) Return the value of the key if the key exists, otherwise ret
//urn -1. 
// void put(int key, int value) Update the value of the key if the key exists. O
//therwise, add the key-value pair to the cache. If the number of keys exceeds the
// capacity from this operation, evict the least recently used key. 
// 
//
// Follow up: 
//Could you do get and put in O(1) time complexity? 
//
// 
// Example 1: 
//
// 
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 3000 
// 0 <= value <= 104 
// At most 3 * 104 calls will be made to get and put. 
// 
// Related Topics Design 
// 👍 7847 👎 320


#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
private:
    int capacity = 0;
    struct data {
        int key;
        int value;
    };
    list<data> l;
    unordered_map<int, list<data>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void moveToFront(list<data>::iterator &it, int key, int value) {
        this->l.push_front(data{.key = key, .value = value});
        this->l.erase(it);
        this->mp[key] = this->l.begin();
    }
    
    int get(int key) {
        if(this->mp.find(key) != this->mp.end()) {
            auto it = this->mp[key];
            if(it == this->l.begin())
                return it->value;
            moveToFront(it, it->key, it->value);
            return this->l.front().value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(this->mp.find(key) != this->mp.end()){
            moveToFront(this->mp[key], key, value);
        } else {
            if(this->l.size() == this->capacity) {
                int k = this->l.back().key;
                this->l.pop_back();
                this->mp.erase(k);
            }
            this->l.push_front(data{.key = key, .value = value});
            this->mp[key] = this->l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
//    Solution solution;
    LRUCache *lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl;
    lru->put(3, 3);
    lru->put(4, 4);
    cout << lru->get(1) << endl;
    cout << lru->get(3) << endl;
    return 0;
}