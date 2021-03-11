//Serialization is the process of converting a data structure or object into a s
//equence of bits so that it can be stored in a file or memory buffer, or transmit
//ted across a network connection link to be reconstructed later in the same or an
//other computer environment. 
//
// Design an algorithm to serialize and deserialize a binary tree. There is no r
//estriction on how your serialization/deserialization algorithm should work. You 
//just need to ensure that a binary tree can be serialized to a string and this st
//ring can be deserialized to the original tree structure. 
//
// Clarification: The input/output format is the same as how LeetCode serializes
// a binary tree. You do not necessarily need to follow this format, so please be 
//creative and come up with different approaches yourself. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,2,3,null,null,4,5]
//Output: [1,2,3,null,null,4,5]
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
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 104]. 
// -1000 <= Node.val <= 1000 
// 
// Related Topics Tree Design 
// 👍 4047 👎 188


#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        string s = "[";
        queue<TreeNode*> Q;
        s += to_string(root->val);
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()) {
            queue<TreeNode*> L;
            bool found = false;
            string ls;
            while(!Q.empty()) {
                root = Q.front();
                Q.pop();
                if(root){
                    ls += "," + to_string(root->val);
                    found = true;
                }
                else{
                    ls += ",null";
                    continue;
                }
                L.push(root->left);
                L.push(root->right);
            }
            if(found) s += ls;
            Q = L;
        }
        s += "]";
        return s;
    }

    vector<string> split(const string &str, const string &delim) {
        vector<string> res;
        if(str.empty()) return res;
        char *strs = new char[str.length()+1];
        strcpy(strs, str.c_str());

        char *d = new char[delim.length()+1];
        strcpy(d, delim.c_str());

        char *p = strtok(strs, d);
        while(p) {
            string s = p;
            res.push_back(s);
            p = strtok(NULL, d);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root, *cur;
        vector<string> ans = split(data.substr(1, data.length()-2), ",");
        if(ans.empty()) return nullptr;
        queue<TreeNode*> Q;
        root = new TreeNode(stoi(ans[0]));
        Q.push(root);
        int i = 1;
        while(i < ans.size()) {
            queue<TreeNode*> L;
            while(!Q.empty()) {
                cur = Q.front();
                // left first
                if(i < ans.size() && ans[i] != "null"){
                    cur->left = new TreeNode(stoi(ans[i]));
                    L.push(cur->left);
                }
                ++i;
                // right then
                if(i < ans.size() && ans[i] != "null"){
                    cur->right = new TreeNode(stoi(ans[i]));
                    L.push(cur->right);
                }
                ++i;
                Q.pop();
            }
            Q = L;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Codec obj;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(100);
    string s = obj.serialize(root);
    TreeNode *cur = obj.deserialize(s);
    cout << obj.serialize(cur) << endl;
    return 0;
}