//Given the root of a binary tree, the value of a target node target, and an int
//eger k, return an array of the values of all nodes that have a distance k from t
//he target node. 
//
// You can return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 
//5) have values 7, 4, and 1.
// 
//
// Example 2: 
//
// 
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 500]. 
// 0 <= Node.val <= 500 
// All the values Node.val are unique. 
// target is the value of one of the nodes in the tree. 
// 0 <= k <= 1000 
// 
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 
// 👍 4183 👎 82
	

#include <iostream>
using namespace std;
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
    unordered_map<TreeNode*, TreeNode*> parents;
public:
    TreeNode *addParent(TreeNode *root) {
        if(!root) return root;
        TreeNode *left = addParent(root->left);
        TreeNode *right = addParent(root->right);
        if(left) parents[left] = root;
        if(right) parents[right] = root;
        return root;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        addParent(root);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> start, next;
        start.push(target);
        while(!start.empty() && k >= 0) {
            while(!start.empty()) {
                auto front = start.front();
                start.pop();
                visited.insert(front);
                if(k == 0) {
                    ans.push_back(front->val);
                } else {
                    if(front->left && !visited.count(front->left)) next.push(front->left);
                    if(front->right && !visited.count(front->right)) next.push(front->right);
                    if(parents.count(front) && !visited.count(parents[front])) next.push(parents[front]);
                }
            }
            if(k == 0) return ans;
            swap(start, next);
            --k;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}