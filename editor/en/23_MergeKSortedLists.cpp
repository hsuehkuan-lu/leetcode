//You are given an array of k linked-lists lists, each linked-list is sorted in 
//ascending order. 
//
// Merge all the linked-lists into one sorted linked-list and return it. 
//
// 
// Example 1: 
//
// 
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
// 
//
// Example 2: 
//
// 
//Input: lists = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: lists = [[]]
//Output: []
// 
//
// 
// Constraints: 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] is sorted in ascending order. 
// The sum of lists[i].length won't exceed 10^4. 
// 
// Related Topics Linked List Divide and Conquer Heap 
// 👍 6725 👎 349


#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *minHeapSolution(vector<ListNode*> &lists) {
        multimap<int, ListNode*> mp;
        // insert head first
        for(auto &l: lists)
            if(l) mp.insert(make_pair(l->val, l));
        ListNode *head, *cur;
        head = cur = nullptr;
        // iterate through all nodes and expand map
        while(!mp.empty()){
            auto it = mp.begin();
            if(!head) {
                head = it->second;
                cur = head;
            } else {
                cur->next = it->second;
                cur = cur->next;
            }
            if(it->second->next)
                mp.insert(make_pair(it->second->next->val, it->second->next));
            mp.erase(it);
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return minHeapSolution(lists);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.minHeapSolution();
    return 0;
}