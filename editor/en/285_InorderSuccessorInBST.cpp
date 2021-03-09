//Given the root of a binary search tree and a node p in it, return the in-order
// successor of that node in the BST. If the given node has no in-order successor 
//in the tree, return null. 
//
// The successor of a node p is the node with the smallest key greater than p.va
//l. 
//
// 
// Example 1: 
//
// 
//Input: root = [2,1,3], p = 1
//Output: 2
//Explanation: 1's in-order successor node is 2. Note that both p and the return
// value is of TreeNode type.
// 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,null,1], p = 6
//Output: null
//Explanation: There is no in-order successor of the current node, so the answer
// is null.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 104]. 
// -105 <= Node.val <= 105 
// All Nodes will have unique values. 
// 
// Related Topics Tree 
// 👍 1454 👎 72


#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
//  Definition for a binary tree node.
//struct TreeNode {
//  int val;
//  TreeNode *left;
//  TreeNode *right;
//  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};


class Solution {
    private:
    TreeNode *ans;
    bool found = false;
public:
    void recursion(TreeNode *root, TreeNode *p) {
        if(!root) return;
        recursion(root->left, p);
        if(found) {
            ans = root;
            found = false;
        }
        if(root->val == p->val)
            found = true;
        recursion(root->right, p);
    }
    TreeNode *bst(TreeNode *root, TreeNode *p) {
        TreeNode *prev = NULL;
        while(root) {
            if(root->val > p->val) {
                prev = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return prev;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return bst(root, p);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}