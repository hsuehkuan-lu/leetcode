//You need to construct a string consists of parenthesis and integers from a bin
//ary tree with the preorder traversing way. 
//
// The null node needs to be represented by empty parenthesis pair "()". And you
// need to omit all the empty parenthesis pairs that don't affect the one-to-one m
//apping relationship between the string and the original binary tree. 
//
// Example 1: 
// 
//Input: Binary tree: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /    
//  4     
//
//Output: "1(2(4))(3)"
// Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to o
//mit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)".
// 
// 
//
// Example 2: 
// 
//Input: Binary tree: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \  
//      4 
//
//Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we can't omit the f
//irst parenthesis pair to break the one-to-one mapping relationship between the i
//nput and the output.
// 
// Related Topics String Tree 
// 👍 924 👎 1266


#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    string dfs(TreeNode *t) {
        if(!t) return "";
        string s = to_string(t->val);
        if(!t->left && !t->right) return s;
        if(!t->right) return s + "(" + dfs(t->left) + ")";
        return s + "(" + dfs(t->left) + ")" + "(" + dfs(t->right) + ")";
    }

    string dfsSolution(TreeNode *t) {
        return dfs(t);
    }
    string tree2str(TreeNode* t) {
        return dfsSolution(t);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(3);
    solution.tree2str(root);
    return 0;
}