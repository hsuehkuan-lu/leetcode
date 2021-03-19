//Given a nested list of integers, implement an iterator to flatten it. 
//
// Each element is either an integer, or a list -- whose elements may also be in
//tegers or other lists. 
//
// Example 1: 
//
// 
// 
//Input: [[1,1],2,[1,1]]
//Output: [1,1,2,1,1]
//Explanation: By calling next repeatedly until hasNext returns false, 
//             the order of elements returned by next should be: [1,1,2,1,1]. 
//
// 
// Example 2: 
//
// 
//Input: [1,[4,[6]]]
//Output: [1,4,6]
//Explanation: By calling next repeatedly until hasNext returns false, 
//             the order of elements returned by next should be: [1,4,6].
// 
// 
// 
// Related Topics Stack Design 
// 👍 2065 👎 786


#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> v;
    int idx;
public:
    void recursion(const vector<NestedInteger> &nestedList) {
        for(auto &i: nestedList) {
            if(i.isInteger())
                v.push_back(i.getInteger());
            else
                recursion(i.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        idx = 0;
        recursion(nestedList);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}