//Given the root of a binary tree, return the inorder traversal of its nodes' va
//lues. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,3]
//Output: [1,3,2]
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1]
//Output: [1]
// 
//
// Example 4: 
//
// 
//Input: root = [1,2]
//Output: [2,1]
// 
//
// Example 5: 
//
// 
//Input: root = [1,null,2]
//Output: [1,2]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// 
//
// Follow up: 
//
// Recursive solution is trivial, could you do it iteratively? 
//
// 
// Related Topics Hash Table Stack Tree 
// 👍 4407 👎 194


#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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
    void recursion(TreeNode *root, vector<int> &ans) {
        if(!root) return;
        recursion(root->left, ans);
        ans.push_back(root->val);
        recursion(root->right, ans);
    }
    vector<int> recursionSolution(TreeNode* root) {
        vector<int> ans;
        recursion(root, ans);
        return ans;
    }
    vector<int> iterationSolution(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
//        return recursionSolution(root);
        return iterationSolution(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    solution.inorderTraversal(root);
    return 0;
}