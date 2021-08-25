//Given an integer n, return a list of all possible full binary trees with n nod
//es. Each node of each tree in the answer must have Node.val == 0. 
//
// Each element of the answer is the root node of one possible tree. You may ret
//urn the final list of trees in any order. 
//
// A full binary tree is a binary tree where each node has exactly 0 or 2 childr
//en. 
//
// 
// Example 1: 
//
// 
//Input: n = 7
//Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,
//0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// 
//
// Example 2: 
//
// 
//Input: n = 3
//Output: [[0,0,0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 
// Related Topics Dynamic Programming Tree Recursion Memoization Binary Tree 
// 👍 1815 👎 153
	

#include <iostream>
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
    TreeNode *copy(TreeNode *root) {
        if(!root) return root;
        TreeNode *new_root = new TreeNode(0);
        new_root->left = copy(root->left);
        new_root->right = copy(root->right);
        return new_root;
    }
    vector<TreeNode*> dfs(vector<vector<TreeNode*>> &trees, int cur) {
        if(!trees[cur-1].empty()) return trees[cur-1];
        vector<TreeNode*> v;
        for(int i=1; i<cur; i+=2) {
            for(auto left: dfs(trees, i)) {
                for(auto right: dfs(trees, cur - i - 1)) {
                    TreeNode *node = new TreeNode(0, copy(left), copy(right));
                    v.push_back(node);
                }
            }
        }
        return trees[cur-1] = v;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if((n & 1) == 0) return {};
        vector<vector<TreeNode*>> trees(n);
        trees[0] = {new TreeNode(0)};
        return dfs(trees, n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}