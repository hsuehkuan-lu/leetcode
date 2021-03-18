//Given the root of a binary tree, return the preorder traversal of its nodes' v
//alues. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,3]
//Output: [1,2,3]
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
//Output: [1,2]
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
// Follow up: Recursive solution is trivial, could you do it iteratively? 
// Related Topics Stack Tree 
// 👍 2135 👎 86


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
    void preorderRecursion(TreeNode *root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        preorderRecursion(root->left, ans);
        preorderRecursion(root->right, ans);
    }
    vector<int> recursionSolution(TreeNode *root) {
        vector<int> ans;
        preorderRecursion(root, ans);
        return ans;
    }
    vector<int> iterationSolution(TreeNode *root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return ans;
    }
    vector<int> iterationSolutionII(TreeNode *root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                ans.push_back(root->val);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
//        return recursionSolution(root);
        return iterationSolutionII(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
//    root->right = new TreeNode(2);
//    root->right->left = new TreeNode(3);
    solution.preorderTraversal(root);
    return 0;
}