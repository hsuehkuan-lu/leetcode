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
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void moveToFront(list<pair<int, int>>::iterator &it, int key, int value) {
        l.push_front({key, value});
        l.erase(it);
        mp[key] = l.begin();
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            auto it = mp[key];
            if(it == l.begin())
                return it->second;
            moveToFront(it, it->first, it->second);
            return l.front().second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            moveToFront(mp[key], key, value);
        } else {
            l.push_front({key, value});
            mp[key] = l.begin();
            if(l.size() > capacity) {
                mp.erase(l.back().first);
                l.pop_back();
            }
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