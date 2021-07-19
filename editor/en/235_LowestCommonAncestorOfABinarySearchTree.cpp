//Given a binary search tree (BST), find the lowest common ancestor (LCA) of two
// given nodes in the BST. 
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
//is defined between two nodes p and q as the lowest node in T that has both p and
// q as descendants (where we allow a node to be a descendant of itself).” 
//
// 
// Example 1: 
//
// 
//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//Output: 6
//Explanation: The LCA of nodes 2 and 8 is 6.
// 
//
// Example 2: 
//
// 
//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//Output: 2
//Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant o
//f itself according to the LCA definition.
// 
//
// Example 3: 
//
// 
//Input: root = [2,1], p = 2, q = 1
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [2, 105]. 
// -109 <= Node.val <= 109 
// All Node.val are unique. 
// p != q 
// p and q will exist in the BST. 
// 
// Related Topics Tree Depth-First Search Binary Search Tree Binary Tree 
// 👍 3588 👎 146
	

#include <iostream>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *bst(TreeNode *root, TreeNode *p, TreeNode *q) {
        int root_val = root->val, p_val = p->val, q_val = q->val;
        if(p_val > root_val && q_val > root_val) {
            return bst(root->right, p, q);
        } else if(p_val < root_val && q_val < root_val) {
            return bst(root->left, p, q);
        } else {
            return root;
        }
    }
    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == p || root == q || !root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        else return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return bst(root, p, q);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(8);
    solution.lowestCommonAncestor(root, root->left, root->right);
    return 0;
}