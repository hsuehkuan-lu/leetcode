//You need to construct a binary tree from a string consisting of parenthesis an
//d integers. 
//
// The whole input represents a binary tree. It contains an integer followed by 
//zero, one or two pairs of parenthesis. The integer represents the root's value a
//nd a pair of parenthesis contains a child binary tree with the same structure. 
//
// You always start to construct the left child node of the parent first if it e
//xists. 
//
// 
// Example 1: 
//
// 
//Input: s = "4(2(3)(1))(6(5))"
//Output: [4,2,6,3,1,5]
// 
//
// Example 2: 
//
// 
//Input: s = "4(2(3)(1))(6(5)(7))"
//Output: [4,2,6,3,1,5,7]
// 
//
// Example 3: 
//
// 
//Input: s = "-4(2(3)(1))(6(5)(7))"
//Output: [-4,2,6,3,1,5,7]
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 3 * 104 
// s consists of digits, '(', ')', and '-' only. 
// 
// Related Topics String Tree 
// 👍 567 👎 104


#include <iostream>
#include <string>
 struct TreeNode {
          int val;
          TreeNode *left;
          TreeNode *right;
          TreeNode() : val(0), left(nullptr), right(nullptr) {}
          TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
          TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
      };
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    TreeNode *dfsSolution(string &s, int &idx) {
        if(idx >= n || s[idx] == ')') return nullptr;
        TreeNode *root;
        if(s[idx] == '(') ++idx;
        int start = idx;
        // parse number
        for(; idx<n; ++idx) {
            if(s[idx] != '-' && !isdigit(s[idx])) {
                root = new TreeNode(stoi(s.substr(start, idx-start)));
                break;
            }
        }
        // last number
        if(!root && idx >=n) {
            root = new TreeNode(stoi(s.substr(start, idx-start)));
            return root;
        }
        root->left = dfsSolution(s, idx);
        root->right = dfsSolution(s, idx);
        if(s[idx] == ')') ++idx;
        return root;
    }
    TreeNode* str2tree(string s) {
        if(s.empty()) return nullptr;
        n = s.size();
        int idx = 0;
        return dfsSolution(s, idx);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.str2tree("4(2(3)(1))(6(5))");
    return 0;
}