//Given the root of a binary tree, return the number of uni-value subtrees. 
//
// A uni-value subtree means all nodes of the subtree have the same value. 
//
// 
// Example 1: 
//
// 
//Input: root = [5,1,5,5,5,null,5]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: root = [5,5,5,5,5,null,5]
//Output: 6
// 
//
// 
// Constraints: 
//
// 
// The numbrt of the node in the tree will be in the range [0, 1000]. 
// -1000 <= Node.val <= 1000 
// 
// Related Topics Tree 
// 👍 683 👎 184


#include <iostream>
#include <queue>
#include <unordered_set>
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
    int checkSubtree(TreeNode *root, unordered_set<TreeNode*> &visited) {
        int left, right, total;
        left = right = total = 0;
        if(!root->left || root->left && root->val == root->left->val) left = 1;
        if(!root->right || root->right && root->val == root->right->val) right = 1;
        if(left && right) {
            if(!visited.count(root)) {
                ++total;
                visited.insert(root);
            }
            if(root->left && !visited.count(root->left)) {
                ++total;
                visited.insert(root->left);
            }
            if(root->right && !visited.count(root->right)) {
                ++total;
                visited.insert(root->right);
            }
        }
        return total;
    }
    int bfsSolution(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        unordered_set<TreeNode*> visited;
        vector<int> cnt(1001, 0);
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode *> l;
            while(!q.empty()) {
                root = q.front();
                q.pop();
                int total = checkSubtree(root, visited);
                cnt[root->val] += total;
                if(root->left) l.push(root->left);
                if(root->right) l.push(root->right);
            }
            q = l;
        }
        int total = 0;
        for(auto &i: cnt)
            total = max(i, total);
        return total;
    }
    int total = 0;
    bool dfsSolution(TreeNode *root) {
        if(!root) return true;
        if(!root->left && !root->right) {
            ++total;
            return true;
        }
        bool is_uni = true;
        if(root->left)
            is_uni = dfsSolution(root->left) && root->left->val == root->val;
        if(root->right)
            is_uni = dfsSolution(root->right) && is_uni && root->right->val == root->val;
        if(!is_uni) return false;
        ++total;
        return true;
    }
    bool optimizeDFSSolution(TreeNode *root, const int &target) {
        if(!root) return true;
        if(!optimizeDFSSolution(root->left, root->val) | !optimizeDFSSolution(root->right, root->val))
            return false;
        ++total;
        return root->val == target;
    }
    int countUnivalSubtrees(TreeNode* root) {
        optimizeDFSSolution(root, 0);
        return total;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);
    solution.countUnivalSubtrees(root);
    return 0;
}