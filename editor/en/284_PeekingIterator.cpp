//Design an iterator that supports the peek operation on a list in addition to t
//he hasNext and the next operations. 
//
// Implement the PeekingIterator class: 
//
// 
// PeekingIterator(int[] nums) Initializes the object with the given integer arr
//ay nums. 
// int next() Returns the next element in the array and moves the pointer to the
// next element. 
// bool hasNext() Returns true if there are still elements in the array. 
// int peek() Returns the next element in the array without moving the pointer. 
//
// 
//
// 
// Example 1: 
//
// 
//Input
//["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
//[[[1, 2, 3]], [], [], [], [], []]
//Output
//[null, 1, 2, 2, 3, false]
//
//Explanation
//PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
//peekingIterator.next();    // return 1, the pointer moves to the next element 
//[1,2,3].
//peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
//peekingIterator.next();    // return 2, the pointer moves to the next element 
//[1,2,3]
//peekingIterator.next();    // return 3, the pointer moves to the next element 
//[1,2,3]
//peekingIterator.hasNext(); // return False
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i] <= 1000 
// All the calls to next and peek are valid. 
// At most 1000 calls will be made to next, hasNext, and peek. 
// 
//
// 
//Follow up: How would you extend your design to be generic and work with all ty
//pes, not just integer? Related Topics Design 
// 👍 760 👎 535


#include <iostream>
#include <vector>
using namespace std;
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
//leetcode submit region begin(Prohibit modification and deletion)
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int next_val;
    bool has_next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    has_next = Iterator::hasNext();
	    if(has_next)
	        next_val = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val;
	}

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        has_next = Iterator::hasNext();
        int prev_val = next_val;
        if(has_next)
            next_val = Iterator::next();
        return prev_val;
    }

    bool hasNext() const {
        return has_next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}