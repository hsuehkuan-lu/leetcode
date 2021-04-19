//Create a timebased key-value store class TimeMap, that supports two operations
//. 
//
// 1. set(string key, string value, int timestamp) 
//
// 
// Stores the key and value, along with the given timestamp. 
// 
//
// 2. get(string key, int timestamp) 
//
// 
// Returns a value such that set(key, value, timestamp_prev) was called previous
//ly, with timestamp_prev <= timestamp. 
// If there are multiple such values, it returns the one with the largest timest
//amp_prev. 
// If there are no values, it returns the empty string (""). 
// 
//
// 
//
// 
// Example 1: 
//
// 
//Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],
//["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
//Output: [null,null,"bar","bar",null,"bar2","bar2"]
//Explanation:   
//TimeMap kv;   
//kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with tim
//estamp = 1   
//kv.get("foo", 1);  // output "bar"   
//kv.get("foo", 3); // output "bar" since there is no value corresponding to foo
// at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar" 
//  
//kv.set("foo", "bar2", 4);   
//kv.get("foo", 4); // output "bar2"   
//kv.get("foo", 5); //output "bar2"   
//
// 
//
// 
// Example 2: 
//
// 
//Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs 
//= [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["
//love",20],["love",25]]
//Output: [null,null,null,"","high","high","low","low"]
// 
// 
// 
//
// 
//
// Note: 
//
// 
// All key/value strings are lowercase. 
// All key/value strings have length in the range [1, 100] 
// The timestamps for all TimeMap.set operations are strictly increasing. 
// 1 <= timestamp <= 10^7 
// TimeMap.set and TimeMap.get functions will be called a total of 120000 times 
//(combined) per test case. 
// 
// Related Topics Hash Table Binary Search 
// 👍 1184 👎 142


#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <utility>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> key2str;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key2str[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!key2str.count(key)) return "";
        auto &v = key2str[key];
        int left = 0, right = v.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(v[mid].first == timestamp) {
                return v[mid].second;
            } else if(v[mid].first > timestamp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left == 0 ? "" : v[left - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<pair<int, string>> mp;
    mp.emplace_back(1, "a");
    mp.emplace_back(2, "b");
    mp.emplace_back(5, "c");
    return 0;
}