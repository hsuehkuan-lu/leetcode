//Given the root of a binary tree, return the postorder traversal of its nodes' 
//values. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,3]
//Output: [3,2,1]
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
//Output: [2,1]
// 
//
// 
// Constraints: 
//
// 
// The number of the nodes in the tree is in the range [0, 100]. 
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
// Related Topics Stack Tree 
// 👍 2450 👎 113


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
        recursion(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> recursionSolution(TreeNode *root) {
        vector<int> ans;
        recursion(root, ans);
        return ans;
    }
    vector<int> twoStackIterationSolution(TreeNode *root) {
        /*
         * The idea of this algorithm is using two stacks to iterate through nodes, and transform
         * original order reversely from first stack to second stack.
         */
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> first, second;
        first.push(root);
        while(!first.empty()) {
            root = first.top();
            second.push(root);
            first.pop();
            if(root->left) first.push(root->left);
            if(root->right) first.push(root->right);
        }
        while(!second.empty()) {
            ans.push_back(second.top()->val);
            second.pop();
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
//        return recursionSolution(root);
        return twoStackIterationSolution(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(4);
    solution.postorderTraversal(root);
    return 0;
}