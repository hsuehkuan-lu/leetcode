//Design and implement an iterator to flatten a 2d vector. It should support the
// following operations: next and hasNext. 
//
// 
//
// Example: 
//
// 
//Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
//
//iterator.next(); // return 1
//iterator.next(); // return 2
//iterator.next(); // return 3
//iterator.hasNext(); // return true
//iterator.hasNext(); // return true
//iterator.next(); // return 4
//iterator.hasNext(); // return false
// 
//
// 
//
// Notes: 
//
// 
// Please remember to RESET your class variables declared in Vector2D, as static
///class variables are persisted across multiple test cases. Please see here for m
//ore details. 
// You may assume that next() call will always be valid, that is, there will be 
//at least a next element in the 2d vector when next() is called. 
// 
//
// 
//
// Follow up: 
//
// As an added challenge, try to code it using only iterators in C++ or iterator
//s in Java. 
// Related Topics Design 
// 👍 427 👎 247


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Vector2D {
    /*
     * The problem is difficult because of the various input formats, including vector of null pointers,
     * null vectors, empty vectors. So make every check before going to next step.
     */
private:
    int row, col;
    vector<vector<int>> *v;
public:
    void findNextValidPosition(int x, int y) {
        ++y;
        while(x < v->size() && y >= (*v)[x].size()) {
            ++x;
            y = 0;
        }
        row = x;
        col = y;
    }

    void checkEmptyMatrix(vector<vector<int>> &v) {
        if(v.empty()) {
            row = col = 1;
            return;
        }
        if(v.size() == 1 && v[0].empty()) {
            row = col = 1;
            return;
        }
        findNextValidPosition(0, -1);
    }

    Vector2D(vector<vector<int>>& v) {
        this->v = &v;
        row = col = 0;
        checkEmptyMatrix(v);
        cout << row << " " << col << endl;
    }
    
    int next() {
        int next_val = (*v)[row][col];
        findNextValidPosition(row, col);
        return next_val;
    }
    
    bool hasNext() {
        return row < v->size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<vector<int>> v = {{1,2}, {3}, {4}};
    Vector2D *obj = new Vector2D(v);
    obj->next();
    obj->next();
    obj->next();
    obj->next();
//    obj->next();
    obj->hasNext();
    return 0;
}