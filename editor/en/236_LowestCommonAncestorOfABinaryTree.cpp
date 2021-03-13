//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes 
//in the tree. 
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
//is defined between two nodes p and q as the lowest node in T that has both p and
// q as descendants (where we allow a node to be a descendant of itself).” 
//
// 
// Example 1: 
//
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//Output: 3
//Explanation: The LCA of nodes 5 and 1 is 3.
// 
//
// Example 2: 
//
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//Output: 5
//Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant o
//f itself according to the LCA definition.
// 
//
// Example 3: 
//
// 
//Input: root = [1,2], p = 1, q = 2
//Output: 1
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
// p and q will exist in the tree. 
// 
// Related Topics Tree 
// 👍 5306 👎 201


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
    bool isParent(TreeNode *parent, TreeNode *child) {
        if(!parent) return false;
        if(parent == child || parent->left == child || parent->right == child) return true;
        return isParent(parent->left, child) || isParent(parent->right, child);
    }
    void dfsSolution(TreeNode *root, TreeNode *p, TreeNode *q, int depth, int &min_depth, TreeNode **ancestor) {
        if(!root) return;
        if(isParent(root->left, p) && isParent(root->left, q)) {
            if(depth > min_depth){
                *ancestor = root->left;
                min_depth = depth;
            }
            dfsSolution(root->left, p, q, depth + 1, min_depth, ancestor);
        }
        if(isParent(root->right, p) && isParent(root->right, q)) {
            if(depth > min_depth){
                *ancestor = root->right;
                min_depth = depth;
            }
            dfsSolution(root->right, p, q, depth + 1, min_depth, ancestor);
        }
    }
    TreeNode *optimizeDFSSolution(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == p || root == q || !root)
            return root;
        TreeNode *left = optimizeDFSSolution(root->left, p, q);
        TreeNode *right = optimizeDFSSolution(root->right, p, q);
        if(left && right) return root;
        else return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        int min_depth = -1;
//        TreeNode *ancestor = root;
//        dfsSolution(root, p, q, 0, min_depth, &ancestor);
//        return ancestor;
        return optimizeDFSSolution(root, p, q);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    solution.lowestCommonAncestor(root, root->left->left, root->right->right);
    return 0;
}